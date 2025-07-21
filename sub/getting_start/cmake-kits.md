## CMake Kits

**CMake Kits**는 `VSCode` 에서 많이 사용되며, 편리하게 컴파일러 환경을 세팅할 수 있는 도구입니다.  
CMake 프로젝트의 빌드 환경을 빠르게 전환하고 설정하는 데 유용합니다.

#### 사용 방법

* **명령 팔레트 열기**  
   `Ctrl + Shift + P`를 눌러 **명령 팔레트**를 엽니다.

* **Kit 선택하기**  
   `CMake: Select a Kit`을 입력하면 사용 가능한 툴체인 리스트가 표시됩니다.
   참고로 CMakePresets 가 활성화 되어 있다면 Select a Kit 보이지 않습니다
   `.vscode/setting.json`
   ```
   "cmake.useCMakePresets": "never"
   ```

* **툴체인 선택**  
   원하는 컴파일러 환경 (예: Visual Studio, Clang, GCC 등)을 선택합니다.

#### Kit 탐지 방식

CMake Tools는 내부적으로 다음 명령어들을 사용하여 시스템에 설치된 컴파일러 및 툴체인을 자동으로 검색합니다:

- `which` (유닉스 계열)
- `where` (Windows)
- `vswhere` (Visual Studio 설치 탐색용)

이를 통해 다양한 플랫폼과 컴파일러 환경에 맞는 Kits를 자동으로 스캔하고 구성할 수 있습니다.

#### Kits 의 탐색 정보들

* 팔레트를 열어 CMake: Edit User-Local CMake Kits 입력
* 정보 확인

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