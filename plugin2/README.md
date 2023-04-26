#  CMake Template for Juce plug-in

To generate an **Xcode** project, run:
```sh
cmake -B Build -G Xcode -D CMAKE_OSX_ARCHITECTURES=arm64\;x86_64 -D CMAKE_OSX_DEPLOYMENT_TARGET=10.13
```
The `-D CMAKE_OSX_ARCHITECTURES=arm64\;x86_64` flag is required to build universal binaries.

The `-D CMAKE_OSX_DEPLOYMENT_TARGET=10.13` flag sets the minimum MacOS version to be supported.

---

To generate a **Visual Studio 2022 (17)** project, run:
```sh
cmake -B Build -G "Visual Studio 17"
```

