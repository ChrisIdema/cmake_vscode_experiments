# cmake_vscode_experiments

# Goals

- basic project v
- separate build folder
- split source files into folders, multiple CMakeLists
- configuration
- forced 32-bit compilation on native target to aid unit tests for 32-bit platforms
- different optimization settings for different source files and Cmake subfolders
- cross compilation for stm32
- windows and linuxS
- multiple build variants or build targets

# Build

## basic

-cmake configure
-cmake build or build task: "cmake"
-run or debug

## 32bit

windows:
select a 32-bits kit such as mingw32

Linux:
```
sudo apt-get install gcc-multilib
```


# Bugs
- Debugging doesn't always work

# notes
- no definition found for "CMAKE_PROJECT_NAME': C/C++:Reset IntelliSense Database
