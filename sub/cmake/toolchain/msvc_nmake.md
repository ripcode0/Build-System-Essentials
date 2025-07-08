#### MSVC NMake Makefiles

* msvc-namke-toolchain.cmake

```cmake

set(VSWHERE "C:/Program Files (x86)/Microsoft Visual Studio/Installer/vswhere.exe")

# vswhere로 최신 Visual Studio 경로 찾기
execute_process(
    COMMAND ${VSWHERE} -latest -property installationPath
    OUTPUT_VARIABLE VS_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(NOT VS_PATH)
    message(FATAL_ERROR "Visual Studio installation not found!")
endif()

# vcvarsall.bat 실행 (환경 변수 설정)
set(VCVARSALL "${VS_PATH}/VC/Auxiliary/Build/vcvarsall.bat")

if(NOT EXISTS ${VCVARSALL})
    message(FATAL_ERROR "vcvarsall.bat not found at: ${VCVARSALL}")
endif()

# 환경 변수 설정을 위해 vcvarsall 실행
execute_process(
    COMMAND cmd /c CALL ${VCVARSALL} x64 && set
    OUTPUT_VARIABLE ENV_VARS
)

# vswhere로 최신 cl.exe 찾기
execute_process(
    COMMAND ${VSWHERE} -latest -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -find VC/Tools/MSVC/*/bin/Hostx64/x64/cl.exe
    OUTPUT_VARIABLE CL_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(NOT CL_PATH)
    message(FATAL_ERROR "cl.exe not found! Run vcvarsall.bat manually.")
endif()

# cl.exe 및 nmake.exe 경로 설정
get_filename_component(COMPILER_DIR ${CL_PATH} DIRECTORY)
set(CMAKE_C_COMPILER ${CL_PATH})
set(CMAKE_CXX_COMPILER ${CL_PATH})
set(CMAKE_MAKE_PROGRAM "${COMPILER_DIR}/nmake.exe")

# 기본 빌드 타입 설정
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

# MSVC 기본 플래그 설정
set(CMAKE_C_FLAGS_INIT "/D_CRT_SECURE_NO_WARNINGS /W3")
set(CMAKE_CXX_FLAGS_INIT "/D_CRT_SECURE_NO_WARNINGS /EHsc /W4 /Zc:__cplusplus")

set(CMAKE_GENERATOR "NMake Makefiles")

set(CMAKE_CL_NOLOGO ON) # MSVC 로고 출력 비활성화
set(CMAKE_NMAKE_COMPILER ${CL_PATH}) # NMake용 컴파일러 명시적 지정

message(STATUS "✔ Using cl.exe: ${CL_PATH}")
message(STATUS "✔ Using nmake.exe: ${CMAKE_MAKE_PROGRAM}")
message(STATUS "✔ MSVC environment initialized using ${VCVARSALL}")
```

* CMakePresets.json

```json
{
    "version": 3,
    "cmakeMinimumRequired": {
        "major": 3,
        "minor": 22,
        "patch": 0
    },
    "configurePresets": [
        {
            "name": "msvc-nmake",
            "description": "MSVC with NMake Makefiles",
            "generator": "NMake Makefiles",
            "binaryDir": "${sourceDir}/build",
            "cacheVariables": {
                "CMAKE_TOOLCHAIN_FILE": "${sourceDir}/cmake/msvc_nmake_toolchain.cmake",
                "CMAKE_BUILD_TYPE" :"Release"
            }
        }
    ],
    "buildPresets": [
        {
            "name": "msvc",
            "description": "msvc with visual studio",
            "displayName": "msvc",
            "configuration" : "Release",
            "configurePreset": "msvc-nmake",
            "jobs": 4,
            "targets" : ["all"]
        }
    ]
}
```

[back](../../../README.md)