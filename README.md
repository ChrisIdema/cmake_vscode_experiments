# cmake_vscode_experiments

# Goals

- basic project v
- separate build folder v
- split source files into folders, multiple CMakeLists
- configuration
- forced 32-bit compilation on native target to aid unit tests for 32-bit vplatforms
- different optimization settings for different source files and Cmake subfolders
- cross compilation for stm32
- windows and linux
- multiple build variants or build targets

# Build

overview:
- **basic**: simple main.c that prints cmake project name, cmake project version, C/C++ version and pointer size. Working debug in launch.json.
- **basic2**: same as basic, but with external build folder
- **32bit**: same as basic2, but forced 32-bit build
- **flags**: same as basic2, but with a second source file with separate compile flags
- **subfolders**: C/C++ mixture, separate folders with sources and CMakeList.txt files, private includes, private compiler flags

## basic

- cmake configure
- cmake build or build task: "cmake"
- run or debug

## 32bit

windows:
select a 32-bits kit such as mingw32

Linux:
```
sudo apt-get install gcc-multilib
```

# notes
- if you get `no definition found for "CMAKE_PROJECT_NAME'`: C/C++:Reset IntelliSense Database
