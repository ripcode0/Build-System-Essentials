# CMake Package Libray Installation

## Overview

This guide explains how to install packages using `CMake`

### 1.installing External Library Packages with `CMake`

* Using find_package
```cmake
find_package(<libname> CONFIG REQUIRED)
if(<libname>_FOUND)
    message(STATUS "Found the <libname> package.")
endif()
```

### 2.Create an installable C/C++ library using `CMake`
```
project_root/
├── CMakeLists.txt
├── src/
│   ├── library.h
│   ├── library.cpp
├── build/
```

### 3.Setting up in CMakeLists.txt
```cmake
#if neither STATIC nor SHARED, the library will be STATIC by default
add_library(<libname> src/library.cpp)
```

