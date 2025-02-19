# CMake Library Management

This guide explains various methods for managing libraries within a CMake-based project. Depending on your project's needs, you can choose from several approaches to include and manage libraries.

---

## Overview

There are multiple ways to manage libraries in CMake:

- **빌드 시스템에서 직접 라이브러리 추가**
Use `add_subdirectory` to include libraries directly from your project.
- **Git을 통한 SubModule**
Add external libraries as Git submodules.
- **시스템 혹은 프로젝트 내 인스톨된 라이브러리 사용**
Locate and use installed libraries with `find_package`.
- **git 저장소에서 라이브러리 가져오기**
Retrieve libraries from Git repositories using `FetchContent` or `ExternalProject`.
- **커스텀 인스톨 팩키지 함수 사용**
Define custom functions to handle library installation.

---

### 1. 빌드 시스템에서 직접 라이브러리 추가

* When the library is part of your project, you can add it using `add_subdirectory` and then build it with `add_library`.

```cmake
# Add the library's directory to the build
add_subdirectory(<path/library>)

# Create a library from the source files in that directory
add_library(my_library src/library.cpp)
```

### 2. Git을 통한 SubModule 사용
* Git submodules allow you to include external libraries in your repository. This method keeps external code versioned alongside your project.

* Adding a Git Submodule
```bash

git submodule add https://github.com/username/library.git <path/library>
git submodule update --init --recursive
```
```cmake
add_subdirectory(<path/library>)
```

### 3. 시스템 혹은 프로젝트 내 인스톨된 라이브러리 사용
To use libraries that are already installed on your system or within your project, use the find_package command.

```cmake
복사
find_package(library CONFIG REQUIRED)
if(library_FOUND)
    message(STATUS "Found the library package.")
endif()
```

### 4. git 저장소에서 라이브러리 가져오기
* CMake provides two main ways to fetch libraries directly from Git repositories:

#### 4.1. FetchContent
* `FetchContent` simplifies the process of downloading and building external projects.
For more details, see the `FetchContent` documentation.


```cmake
include(FetchContent)
FetchContent_Declare(
  library_name
  GIT_REPOSITORY https://github.com/username/library.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(library)
```
#### 4.2. ExternalProject
* The ExternalProject module allows for more complex build setups, including out-of-source builds.

```cmake
include(ExternalProject)
ExternalProject_Add(
  library_name
  GIT_REPOSITORY https://github.com/username/library.git
  GIT_TAG        master
  PREFIX         ${CMAKE_BINARY_DIR}/external/library
)
```

[back](../../../README.md)