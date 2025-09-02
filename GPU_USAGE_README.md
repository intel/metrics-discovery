# Intel GPU Usage Monitor

A C program that uses the Intel Metrics Discovery library to measure GPU usage on Intel UHD 620 and other compatible Intel integrated GPUs.

## Features

- **Single snapshot mode**: Take a one-time measurement of GPU usage
- **Continuous monitoring mode**: Monitor GPU usage in real-time with 1-second updates
- **Engine-specific utilization**: Reports separate utilization for Render, Blitter, Video, and Enhance engines
- **Normalized output**: Total utilization is capped at 100% even if individual engines overlap
- **Clean output format**: `Render: 23.5%  Blitter: 0.0%  Video: 12.3%  Enhance: 0.0%  | Total: 35.8%`

## Building the Intel Metrics Discovery Library

### Prerequisites

Make sure you have the required dependencies installed:

```bash
# Ubuntu/Debian
sudo apt update
sudo apt install libdrm-dev build-essential cmake git

# Red Hat/CentOS/Fedora
sudo dnf install libdrm-devel gcc gcc-c++ cmake git
# or for older versions:
sudo yum install libdrm-devel gcc gcc-c++ cmake git
```

### Clone and Build the Library

1. **Clone the repository** (if you haven't already):
   ```bash
   git clone https://github.com/intel/metrics-discovery.git
   cd metrics-discovery
   ```

2. **Configure the build**:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. **Build the library**:
   ```bash
   make -j$(nproc)
   ```

4. **The built library will be located at**:
   ```
   dump/linux64/release/metrics_discovery/libigdmd.so
   ```

5. **Install the library** (optional, requires root):
   ```bash
   sudo make install
   ```

## Building the GPU Usage Monitor

### Method 1: Using the provided Makefile

From the root directory of the metrics-discovery repository:

```bash
# Build the program
make -f Makefile.gpu_usage

# The executable will be created as 'gpu_usage'
```

### Method 2: Manual compilation

```bash
# Compile with explicit paths
g++ -Wall -Wextra -std=c++17 -O2 \
    -I./inc \
    -L./dump/linux64/release/metrics_discovery \
    -o gpu_usage gpu_usage.c \
    -ligdmd -ldl
```

### Method 3: If library is installed system-wide

If you installed the library with `sudo make install`:

```bash
g++ -Wall -Wextra -std=c++17 -O2 \
    -I./inc \
    -o gpu_usage gpu_usage.c \
    -ligdmd -ldl
```

## Setting Up Environment Variables

### Library Path Setup

If you built the library but didn't install it system-wide, you need to tell the system where to find it:

```bash
# Add the library path to LD_LIBRARY_PATH
export LD_LIBRARY_PATH="$PWD/dump/linux64/release/metrics_discovery:$LD_LIBRARY_PATH"

# Or run with LD_LIBRARY_PATH
LD_LIBRARY_PATH="./dump/linux64/release/metrics_discovery" ./gpu_usage
```

### Permissions Setup

The Intel Metrics Discovery library may require access to GPU performance counters. On some systems, you may need to:

1. **Add your user to the render group**:
   ```bash
   sudo usermod -a -G render $USER
   # Log out and log back in for this to take effect
   ```

2. **Check if perf events are enabled**:
   ```bash
   cat /proc/sys/kernel/perf_event_paranoid
   # If this returns 2 or higher, you may need to reduce it (requires root):
   sudo sysctl kernel.perf_event_paranoid=1
   ```

## Running the Program

### Single Snapshot Mode

Take a one-time measurement and exit:

```bash
./gpu_usage --snapshot
# or
./gpu_usage -s
```

### Continuous Monitoring Mode

Monitor GPU usage continuously (updates every second):

```bash
./gpu_usage
```

Press `Ctrl+C` to stop continuous monitoring.

### Example Output

```
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
Render: 23.5%  Blitter: 0.0%  Video: 12.3%  Enhance: 0.0%  | Total: 35.8%
Render: 45.2%  Blitter: 5.1%  Video: 0.0%  Enhance: 0.0%  | Total: 50.3%
Render: 12.1%  Blitter: 0.0%  Video: 8.7%  Enhance: 2.1%  | Total: 22.9%
```

## Interpreting the Output

- **Render**: 3D/graphics rendering engine utilization (games, 3D applications)
- **Blitter**: 2D operations and memory copy engine utilization
- **Video**: Hardware video decode/encode engine utilization
- **Enhance**: Video post-processing and enhancement engine utilization
- **Total**: Combined utilization across all engines (normalized to ≤100%)

## Troubleshooting

### Library Not Found

If you get "libigdmd.so: cannot open shared object file":

1. Make sure the library was built successfully
2. Set the `LD_LIBRARY_PATH` environment variable
3. Or install the library system-wide with `sudo make install`

### Permission Denied

If you get permission errors:

1. Add your user to the `render` group
2. Check perf event permissions
3. Try running with `sudo` (not recommended for regular use)

### No Compatible GPU Found

If the program reports "No compatible GPU found":

1. Make sure you have an Intel integrated GPU
2. Verify that the GPU drivers are properly installed
3. Check that `/dev/dri/` devices exist and are accessible

### No GPU Metrics Found

If GPU utilization metrics are not found:

1. Your GPU may not support the required performance counters
2. Try updating your GPU drivers
3. Some older Intel GPUs may not be supported

## Requirements

- **Linux kernel**: Version 5.7 or newer (varies by GPU generation)
- **Mesa**: Version 18.2 or newer (for event-based measurements)
- **Intel GPU**: Xe, Gen12, or newer architecture
- **Compiler**: GCC or Clang with C++17 support
- **CMake**: Version 3.5 or newer

For specific GPU requirements, see the main README.md file in the repository.

## License

This GPU usage monitor is provided under the same MIT License as the Intel Metrics Discovery library.