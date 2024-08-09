# Intel(R) Metrics Discovery Application Programming Interface

## Introduction

This software is a user mode library that provides access to GPU performance data.

The library has OS abstraction layer that allows for interoperability in different environments.

## License

Intel(R) Metrics Discovery Application Programming Interface is distributed under the MIT License.

You may obtain a copy of the License at:
https://opensource.org/licenses/MIT

## Supported Platforms

- Intel(R) Processors with Arc graphics devices (formerly Alchemist)
- Intel(R) Processors with Gen12 graphics devices (formerly Tiger Lake, Arctic Sound, DG1, Rocket Lake, Ponte Vecchio, Alder Lake)
- Intel(R) Processors with Gen11 graphics devices (formerly Ice Lake, Elkhart Lake),
- Intel(R) Processors with Gen9 graphics devices (formerly Skylake, Kaby Lake, Apollo Lake/Broxton, Gemini Lake, Coffee Lake),
- Intel(R) Processors with Gen8 graphics devices (formerly Broadwell),
- Intel(R) Processors with Gen7.5 graphics devices (formerly Haswell).

## Supported Operating Systems

Intel(R) Metrics Discovery Application Programming Interface is supported on Linux family operating systems with minimum kernel version 4.14.
Event based measurements require minimum Mesa version 18.2.

### Detailed minimum version requirements

| Platform | Code Name | Minimum Linux Kernel Version | Minimum Mesa Version |
|--|--|--|--|
| Arc | Alchemist | 5.20 | 22.1.5 |
| Gen12 | Rocket Lake | 5.17 | 22.1.5 |
| Gen12 | DG1 | 5.13 | 22.1.5 |
| Gen12 | Tiger Lake | 5.9 | 21.0 |
| Gen11 | Elkhart Lake | 5.3 | 19.1 |
| Gen11 | Ice Lake | 4.18 | 19.1 |
| Gen9, Gen8 | * | 4.14 | 18.2 |
| Gen7.5 | Haswell | 4.17 | 18.2 |

## Build and Install

1\. Download sources.

2\. Install libdrm-dev.

```shell
sudo apt install libdrm-dev
```
or
```shell
sudo dnf install libdrm-devel
```

3\. Run CMake generation:

```shell
mkdir build && cd build
cmake ..
```

4\. Build:

```shell
make -j$(nproc)
```

5\. Built library will be here (for 64-bit Linux):

```shell
(project_root)/dump/linux64/release/metrics_discovery/libigdmd.so
```

6\. Install:

If using native package manager (yum, dnf, etc..) skip to step 7

```shell
sudo make install
```

7\. Packaging:

```shell
make package
```

After the process completes, there should be a set of files such as
```code
intel-metrics-discovery-[VERSION].x86_64.rpm
intel-metrics-discovery-devel-[VERSION].x86_64.rpm
intel-metrics-discovery-pkgconfig-[VERSION].x86_64.rpm
```

*Note: To clear CMake params remove CMakeCache.txt, then regenerate.*

## Support

Please file a GitHub issue to report an issue or ask questions.

## How to Contribute

Contributions to the Metrics-Discovery are welcomed and encouraged.
Please see [CONTRIBUTING](CONTRIBUTING.md) for details how to
contribute to the project.

##
___(*) Other names and brands my be claimed as property of others.___
