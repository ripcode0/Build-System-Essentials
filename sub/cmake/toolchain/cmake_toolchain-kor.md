### CMake 툴체인

#### 툴체인 파일이란?

`CMake`에서 *툴체인 파일(toolchain file)*은 빌드 환경을 사전에 정의하는 구성 스크립트입니다.  
이 파일에서는 **컴파일러 경로**, **링커**, **시스템 루트**, **환경 변수** 등을 지정합니다.  
이를 통해 시스템 기본 설정 대신 `LLVM`, `MinGW` 등 다양한 커스텀 툴체인을 사용하여 빌드할 수 있습니다.

#### 툴체인 파일 수동 사용 방법

프로젝트를 구성할 때 툴체인 파일을 직접 지정할 수 있습니다:

```cmd
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=<path>/xxx-toolchain.cmake
```

#### Toolchain file 을 이용 간단한 예제
##### 
```cmd
│   CMakeLists.txt
│
├───cmake
│       clang-toolchain.cmake
│
└───src
        main.cpp
```