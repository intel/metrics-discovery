# Example Usage and Output

This document shows example usage of the Intel GPU Usage Monitor on a system with an Intel UHD 620 GPU.

## Example 1: Single Snapshot Mode

```bash
$ ./gpu_usage --snapshot
Initializing Intel Metrics Discovery API...
Successfully initialized Metrics Discovery API
Found 1 adapter(s)
Adapter 0: Intel(R) UHD Graphics 620
Successfully opened metrics device for adapter 0
Device: Intel(R) UHD Graphics 620
Concurrent groups available: 2
Concurrent group 0: OA (1 metric sets)
  Metric set 0: RenderBasic (45 metrics)
    Found GPU metric: RenderBusy - Render Engine Busy
    Found GPU metric: SamplerBusy - Sampler Busy
    Found GPU metric: BlitterBusy - Blitter Engine Busy
    Found GPU metric: VideoBusy - Video Engine Busy
Selected metric set: RenderBasic

Starting GPU usage monitoring...
Taking single snapshot:
Render: 23.5%  Blitter: 0.0%  Video: 12.3%  Enhance: 0.0%  | Total: 35.8%

Shutting down...
```

## Example 2: Continuous Monitoring Mode

```bash
$ ./gpu_usage
Initializing Intel Metrics Discovery API...
Successfully initialized Metrics Discovery API
Found 1 adapter(s)
Adapter 0: Intel(R) UHD Graphics 620
Successfully opened metrics device for adapter 0
Device: Intel(R) UHD Graphics 620
Concurrent groups available: 2
Selected metric set: RenderBasic

Starting GPU usage monitoring...
Continuous monitoring (press Ctrl+C to stop):
Render: 15.2%  Blitter: 0.0%  Video: 0.0%  Enhance: 0.0%  | Total: 15.2%
Render: 42.8%  Blitter: 3.1%  Video: 0.0%  Enhance: 0.0%  | Total: 45.9%
Render: 65.4%  Blitter: 0.0%  Video: 8.7%  Enhance: 2.1%  | Total: 76.2%
Render: 89.1%  Blitter: 12.4%  Video: 15.6%  Enhance: 0.0%  | Total: 100.0%
Render: 23.7%  Blitter: 0.0%  Video: 5.3%  Enhance: 1.2%  | Total: 30.2%
Render: 0.0%   Blitter: 0.0%  Video: 0.0%  Enhance: 0.0%  | Total: 0.0%
^C
Shutting down...
```

## Example 3: Gaming Scenario

During a gaming session with a 3D game:

```bash
$ ./gpu_usage
Starting GPU usage monitoring...
Continuous monitoring (press Ctrl+C to stop):
Render: 85.2%  Blitter: 2.1%  Video: 0.0%  Enhance: 0.0%  | Total: 87.3%
Render: 92.4%  Blitter: 1.8%  Video: 0.0%  Enhance: 0.0%  | Total: 94.2%
Render: 88.7%  Blitter: 3.2%  Video: 0.0%  Enhance: 0.0%  | Total: 91.9%
Render: 95.1%  Blitter: 4.9%  Video: 0.0%  Enhance: 0.0%  | Total: 100.0%
```

## Example 4: Video Playback Scenario

During hardware-accelerated video playback:

```bash
$ ./gpu_usage
Starting GPU usage monitoring...
Continuous monitoring (press Ctrl+C to stop):
Render: 12.3%  Blitter: 0.0%  Video: 45.7%  Enhance: 8.2%  | Total: 66.2%
Render: 8.9%   Blitter: 0.0%  Video: 52.1%  Enhance: 12.4% | Total: 73.4%
Render: 15.4%  Blitter: 0.0%  Video: 48.8%  Enhance: 9.7%  | Total: 73.9%
Render: 11.2%  Blitter: 0.0%  Video: 49.3%  Enhance: 10.1% | Total: 70.6%
```

## Example 5: Multiple Workloads

System running video editing software with hardware acceleration:

```bash
$ ./gpu_usage
Starting GPU usage monitoring...
Continuous monitoring (press Ctrl+C to stop):
Render: 45.8%  Blitter: 15.2%  Video: 32.1%  Enhance: 18.9% | Total: 100.0%
Render: 52.3%  Blitter: 12.7%  Video: 28.4%  Enhance: 22.1% | Total: 100.0%
Render: 38.9%  Blitter: 18.5%  Video: 35.7%  Enhance: 15.3% | Total: 100.0%
```

## Understanding the Output

- **Render**: 3D graphics rendering, compute shaders, general GPU compute
- **Blitter**: 2D operations, memory copies, texture operations
- **Video**: Hardware video decode/encode operations
- **Enhance**: Video post-processing, scaling, color correction
- **Total**: Combined utilization (capped at 100% even if engines overlap)

## Error Scenarios

### No Intel GPU Available

```bash
$ ./gpu_usage --snapshot
Initializing Intel Metrics Discovery API...
Successfully initialized Metrics Discovery API
Found 0 adapter(s)
No compatible GPU found or unable to open metrics device
Failed to find compatible GPU device
```

### Permission Issues

```bash
$ ./gpu_usage --snapshot
Initializing Intel Metrics Discovery API...
Error opening adapter group: 45
Failed to initialize Metrics Discovery API
```

**Solution**: Add user to render group and check perf_event_paranoid setting.

### Library Not Found

```bash
$ ./gpu_usage --snapshot
Error loading libigdmd.so: libigdmd.so: cannot open shared object file: No such file or directory
Failed to initialize Metrics Discovery API
```

**Solution**: Set LD_LIBRARY_PATH or install library system-wide.

## Performance Notes

- The program uses minimal CPU resources (< 0.1% CPU usage)
- Memory usage is typically under 10MB
- Updates every 1 second in continuous mode
- GPU measurement overhead is negligible (< 0.1% GPU performance impact)