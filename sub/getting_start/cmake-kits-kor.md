### CMake Kits

**CMake Kits** 은 `VSCode` 확장인 `CMake Tools` 에서 사용되는 메타 정보로,
컴파일러 및 빌드 환경을 쉽게 전환하고 관리할 수 있도록 도와줍니다.
여러 툴체인을 사용할 때 프로젝트 간 빠르게 전환하는 데 매우 유용합니다.

- `cmake-tools-kits.json` : `사용자(Global)` 단위 설정
- `.vscode/CMake-Kits.json` : `프로젝트 단위(Local)` 설정  

#### Kits 사용 방법

* 명령 팔레트 열기 

   `Ctrl + Shift + P`를 눌러 **명령 팔레트**를 엽니다.

* Kit 선택하기 
   * `CMake: Select a Kit` 입력 : 사용 가능한 툴체인 목록이 표시됨
   * `CMakePresets` 가 활성화되어 있으면 Kit 메뉴가 비활성화됩니다. 아래 설정으로 끌 수 있습니다
   `.vscode/setting.json`
   ```
   "cmake.useCMakePresets": "never"
   ```

* 툴체인 선택
   원하는 컴파일러 환경 (예: Visual Studio, Clang, GCC 등)을 선택합니다.

#### Kits 탐지 방식

CMake Tools는 내부적으로 다음 명령어들을 사용하여 시스템에 설치된 컴파일러 및 툴체인을 자동으로 검색합니다:

- `which` (유닉스 계열)
- `where` (Windows)
- `vswhere` (Visual Studio 설치 탐색용)

이를 통해 다양한 플랫폼과 컴파일러 환경에 맞는 Kits를 자동으로 스캔하고 구성할 수 있습니다.


#### 글로벌 kit 설정 파일

* `CMake Tools` 에서는 전역(Global) 및 로컬(Local) Kits 설정을 지원합니다.
* `명령 팔레트` (`Ctrl + Shift + P`)를 열고  
  `CMake: Edit User-Local CMake Kits`를 입력하면 `글로벌 kit 설정 파일` 을 편집할 수 있습니다.

* 플랫폼별 `글로벌 kit 설정 파일` 기본 위치는 다음과 같습니다:
```
[MacOS]     /Users/<user name>/.local/share/CMakeTools/cmake-tools-kits.json
[Windows]   C:\Users\<user name>\AppData\Local\CMakeTools\cmake-tools-kits.json
[Ubuntu]    /home/<user name>/.local/share/CMakeTools/cmake-tools-kits.json
```

```json
[
    {
        "name": "Clang 20.1.7 x86_64-w64-windows-gnu (clang64)",
        "compilers": {
            "C": "C:\\msys64\\clang64\\bin\\clang.exe",
            "CXX": "C:\\msys64\\clang64\\bin\\clang++.exe"
            },
        "isTrusted": true,
        "environmentVariables": {
            "CMT_MINGW_PATH": "C:\\msys64\\clang64\\bin",
            "MSYSTEM": "CLANG64",
            "MSYSTEM_PREFIX": "/clang64",
            "PATH": "C:\\msys64\\clang64\\bin;C:\\msys64\\usr\\bin;${env:PATH}"
            }
  },
  ..etc
]
```
#### 프로젝트 Local Kits 설정
* `.vscode/CMake-Kits.json` 파일에 로컬 Kits 을 명시할 수 있습니다.
* 하지만 변경 후 즉시 적용되지는 않으며, 아래 순서를 따라야 적용됩니다
   * `VSCode` 재시작
   * `CMake: Select a Kit` 실행
   * 새로 정의된 Kit 목록 스캔

#### Local kits 을 만들어보자
##### MSVC 예시
* 먼저, 아래 명령어를 통해 `vcvars64.bat`의 경로를 찾습니다:
```cmd
where /R "C:\Program Files\Microsoft Visual Studio" vcvars64.bat
```
* 찾은 경로를 .vscode/cmake-kits.json 에 다음과 같이 등록합니다
```json
[
    {
        "name": "msvc-cl",
        "compilers": {
            "C": "cl.exe",
            "CXX": "cl.exe"
        },
        "environmentSetupScript": "C:/Program Files/Microsoft Visual Studio/2022/Professional/VC/Auxiliary/Build/vcvars64.bat"
    }
]
```

* environmentSetupScript는 Visual Studio 환경 변수 초기화를 위한 스크립트입니다.
* 설정 후 반드시 VSCode를 재시작하고 Kit을 다시 선택해야 적용됩니다.