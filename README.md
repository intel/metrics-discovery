# Intel(R) Metrics Discovery Application Programming Interface

## Introduction

This software is a user mode library that provides access to GPU performance data.

The library has OS abstraction layer that allows for interoperability in different environments.

## License

Intel(R) Metrics Discovery Application Programming Interface is distributed under the MIT License.

You may obtain a copy of the License at:
https://opensource.org/licenses/MIT

## Supported Platforms

- Intel(R) Processors with Xe3P graphics devices (formerly Crescent Island)
- Intel(R) Processors with Xe3 graphics devices (formerly Panther Lake, Wildcat Lake, Nova Lake)
- Intel(R) Processors with Xe2 graphics devices (formerly Lunar Lake)
- Intel(R) Processors with Arc graphics devices (formerly Alchemist, Battlemage)
- Intel(R) Processors with Xe graphics devices (formerly Tiger Lake, Rocket Lake, DG1, Alder Lake, Ponte Vecchio, Meteor Lake, Arrow Lake)

Since version 1.14.181, support for Gen7.5, Gen8, Gen9 and Gen11 platforms has been discontinued. For these platforms, use version 1.14.180 or earlier.

## Supported Operating Systems

Intel(R) Metrics Discovery Application Programming Interface is supported on Linux family operating systems with minimum kernel version 5.7.
Event based measurements require minimum Mesa version 18.2.

### Detailed minimum version requirements

| Platform | Code Name | Minimum Linux Kernel Version | Minimum Mesa Version |
|--|--|--|--|
| Xe3P-XPC | Crescent Island | 6.19 | ---- |
| Xe3-LPG | Nova Lake | 6.19 | 26.0 |
| Xe3-LPG | Wildcat Lake | 6.18 | 25.3 |
| Xe3-LPG | Panther Lake | 6.15 | 25.1 |
| Xe2-HPG | Battlemage | 6.11 | 24.2 |
| Xe2-LPG | Lunar Lake | 6.11 | 24.2 |
| Xe-LPG | Arrow Lake-H | 6.9 | 24.1 |
| Xe-LPG | Arrow Lake-S | 6.7 | 24.1 |
| Xe-LPG | Arrow Lake-U | 6.9 | 24.1 |
| Xe-LPG | Meteor Lake | 6.7 | 23.1 |
| Xe-HPG | Alchemist | 6.2 | 22.2 |
| Xe-HPC | Ponte Vecchio | 5.20 | 18.2 |
| Xe-LP | Alder Lake-S | 5.16 | 22.0 |
| Xe-LP | Alder Lake-N | 5.18 | 22.0 |
| Xe-LP | Alder Lake-P | 5.17 | 22.0 |
| Xe-LP | DG1 | 5.16 | 22.1.5 |
| Xe-LP | Rocket Lake | 5.13 | 20.2 |
| Xe-LP | Tiger Lake | 5.7 | 21.0 |

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
