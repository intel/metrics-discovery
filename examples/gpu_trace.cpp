// gpu_trace.cpp — Intel Arc GPU trace tool
//
// Uses Intel Metrics Discovery API to sample a configurable OA metric set
// via IoStream and reports Vector Engine ALU0/ALU1/XMX(ALU2) activity, stalls,
// L3 (device cache) bandwidth, and VRAM bandwidth. All values are normalized
// to per-second rates.
//
// Build:
//   g++ -std=c++17 -O2 -o gpu_trace gpu_trace.cpp -ldl -I../inc/common/instrumentation/api
//
// Run (requires root or i915/xe perf access):
//   sudo ./bmg_trace [interval_ms]     (default: 1000 ms)

#include "metrics_discovery_api.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <csignal>
#include <dlfcn.h>
#include <unistd.h>
#include <vector>
#include <deque>
#include <chrono>

using namespace MetricsDiscovery;

// ── Globals ──────────────────────────────────────────────────────────────────

static volatile sig_atomic_t g_running = 1;

static void sigHandler(int) { g_running = 0; }

static const char* ccToStr(TCompletionCode cc)
{
    switch (cc) {
    case CC_OK:                      return "OK";
    case CC_READ_PENDING:            return "READ_PENDING";
    case CC_ALREADY_INITIALIZED:     return "ALREADY_INITIALIZED";
    case CC_STILL_INITIALIZED:       return "STILL_INITIALIZED";
    case CC_CONCURRENT_GROUP_LOCKED: return "CONCURRENT_GROUP_LOCKED";
    case CC_WAIT_TIMEOUT:            return "WAIT_TIMEOUT";
    case CC_TRY_AGAIN:               return "TRY_AGAIN";
    case CC_ERROR_INVALID_PARAMETER: return "ERROR_INVALID_PARAMETER";
    case CC_ERROR_NO_MEMORY:         return "ERROR_NO_MEMORY";
    case CC_ERROR_GENERAL:           return "ERROR_GENERAL";
    case CC_ERROR_FILE_NOT_FOUND:    return "ERROR_FILE_NOT_FOUND";
    case CC_ERROR_NOT_SUPPORTED:     return "ERROR_NOT_SUPPORTED";
    case CC_ERROR_ACCESS_DENIED:     return "ERROR_ACCESS_DENIED";
    default:                         return "UNKNOWN";
    }
}

static double typedToDouble(const TTypedValue_1_0& v)
{
    switch (v.ValueType) {
    case VALUE_TYPE_UINT32: return static_cast<double>(v.ValueUInt32);
    case VALUE_TYPE_UINT64: return static_cast<double>(v.ValueUInt64);
    case VALUE_TYPE_FLOAT:  return static_cast<double>(v.ValueFloat);
    case VALUE_TYPE_BOOL:   return v.ValueBool ? 1.0 : 0.0;
    default:                return 0.0;
    }
}

// ── Metric descriptors ───────────────────────────────────────────────────────

// How to aggregate across OA reports within a display interval:
//   PCT  — percentage: time-weighted average (weight by GpuTime per report)
//   EVENT — event count: sum all, then divide by total GpuTime → per second
//   BYTE  — byte count: sum all, then divide by total GpuTime → bytes/sec
//   RATE  — already a rate (B/s): time-weighted average
//   CTX   — context info (GpuTime, freq): handled specially
enum MetricKind { PCT, EVENT, BYTE, RATE, CTX };

struct MetricSlot {
    const char* symbol;
    const char* label;
    MetricKind  kind;
    int         index;  // resolved after API filtering (-1 = not found)
};

static MetricSlot g_metrics[] = {
    // ── Context ──
    { "GpuTime",                                "GPU Time",             CTX,   -1 },
    { "AvgGpuCoreFrequencyMHz",                 "GPU Freq",             CTX,   -1 },
    { "GPU_BUSY",                               "GPU Busy",             PCT,   -1 },
    { "GPGPU_DISPATCH",                         "Dispatch",             PCT,   -1 },

    // ── Vector Engine activity ──
    { "XVE_ACTIVE",                             "XVE Active",           PCT,   -1 },
    { "XVE_INST_EXECUTED_ALU0_ALL_UTILIZATION",  "ALU0 Utilization",    PCT,   -1 },
    { "XVE_INST_EXECUTED_ALU1_ALL_UTILIZATION",  "ALU1 Utilization",    PCT,   -1 },
    { "XVE_INST_EXECUTED_ALU2_ALL_UTILIZATION",  "ALU2/XMX Utilization",PCT,   -1 },
    { "XVE_INST_EXECUTED_ALU0_ALL",              "ALU0 Exec Slots",     EVENT, -1 },
    { "XVE_INST_EXECUTED_ALU1_ALL",              "ALU1 Exec Slots",     EVENT, -1 },
    { "XVE_INST_EXECUTED_ALU2_ALL",              "ALU2/XMX Exec Slots", EVENT, -1 },
    { "XVE_PIPE_ALU0_AND_ALU1_ACTIVE",           "ALU0+ALU1 Co-Active", PCT,   -1 },
    { "XVE_PIPE_ALU0_AND_ALU2_ACTIVE",           "ALU0+ALU2 Co-Active", PCT,   -1 },
    { "XVE_MULTIPLE_PIPE_ACTIVE",                "Multi-Pipe Active",   PCT,   -1 },
    { "XVE_THREADS_OCCUPANCY_ALL",               "Thread Occupancy",    PCT,   -1 },
    { "XVE_LOAD_STORE_CACHE_READ_MESSAGE_COUNT", "Load Read Message",   EVENT, -1 },
    { "XVE_SLM_READ_MESSAGE_COUNT",              "SLM Read Message",    EVENT, -1 },
    { "XVE_INST_EXECUTED_XMX_FP16",              "XMX FP16 instr",      EVENT, -1 },
    { "XVE_INST_EXECUTED_XMX_BF16",              "XMX BF16 instr",      EVENT, -1 },
    { "XVE_INST_EXECUTED_FP16",                  "non-XMX FP16 instr",  EVENT, -1 },
    { "XVE_INST_EXECUTED_FP32",                  "non-XMX FP32 instr",  EVENT, -1 },
    { "XVE_INST_EXECUTED_FP64",                  "non-XMX FP64 instr",  EVENT, -1 },
    { "XVE_INST_EXECUTED_FP64_2ND",              "non-XMX FP64_2 instr",EVENT, -1 },
    { "XVE_INST_EXECUTED_INT16",                 "non-XMX INT16 instr", EVENT, -1 },
    { "XVE_INST_EXECUTED_INT32",                 "non-XMX INT32 instr", EVENT, -1 },
    { "XVE_INST_EXECUTED_INT64",                 "non-XMX INT64 instr", EVENT, -1 },
    { "XVE_INST_EXECUTED_MATH",                  "non-XMX Math instr",  EVENT, -1 },
    { "XVE_INST_EXECUTED_BITCONV",               "bitconv instr",       EVENT, -1 },
    { "XVE_INST_EXECUTED_BARRIER",               "Barrier instr",       EVENT, -1 },
    { "XVE_INST_EXECUTED_CONTROL_ALL",           "control instr",       EVENT, -1 },

    // ── Stalls ──
    { "XVE_STALL",                               "XVE Stall",           PCT,   -1 },
    { "XVE_SHARED_FUNCTION_ACCESS_HOLD",         "SF Access Hold",      PCT,   -1 },

    // ── L3 / Device Cache ──
    { "L3_READ",                                 "L3 Reads",            EVENT, -1 },
    { "L3_WRITE",                                "L3 Writes",           EVENT, -1 },
    { "L3_HIT",                                  "L3 Hits",             EVENT, -1 },
    { "L3_MISS",                                 "L3 Misses",           EVENT, -1 },
    { "L3_STALL",                                "L3 Stall",            PCT,   -1 },
    { "LOAD_STORE_CACHE_BYTE_READ",              "Load Store Cache Read", BYTE, -1 },
    { "SLM_BYTE_READ",                           "SLM Read",            BYTE,  -1 },

    // ── VRAM bandwidth ──
    { "GPU_MEMORY_BYTE_READ",                    "VRAM Read BW",        BYTE,  -1 },
    { "GPU_MEMORY_BYTE_WRITE",                   "VRAM Write BW",       BYTE,  -1 },
    { "GPU_MEMORY_32B_TRANSACTION_READ",         "VRAM 32B Reads",      BYTE,  -1 },
    { "GPU_MEMORY_64B_TRANSACTION_READ",         "VRAM 64B Reads",      BYTE,  -1 },
    { "GPU_MEMORY_REQUEST_QUEUE_FULL",           "VRAM Queue Full",     PCT,   -1 },
    { "GPU_MEMORY_ACTIVE",                       "VRAM Active",         PCT,   -1 },
};
static constexpr int NUM_METRICS = sizeof(g_metrics) / sizeof(g_metrics[0]);

// ── Formatting helpers ───────────────────────────────────────────────────────

static void fmtRate(double bps, char* buf, size_t sz)
{
    if (bps >= 1e9)      snprintf(buf, sz, "%7.2f GB/s", bps / 1e9);
    else if (bps >= 1e6) snprintf(buf, sz, "%7.2f MB/s", bps / 1e6);
    else if (bps >= 1e3) snprintf(buf, sz, "%7.2f KB/s", bps / 1e3);
    else                 snprintf(buf, sz, "%7.0f  B/s", bps);
}

static void fmtCount(double cps, char* buf, size_t sz)
{
    if (cps >= 1e9)      snprintf(buf, sz, "%7.2f G/s", cps / 1e9);
    else if (cps >= 1e6) snprintf(buf, sz, "%7.2f M/s", cps / 1e6);
    else if (cps >= 1e3) snprintf(buf, sz, "%7.2f K/s", cps / 1e3);
    else                 snprintf(buf, sz, "%7.0f  /s", cps);
}

// ── Main ─────────────────────────────────────────────────────────────────────

int main(int argc, char* argv[])
{
    fprintf(stderr, "Args: intervalMs(1000) profile(ComputeBasic)\n\n");
    uint32_t intervalMs = 1000;
    if (argc > 1) intervalMs = static_cast<uint32_t>(atoi(argv[1]));
    if (intervalMs < 50) intervalMs = 50;

    const char* profile = "ComputeBasic";
    if (argc > 2) profile = argv[2];
    if (strcmp(profile, "ComputeBasic") && strcmp(profile, "MemoryProfile") && strcmp(profile, "VectorEngineProfile")) {
        fprintf(stderr, "Profile was not ComputeBasic, MemoryProfile, or VectorEngineProfile\n");
        return -1;
    }

    signal(SIGINT,  sigHandler);
    signal(SIGTERM, sigHandler);

    // ── Load library ─────────────────────────────────────────────────────────
    void* lib = dlopen("libigdmd.so", RTLD_LAZY);
    if (!lib) lib = dlopen("libigdmd.so.1", RTLD_LAZY);
    if (!lib) {
        lib = dlopen("../dump/linux64/release/metrics_discovery/libigdmd.so", RTLD_LAZY);
    }
    if (!lib) {
        fprintf(stderr, "ERROR: Cannot load libigdmd.so: %s\n", dlerror());
        fprintf(stderr, "Make sure the library is installed or set LD_LIBRARY_PATH.\n");
        return 1;
    }

    auto fnOpen = reinterpret_cast<OpenAdapterGroup_fn>(dlsym(lib, "OpenAdapterGroup"));
    if (!fnOpen) {
        fprintf(stderr, "ERROR: OpenAdapterGroup symbol not found.\n");
        dlclose(lib);
        return 1;
    }

    // ── Open adapter group ───────────────────────────────────────────────────
    IAdapterGroupLatest* adapterGroup = nullptr;
    TCompletionCode cc = fnOpen(&adapterGroup);
    if (cc != CC_OK || !adapterGroup) {
        fprintf(stderr, "ERROR: OpenAdapterGroup failed: %s\n", ccToStr(cc));
        dlclose(lib);
        return 1;
    }

    const auto* agParams = adapterGroup->GetParams();
    printf("MDAPI v%u.%u.%u — %u adapter(s) found\n",
           agParams->Version.MajorNumber,
           agParams->Version.MinorNumber,
           agParams->Version.BuildNumber,
           agParams->AdapterCount);

    if (agParams->AdapterCount == 0) {
        fprintf(stderr, "ERROR: No GPU adapters found.\n");
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    // ── Pick the first adapter and open metrics device ───────────────────────
    IAdapterLatest* adapter = adapterGroup->GetAdapter(0);
    if (!adapter) {
        fprintf(stderr, "ERROR: GetAdapter(0) returned null.\n");
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    const auto* adapterParams = adapter->GetParams();
    printf("Adapter: %s  (DeviceId=0x%04X, Type=%s)\n",
           adapterParams->ShortName ? adapterParams->ShortName : "unknown",
           adapterParams->DeviceId,
           adapterParams->Type == ADAPTER_TYPE_DISCRETE ? "discrete" : "integrated");

    IMetricsDeviceLatest* device = nullptr;
    cc = adapter->OpenMetricsDevice(&device);
    if (cc != CC_OK || !device) {
        fprintf(stderr, "ERROR: OpenMetricsDevice failed: %s\n", ccToStr(cc));
        fprintf(stderr, "Hint: run as root or grant i915/xe perf access.\n");
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    const auto* devParams = device->GetParams();
    printf("Device: %s — %u concurrent group(s)\n",
           devParams->DeviceName ? devParams->DeviceName : "unknown",
           devParams->ConcurrentGroupsCount);

    // ── Find the "OA" concurrent group ───────────────────────────────────────
    IConcurrentGroupLatest* oaGroup = nullptr;
    for (uint32_t i = 0; i < devParams->ConcurrentGroupsCount; i++) {
        auto* cg = device->GetConcurrentGroup(i);
        if (!cg) continue;
        auto* cgp = cg->GetParams();
        if (cgp && cgp->SymbolName && strcmp(cgp->SymbolName, "OA") == 0) {
            oaGroup = cg;
            break;
        }
    }
    if (!oaGroup) {
        fprintf(stderr, "ERROR: OA concurrent group not found.\n");
        adapter->CloseMetricsDevice(device);
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    // ── Find the "ComputeBasic" metric set ───────────────────────────────────
    auto* oaParams = oaGroup->GetParams();
    IMetricSetLatest* metricSet = nullptr;
    for (uint32_t i = 0; i < oaParams->MetricSetsCount; i++) {
        auto* ms = oaGroup->GetMetricSet(i);
        if (!ms) continue;
        auto* msp = ms->GetParams();
        if (msp && msp->SymbolName && strcmp(msp->SymbolName, profile) == 0) {
            metricSet = ms;
            break;
        }
    }
    if (!metricSet) {
        fprintf(stderr, "ERROR: ComputeBasic metric set not found.\n");
        fprintf(stderr, "Available sets in OA group:\n");
        for (uint32_t i = 0; i < oaParams->MetricSetsCount; i++) {
            auto* ms = oaGroup->GetMetricSet(i);
            if (ms && ms->GetParams())
                fprintf(stderr, "  [%u] %s\n", i, ms->GetParams()->SymbolName);
        }
        adapter->CloseMetricsDevice(device);
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    auto* msParams = metricSet->GetParams();
    printf("Metric set: %s (%s) — %u metrics, %u info, report=%u bytes\n",
           msParams->SymbolName, msParams->ShortName,
           msParams->MetricsCount, msParams->InformationCount,
           msParams->RawReportSize);

    // ── Configure API filtering ─────────────────────────────────────────────
    // Must happen before resolving indices — filtering renumbers metrics.
    cc = metricSet->SetApiFiltering(API_TYPE_IOSTREAM);
    if (cc != CC_OK) {
        fprintf(stderr, "WARNING: SetApiFiltering: %s\n", ccToStr(cc));
    }
    msParams = metricSet->GetParams();

    // ── Resolve wanted metric indices ────────────────────────────────────────
    int resolved = 0;
    for (uint32_t m = 0; m < msParams->MetricsCount; m++) {
        auto* metric = metricSet->GetMetric(m);
        if (!metric) continue;
        auto* mp = metric->GetParams();
        if (!mp || !mp->SymbolName) continue;
        for (int w = 0; w < NUM_METRICS; w++) {
            if (g_metrics[w].index < 0 &&
                strcmp(g_metrics[w].symbol, mp->SymbolName) == 0) {
                g_metrics[w].index = static_cast<int>(m);
                resolved++;
                break;
            }
        }
    }
    printf("Resolved %d/%d metrics (post IOSTREAM filter: %u metrics, %u info).\n",
           resolved, NUM_METRICS, msParams->MetricsCount, msParams->InformationCount);
    if (resolved == 0) {
        fprintf(stderr, "ERROR: No matching metrics found.\n");
        adapter->CloseMetricsDevice(device);
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    // Find GpuTime index — needed for per-second normalization
    int gpuTimeIdx = -1;
    for (int w = 0; w < NUM_METRICS; w++) {
        if (strcmp(g_metrics[w].symbol, "GpuTime") == 0) {
            gpuTimeIdx = g_metrics[w].index;
            break;
        }
    }
    if (gpuTimeIdx < 0) {
        fprintf(stderr, "ERROR: GpuTime metric not found — cannot normalize.\n");
        adapter->CloseMetricsDevice(device);
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    // ── Open IoStream ──────────────────────────────────────────────────────
    cc = oaGroup->SetIoStreamSamplingType(SAMPLING_TYPE_OA_TIMER);
    if (cc != CC_OK) {
        fprintf(stderr, "WARNING: SetIoStreamSamplingType: %s\n", ccToStr(cc));
    }

    // Short OA period + small buffer so the kernel signals POLLIN quickly.
    uint32_t timerPeriodNs = 1000000;       // 1 ms HW sampling period
    uint32_t oaBufSize     = 128 * 1024;    // 128 KB
    cc = oaGroup->OpenIoStream(metricSet, 0, &timerPeriodNs, &oaBufSize);
    if (cc != CC_OK) {
        fprintf(stderr, "ERROR: OpenIoStream failed: %s\n", ccToStr(cc));
        if (cc == CC_CONCURRENT_GROUP_LOCKED)
            fprintf(stderr, "Hint: another process may hold the OA stream.\n");
        else
            fprintf(stderr, "Hint: run as root or grant CAP_PERFMON.\n");
        adapter->CloseMetricsDevice(device);
        adapterGroup->Close();
        dlclose(lib);
        return 1;
    }

    printf("IoStream open. OA timer: %u ns (~%.2f ms), OA buffer: %u bytes\n",
           timerPeriodNs, timerPeriodNs / 1e6, oaBufSize);

    // ── Buffer setup ─────────────────────────────────────────────────────────
    const uint32_t rawReportSize   = msParams->RawReportSize;
    const uint32_t metricsCount    = msParams->MetricsCount;
    const uint32_t infoCount       = msParams->InformationCount;
    const uint32_t valuesPerReport = metricsCount + infoCount;
    const uint32_t reportsInOaBuf  = oaBufSize / rawReportSize;
    const uint32_t maxReports      = reportsInOaBuf + 64;

    std::vector<char>            rawBuf(maxReports * rawReportSize);
    std::vector<TTypedValue_1_0> outBuf(maxReports * valuesPerReport);

    // Accumulators for the display interval
    std::vector<double> accumSum(NUM_METRICS, 0.0);   // sum of values
    std::vector<double> accumWt(NUM_METRICS, 0.0);    // sum of GpuTime weights (for PCT/RATE)
    std::vector<double> peakVal(NUM_METRICS, 0.0);    // peak value per report in interval
    double totalGpuTimeNs = 0.0;
    uint32_t totalReports = 0;

    // Peak sliding window tracking (10ms and 100ms)
    struct WindowReport {
        double gpuTimeNs;
        double contrib[NUM_METRICS]; // weighted val for PCT/RATE/CTX, raw count for EVENT/BYTE
    };
    // 10ms window
    std::deque<WindowReport> win10Deque;
    std::vector<double> win10Sum(NUM_METRICS, 0.0);
    double win10GpuTimeNs = 0.0;
    std::vector<double> peak10msAvg(NUM_METRICS, 0.0);
    // 100ms window
    std::deque<WindowReport> win100Deque;
    std::vector<double> win100Sum(NUM_METRICS, 0.0);
    double win100GpuTimeNs = 0.0;
    std::vector<double> peak100msAvg(NUM_METRICS, 0.0);

    // ── Sampling loop ────────────────────────────────────────────────────────
    printf("\nDisplaying every %u ms. Press Ctrl+C to stop.\n", intervalMs);
    printf("================================================================================\n");

    using Clock = std::chrono::steady_clock;
    auto lastDisplay = Clock::now();
    uint64_t sampleNum = 0;

    while (g_running) {
        // How much time left until next display?
        auto now = Clock::now();
        auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(
            now - lastDisplay).count();
        int waitMs = static_cast<int>(intervalMs) - static_cast<int>(elapsedMs);
        if (waitMs < 10) waitMs = 10;

        cc = oaGroup->WaitForReports(static_cast<uint32_t>(waitMs));
        if (!g_running) break;

        // Drain all available reports (may need multiple reads)
        while (g_running) {
            uint32_t reportsCount = maxReports;
            cc = oaGroup->ReadIoStream(&reportsCount, rawBuf.data(),
                                       IO_READ_FLAG_DROP_OLD_REPORTS);
            if (reportsCount == 0) break;

            // Calculate deltas: N raw reports → N-1 calculated results
            uint32_t outCount = 0;
            uint32_t calcOutBytes = maxReports * valuesPerReport *
                                    static_cast<uint32_t>(sizeof(TTypedValue_1_0));
            metricSet->CalculateMetrics(
                reinterpret_cast<const uint8_t*>(rawBuf.data()),
                reportsCount * rawReportSize,
                outBuf.data(),
                calcOutBytes,
                &outCount,
                nullptr, 0);

            // Accumulate into interval totals
            for (uint32_t r = 0; r < outCount; r++) {
                const TTypedValue_1_0* rv = &outBuf[r * valuesPerReport];
                double gpuTimeNs = typedToDouble(rv[gpuTimeIdx]);
                totalGpuTimeNs += gpuTimeNs;
                totalReports++;

                for (int w = 0; w < NUM_METRICS; w++) {
                    if (g_metrics[w].index < 0) continue;
                    double val = typedToDouble(rv[g_metrics[w].index]);
                    switch (g_metrics[w].kind) {
                    case PCT:
                    case RATE:
                    case CTX:
                        // Time-weighted: accumulate val*weight, divide by total weight later
                        accumSum[w] += val * gpuTimeNs;
                        accumWt[w]  += gpuTimeNs;
                        // Peak: max instantaneous value across reports
                        if (val > peakVal[w]) peakVal[w] = val;
                        break;
                    case EVENT:
                    case BYTE:
                        // Sum raw counts; we'll divide by total time for /s
                        accumSum[w] += val;
                        // Peak: max per-second rate from a single report
                        if (gpuTimeNs > 0.0) {
                            double ratePerSec = val / (gpuTimeNs / 1e9);
                            if (ratePerSec > peakVal[w]) peakVal[w] = ratePerSec;
                        }
                        break;
                    }
                }

                // ── Update peak sliding windows (10ms, 100ms) ──
                WindowReport wr;
                wr.gpuTimeNs = gpuTimeNs;
                for (int w = 0; w < NUM_METRICS; w++) {
                    if (g_metrics[w].index < 0) { wr.contrib[w] = 0.0; continue; }
                    double val = typedToDouble(rv[g_metrics[w].index]);
                    switch (g_metrics[w].kind) {
                    case PCT: case RATE: case CTX:
                        wr.contrib[w] = val * gpuTimeNs;
                        break;
                    case EVENT: case BYTE:
                        wr.contrib[w] = val;
                        break;
                    }
                }

                auto updateWindow = [&](std::deque<WindowReport>& dq,
                                        std::vector<double>& sum, double& winGpuNs,
                                        std::vector<double>& peakAvg,
                                        double windowNs, double minNs) {
                    winGpuNs += wr.gpuTimeNs;
                    for (int w = 0; w < NUM_METRICS; w++)
                        sum[w] += wr.contrib[w];
                    dq.push_back(wr);
                    while (dq.size() > 1 &&
                           winGpuNs - dq.front().gpuTimeNs >= windowNs) {
                        winGpuNs -= dq.front().gpuTimeNs;
                        for (int w = 0; w < NUM_METRICS; w++)
                            sum[w] -= dq.front().contrib[w];
                        dq.pop_front();
                    }
                    if (winGpuNs >= minNs) {
                        double timeSec = winGpuNs / 1e9;
                        for (int w = 0; w < NUM_METRICS; w++) {
                            if (g_metrics[w].index < 0) continue;
                            double avg = 0.0;
                            switch (g_metrics[w].kind) {
                            case PCT: case RATE: case CTX:
                                avg = sum[w] / winGpuNs;
                                break;
                            case EVENT: case BYTE:
                                avg = sum[w] / timeSec;
                                break;
                            }
                            if (avg > peakAvg[w]) peakAvg[w] = avg;
                        }
                    }
                };
                updateWindow(win10Deque, win10Sum, win10GpuTimeNs,
                             peak10msAvg, 10e6, 5e6);
                updateWindow(win100Deque, win100Sum, win100GpuTimeNs,
                             peak100msAvg, 100e6, 50e6);
            }

            if (cc != CC_READ_PENDING) break; // no more data waiting
        }

        // Check if it's time to display
        now = Clock::now();
        elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(
            now - lastDisplay).count();
        if (elapsedMs < intervalMs || totalReports == 0) continue;

        // ── Compute final values ─────────────────────────────────────────────
        std::vector<double> result(NUM_METRICS, 0.0);
        std::vector<double> peak(NUM_METRICS, 0.0);
        double totalGpuTimeSec = totalGpuTimeNs / 1e9;
        if (totalGpuTimeSec <= 0.0) totalGpuTimeSec = 1e-9; // avoid div/0

        for (int w = 0; w < NUM_METRICS; w++) {
            if (g_metrics[w].index < 0) continue;
            peak[w] = peakVal[w];  // already tracked during accumulation
            switch (g_metrics[w].kind) {
            case PCT:
            case RATE:
            case CTX:
                result[w] = (accumWt[w] > 0.0) ? accumSum[w] / accumWt[w] : 0.0;
                break;
            case EVENT:
            case BYTE:
                result[w] = accumSum[w] / totalGpuTimeSec;
                break;
            }
        }

        // ── Print ────────────────────────────────────────────────────────────
        sampleNum++;
        auto wallTime = std::chrono::system_clock::now();
        auto tt = std::chrono::system_clock::to_time_t(wallTime);
        struct tm tm_buf;
        localtime_r(&tt, &tm_buf);
        char timeStr[64];
        strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &tm_buf);

        printf("\n── Sample #%lu  [%s]  %u reports over %.1f ms GPU time ──\n",
               (unsigned long)sampleNum, timeStr,
               totalReports, totalGpuTimeNs / 1e6);

        // Context line
        double gpuBusy = 0, gpuFreq = 0, dispatching = 0;
        double gpuBusyPk = 0, dispatchPk = 0, gpuFreqPk = 0;
        double gpuBusyPk10 = 0, dispatchPk10 = 0, gpuFreqPk10 = 0;
        double gpuBusyPk100 = 0, dispatchPk100 = 0, gpuFreqPk100 = 0;
        for (int w = 0; w < NUM_METRICS; w++) {
            if (g_metrics[w].index < 0) continue;
            if (strcmp(g_metrics[w].symbol, "GPU_BUSY") == 0)                { gpuBusy = result[w]; gpuBusyPk = peak[w]; gpuBusyPk10 = peak10msAvg[w]; gpuBusyPk100 = peak100msAvg[w]; }
            if (strcmp(g_metrics[w].symbol, "GPGPU_DISPATCH") == 0)          { dispatching = result[w]; dispatchPk = peak[w]; dispatchPk10 = peak10msAvg[w]; dispatchPk100 = peak100msAvg[w]; }
            if (strcmp(g_metrics[w].symbol, "AvgGpuCoreFrequencyMHz") == 0)  { gpuFreq = result[w]; gpuFreqPk = peak[w]; gpuFreqPk10 = peak10msAvg[w]; gpuFreqPk100 = peak100msAvg[w]; }
        }
        printf("  GPU: Busy=%.1f%% (100ms %.1f%%, 10ms %.1f%%, peak %.1f%%)  Dispatch=%.1f%% (100ms %.1f%%, 10ms %.1f%%, peak %.1f%%)\n",
               gpuBusy, gpuBusyPk100, gpuBusyPk10, gpuBusyPk,
               dispatching, dispatchPk100, dispatchPk10, dispatchPk);
        printf("        Freq=%.0f MHz (100ms %.0f, 10ms %.0f, peak %.0f)\n",
               gpuFreq, gpuFreqPk100, gpuFreqPk10, gpuFreqPk);

        // Vector Engine
        printf("  Vector Engine:             %12s    %12s    %12s    %12s\n", "avg", "pk 100ms", "pk 10ms", "peak");
        for (int w = 0; w < NUM_METRICS; w++) {
            if (g_metrics[w].index < 0) continue;
            if (strncmp(g_metrics[w].symbol, "XVE_", 4) != 0) continue;
            char buf[64], pbuf[64], p10buf[64], p100buf[64];
            if (g_metrics[w].kind == PCT) {
                snprintf(buf, sizeof(buf), "%7.2f %%", result[w]);
                snprintf(p100buf, sizeof(p100buf), "%7.2f %%", peak100msAvg[w]);
                snprintf(p10buf, sizeof(p10buf), "%7.2f %%", peak10msAvg[w]);
                snprintf(pbuf, sizeof(pbuf), "%7.2f %%", peak[w]);
            } else {
                fmtCount(result[w], buf, sizeof(buf));
                fmtCount(peak100msAvg[w], p100buf, sizeof(p100buf));
                fmtCount(peak10msAvg[w], p10buf, sizeof(p10buf));
                fmtCount(peak[w], pbuf, sizeof(pbuf));
            }
            printf("    %-26s %12s    %12s    %12s    %12s\n", g_metrics[w].label, buf, p100buf, p10buf, pbuf);
        }

        // L3 / Device Cache
        printf("  L3 (Device Cache):         %12s    %12s    %12s    %12s\n", "avg", "pk 100ms", "pk 10ms", "peak");
        for (int w = 0; w < NUM_METRICS; w++) {
            if (g_metrics[w].index < 0) continue;
            if (strncmp(g_metrics[w].symbol, "L3_", 3) && strncmp(g_metrics[w].symbol, "LOAD_", 5) && strncmp(g_metrics[w].symbol, "SLM_", 4)) continue;
            char buf[64], pbuf[64], p10buf[64], p100buf[64];
            if (g_metrics[w].kind == PCT) {
                snprintf(buf, sizeof(buf), "%7.2f %%", result[w]);
                snprintf(p100buf, sizeof(p100buf), "%7.2f %%", peak100msAvg[w]);
                snprintf(p10buf, sizeof(p10buf), "%7.2f %%", peak10msAvg[w]);
                snprintf(pbuf, sizeof(pbuf), "%7.2f %%", peak[w]);
            } else {
                fmtCount(result[w], buf, sizeof(buf));
                fmtCount(peak100msAvg[w], p100buf, sizeof(p100buf));
                fmtCount(peak10msAvg[w], p10buf, sizeof(p10buf));
                fmtCount(peak[w], pbuf, sizeof(pbuf));
            }
            printf("    %-26s %12s    %12s    %12s    %12s\n", g_metrics[w].label, buf, p100buf, p10buf, pbuf);
        }

        // VRAM
        printf("  VRAM:                      %12s    %12s    %12s    %12s\n", "avg", "pk 100ms", "pk 10ms", "peak");
        for (int w = 0; w < NUM_METRICS; w++) {
            if (g_metrics[w].index < 0) continue;
            if (strncmp(g_metrics[w].symbol, "GPU_MEMORY_", 11) != 0) continue;
            char buf[64], pbuf[64], p10buf[64], p100buf[64];
            if (g_metrics[w].kind == BYTE || g_metrics[w].kind == RATE) {
                fmtRate(result[w], buf, sizeof(buf));
                fmtRate(peak100msAvg[w], p100buf, sizeof(p100buf));
                fmtRate(peak10msAvg[w], p10buf, sizeof(p10buf));
                fmtRate(peak[w], pbuf, sizeof(pbuf));
            } else {
                snprintf(buf, sizeof(buf), "%7.2f %%", result[w]);
                snprintf(p100buf, sizeof(p100buf), "%7.2f %%", peak100msAvg[w]);
                snprintf(p10buf, sizeof(p10buf), "%7.2f %%", peak10msAvg[w]);
                snprintf(pbuf, sizeof(pbuf), "%7.2f %%", peak[w]);
            }
            printf("    %-26s %12s    %12s    %12s    %12s\n", g_metrics[w].label, buf, p100buf, p10buf, pbuf);
        }

        fflush(stdout);

        // Reset accumulators
        std::fill(accumSum.begin(), accumSum.end(), 0.0);
        std::fill(accumWt.begin(), accumWt.end(), 0.0);
        std::fill(peakVal.begin(), peakVal.end(), 0.0);
        std::fill(peak10msAvg.begin(), peak10msAvg.end(), 0.0);
        std::fill(win10Sum.begin(), win10Sum.end(), 0.0);
        win10Deque.clear();
        win10GpuTimeNs = 0.0;
        std::fill(peak100msAvg.begin(), peak100msAvg.end(), 0.0);
        std::fill(win100Sum.begin(), win100Sum.end(), 0.0);
        win100Deque.clear();
        win100GpuTimeNs = 0.0;
        totalGpuTimeNs = 0.0;
        totalReports = 0;
        lastDisplay = now;
    }

    // ── Cleanup ──────────────────────────────────────────────────────────────
    printf("\nShutting down...\n");
    oaGroup->CloseIoStream();
    adapter->CloseMetricsDevice(device);
    adapterGroup->Close();
    dlclose(lib);
    printf("Done.\n");
    return 0;
}
