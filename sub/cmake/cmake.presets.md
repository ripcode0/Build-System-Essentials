# Visual Studio Code에서 CMake Presets로 구성 및 빌드하기

CMake는 `CMakePresets.json`과 `CMakeUserPresets.json` 두 개의 파일을 지원하여, 사용자가 공통 구성(configure), 빌드, 테스트 옵션을 명시하고 다른 사람과 공유할 수 있도록 합니다. 이 두 파일을 사용하면 Visual Studio와 Visual Studio Code에서, 그리고 CI(지속적인 통합) 파이프라인 및 명령줄에서 CMake를 구동할 수 있습니다.

- **`CMakePresets.json`**: 프로젝트 전반에 걸친 빌드를 저장하는 용도
- **`CMakeUserPresets.json`**: 개발자가 개별적으로 로컬 빌드를 저장하는 용도

Visual Studio Code의 CMake Tools 확장 버전 1.7 이상에서 이 두 파일과의 통합 기능을 사용할 수 있습니다.

이 문서는 Visual Studio Code의 CMake Tools 확장에서 `CMakePresets.json`을 어떻게 활용하는지 다룹니다. 추가로 참고할 만한 링크는 다음과 같습니다:

- `CMakePresets.json` 포맷에 대한 자세한 정보: [CMake 공식 문서](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
- Microsoft 벤더 맵과 매크로 확장에 대한 자세한 정보: [CMakePresets.json 및 CMakeUserPresets.json의 Microsoft 벤더 맵 참조](https://docs.microsoft.com/cpp/build/cmake-presets-json-reference)
- Visual Studio에서 `CMakePresets.json` 사용하는 방법: [Visual Studio에서 CMake Presets로 구성 및 빌드하기](https://docs.microsoft.com/cpp/build/cmake-presets-vs)

CMake Tools 확장에서는 `kits`와 `variants` 파일 대신 `CMakePresets.json` 활용을 권장합니다. CMake Tools 확장에서 `CMakePresets.json` 통합을 활성화하거나 비활성화하려면, [CMake Tools 확장에서 `CMakePresets.json` 활성화](#enable-cmakepresetsjson-in-the-cmake-tools-extension)를 참고하세요.

---

## 지원되는 CMake 및 `CMakePresets.json` 버전

- CMake Tools 확장은 `CMakePresets.json` 및 `CMakeUserPresets.json` 파일의 **버전 2 이상**을 지원합니다.  
  - 파일 버전을 업데이트하려면 파일의 루트 객체에 있는 `version` 필드를 올리면 됩니다.  
  - 예시와 추가 정보는 [CMakePresets.json](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#format)을 참고하세요.

- 명령줄에서 `--preset` 옵션을 사용하여 CMake를 호출할 때는 **CMake 버전 3.20 이상**이 필요합니다.  
  - CMake Tools는 `CMakePresets.json`과 `CMakeUserPresets.json`을 직접 읽고 해석하며, CMake를 `--preset` 옵션으로 직접 호출하지는 않습니다.  
  - 따라서 Visual Studio Code 내부에서 `CMakePresets.json`으로 빌드할 때 반드시 CMake 3.20 이상이 필요한 것은 아니지만, **CMake 3.14 이상**을 사용할 것을 권장합니다.

---

## CMake Tools 확장에서 `CMakePresets.json` 활성화

`settings.json` 파일에 `cmake.useCMakePresets`라는 새 설정이 추가되었습니다:

| 설정                        | 설명                                                                 | 허용값               | 기본값 |
|----------------------------|-----------------------------------------------------------------------|----------------------|--------|
| `cmake.useCMakePresets`    | CMake configure, build, test를 `CMakePresets.json`으로 구동할지 여부 | `always`, `never`, `auto` | `auto` |

- `auto`로 설정되어 있으면, `cmake.sourceDirectory`(활성 폴더 기준)에 `CMakePresets.json`이 있으면 `always`로 평가하고, 없으면 `never`로 평가합니다.
- 명시적으로 모든 CMake 프로젝트에서 `CMakePresets.json` 통합을 켜거나 끄려면, `cmake.useCMakePresets`를 `always` 또는 `never`로 설정하면 됩니다.

---

## 구성(Configure) 및 빌드(Build)

Visual Studio Code에서 다음 명령을 사용하여 CMake 프로젝트를 구성하고 빌드할 수 있습니다. 명령 팔레트는 `Ctrl+Shift+P`로 열 수 있습니다.

![명령 팔레트 스크린샷](images/command-palette.png)

### CMake: Select Configure Preset

- **CMake: Select Configure Preset** 명령은 `CMakePresets.json`과 `CMakeUserPresets.json`에 정의된 **숨김 처리되지 않은(non-hidden) Configure Preset**들의 합집합을 보여줍니다.
- 원하는 Configure Preset을 선택하면 활성 Configure Preset이 됩니다.  
  - 이는 CMake가 프로젝트 빌드 시스템을 생성할 때 사용하는 `configurePreset` 값입니다.
- 활성 Configure Preset은 CMake Tools 사이드바의 "Project Status View"에 표시됩니다.

CMake Tools는 Microsoft Visual Studio Settings 벤더 맵의 `hostOS` 값을 사용하여, 현재 플랫폼에 적용되지 않는 Configure Preset을 숨깁니다. 자세한 내용은 [Visual Studio Settings vendor map](https://docs.microsoft.com/cpp/build/cmake-presets-json-reference#visual-studio-settings-vendor-map)의 `hostOS` 항목을 참고하세요.

### CMake: Configure

- **CMake: Configure** 명령을 실행하면 프로젝트를 구성합니다.  
  - 이는 명령줄에서 `cmake --preset <configurePreset>`을 실행하는 것과 동일합니다. 여기서 `<configurePreset>`은 활성 Configure Preset의 이름입니다.

> [!NOTE]  
> Windows 개발자의 경우, Visual Studio Code를 "개발자 명령 프롬프트(Developer Command Prompt)"에서 열어야 하며, 그렇지 않은 경우 **CMake: Scan for Compilers** 명령을 실행하여 Visual Studio에 설치된 빌드 도구(CMake, Ninja)를 CMake Tools 확장이 인식하도록 해야 합니다.

### CMake: Select Build Preset

- **CMake: Select Build Preset** 명령은 "기본 Build Preset"과 `CMakePresets.json`, `CMakeUserPresets.json`에 정의된 **숨김 처리되지 않은 Build Preset**들의 합집합을 보여줍니다.
- "기본 Build Preset"은 명령줄에서 `cmake --build`를 추가 인자 없이 실행하는 것과 동일합니다.
- 원하는 Build Preset을 선택하면 활성 Build Preset이 됩니다.  
  - 이는 CMake로 프로젝트를 빌드할 때 사용하는 `buildPreset` 값입니다.
- 활성 Build Preset은 CMake Tools 사이드바의 "Project Status View"에 표시됩니다.

모든 Build Preset에는 연결된 `configurePreset` 값이 있어야 합니다. CMake Tools는 활성 Configure Preset에 맞지 않는 Build Preset을 숨깁니다. 자세한 내용은 [Build Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#build-preset)을 참고하세요.

### CMake: Build

- **CMake: Build** 명령을 실행하면 전체 프로젝트를 빌드합니다.  
  - 이는 명령줄에서 `cmake --build --preset <buildPreset>`을 실행하는 것과 동일합니다. `<buildPreset>`에는 활성 Build Preset의 이름을 넣습니다.
- **CMake: Build Target** 명령을 실행하면, 활성 Build Preset에 설정된 빌드 지침을 사용해 특정 타깃만 빌드합니다.

---

## 테스트(Test)

CTest는 CMake의 테스트 구동 프로그램이며, CMake Tools 확장과 통합되어 있습니다. 자세한 내용은 [CTest 문서](https://cmake.org/cmake/help/latest/manual/ctest.1.html#ctest-1)를 참고하세요.

### CMake: Select Test Preset

- **CMake: Select Test Preset** 명령은 "기본 Test Preset"과 `CMakePresets.json`, `CMakeUserPresets.json`에 정의된 **숨김 처리되지 않은 Test Preset**들의 합집합을 보여줍니다.
- "기본 Test Preset"은 명령줄에서 추가 인자 없이 `ctest`를 실행하는 것과 동일합니다.
- 원하는 Test Preset을 선택하면 활성 Test Preset이 됩니다.  
  - 이는 CTest로 테스트를 실행할 때 사용되는 `testPreset` 값입니다.
- 활성 Test Preset은 CMake Tools 사이드바의 "Project Status View"에 표시됩니다.

모든 Test Preset에는 연결된 `configurePreset` 값이 있어야 합니다. CMake Tools는 활성 Configure Preset에 맞지 않는 Test Preset을 숨깁니다. 자세한 내용은 [Test Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#test-preset)을 참고하세요.

### CMake: Run Tests

- **CMake: Run Tests** 명령을 실행하면 CTest가 호출됩니다.
- `cmake.ctest.testExplorerIntegrationEnabled`를 활성화한 상태에서는, `cmake.ctest.allowParallelJobs` 설정에 따라 테스트 실행 방식이 달라집니다.
  - `cmake.ctest.allowParallelJobs`가 비활성화된 상태에서는 테스트 진행 상황을 Test Explorer에서 정확하게 추적하기 위해 각 테스트가 개별적으로 실행됩니다.
  - `cmake.ctest.allowParallelJobs`가 활성화된 상태에서는 모든 테스트가 병렬로 실행되며, 이는 명령줄에서 `ctest --preset <testPreset>`을 실행하는 것과 동일합니다. 여기서 `<testPreset>`은 활성 Test Preset의 이름입니다.

### CMake Tools 사이드바의 Project Status View 동작

CMake Tools 사이드바의 Project Status View에는 활성 Configure Preset, Build Preset, Test Preset이 각각의 노드(Configure, Build, Test) 아래에 표시됩니다. 각 옵션을 선택해서 활성 Preset을 변경할 수 있습니다.

![CMake 사이드바 Project Status View의 스크린샷](images/cmake-presets.png)

개별 상태 표시줄 아이콘을 표시하거나 숨기려면, `settings.json`의 `cmake.options.advanced`를 수정하세요. 뷰 구성에 대한 자세한 내용은 [CMake 뷰 구성 문서](cmake-options-configuration.md)를 참고하세요.

---

## 새 Preset 추가하기

CMake Tools의 "Add" 명령과 Preset 템플릿은 기본적으로 `CMakePresets.json`을 수정합니다.  
유저 레벨(로컬)의 Preset을 새로 추가하고 싶다면, `CMakeUserPresets.json`을 직접 편집하십시오.

> **경로 표기 주의:**  
> `CMakePresets.json` 및 `CMakeUserPresets.json`에서는 경로 구분자로 **슬래시**(`/`)를 사용해야 합니다.

### 새 Configure Preset 추가하기

- **CMake: Add Configure Preset** 명령을 실행하면, 몇 가지 Configure Preset 템플릿 목록과 **[Scan for Compilers]** 옵션이 표시됩니다.
  - **[Scan for Compilers]**를 선택하면 `PATH`에 있는 GCC/Clang 컴파일러, `cmake.additionalCompilerSearchDirs`와 `cmake.emscriptenSearchDirs`에 등록된 모든 컴파일러, 그리고 Visual Studio에 설치된 최신 버전의 `cl.exe`를 검색합니다.
  
  ![새 Configure Preset 추가 스크린샷](images/add-configure-preset-vscode.png)

  - **Inherit from Configure Preset**: 이미 존재하는 Configure Preset을 상속합니다. 상속에 관한 자세한 내용은 [Configure Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#configure-preset)을 참고하세요.
  - **Toolchain File** 템플릿: CMake 툴체인 파일로 프로젝트를 구성하는 템플릿입니다.
  - **Custom** 템플릿: 아무 옵션이 없는 Configure Preset을 만듭니다.
  - **[Scan for Compilers]**: 시스템에서 C/C++ 컴파일러를 검색합니다.

- `CMakePresets.json`이 이미 존재한다면, 선택한 템플릿이 `CMakePresets.json`에 추가됩니다.  
  - 만약 없으면, 새로운 `CMakePresets.json` 파일이 생성되고 템플릿이 복사됩니다.
- 생성된 Preset을 수정하는 방법은 [Edit presets](#edit-presets)를 참고하세요.

> [!NOTE]  
> Windows 환경에서 CMake Tools는 기본적으로 가장 최근 버전의 Visual Studio가 설치한 `cl.exe`를 사용합니다. 특정 컴파일러 버전을 지정하고 싶다면, `CMakePresets.json`의 `toolset` 옵션을 설정하세요. 자세한 내용은 [Configure Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#configure-preset)와 [Toolset Selection](https://cmake.org/cmake/help/latest/generator/Visual%20Studio%2016%202019.html#toolset-selection)을 참고하세요.

### 새 Build Preset 추가하기

- **CMake: Add Build Preset** 명령을 실행하면, 여러 가지 Build Preset 템플릿 목록이 나타납니다:
  - **Create from Configure Preset**: `CMakePresets.json`에 정의된 `configurePresets` 목록이 표시되고, 선택한 Configure Preset에 연결되는 빈 Build Preset이 생성됩니다.
  - **Inherit from Build Preset**: 이미 존재하는 `buildPresets` 목록이 표시되고, 선택한 Build Preset을 상속하는 새 Build Preset이 생성됩니다.
  - **Custom**: 아무 옵션이 없는 빈 Build Preset을 생성합니다.

자세한 수정 방법은 [Build Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#build-preset)을 참고하세요.

### 새 Test Preset 추가하기

- **CMake: Add Test Preset** 명령을 실행하면, 여러 가지 Test Preset 템플릿 목록이 나타납니다:
  - **Create from Configure Preset**: `CMakePresets.json`에 정의된 `configurePresets` 목록이 표시되고, 선택한 Configure Preset에 연결되는 빈 Test Preset이 생성됩니다.
  - **Inherit from Test Preset**: 이미 존재하는 `testPresets` 목록이 표시되고, 선택한 Test Preset을 상속하는 새 Test Preset이 생성됩니다.
  - **Custom**: 아무 옵션이 없는 빈 Test Preset을 생성합니다.

자세한 수정 방법은 [Test Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#test-preset)을 참고하세요.

---

## Preset 편집하기 (Edit presets)

Configure Preset, Build Preset, Test Preset을 편집하는 가장 자세한 정보는 [CMake 공식 문서](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#id1)를 참고하세요. 이곳에서는 자주 사용하는 기능 몇 가지를 요약합니다.

### 컴파일러 선택하기

- Configure Preset에서 `cacheVariables.CMAKE_C_COMPILER`와 `cacheVariables.CMAKE_CXX_COMPILER`를 통해 C 및 C++ 컴파일러를 설정할 수 있습니다.  
  - 이는 명령줄에서 `-D CMAKE_C_COMPILER=<값>`와 `-D CMAKE_CXX_COMPILER=<값>`를 넘기는 것과 동일합니다.
  - 자세한 내용은 [`CMAKE_<LANG>_COMPILER`](https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER.html#cmake-lang-compiler)를 참고하세요.

- `PATH`에 있는 컴파일러 이름을 직접 적거나, 컴파일러의 전체 경로를 담고 있는 환경 변수를 사용할 수 있습니다.  
  - 파일을 공유 가능하게 유지하려면 전체 경로는 지양하고 환경 변수를 사용하는 방법이 권장됩니다.

- Visual C++ 툴셋을 사용하는 경우, CMake Tools는 자동으로 최신 Visual Studio 빌드 도구 환경을 설정합니다. 특정 버전의 컴파일러를 사용하려면, `CMakePresets.json`의 `toolset` 옵션을 사용하세요. 자세한 내용은 [Configure Presets와 Toolset Selection](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html)을 참고하세요.

예를 들어, 64비트 Windows에서 `cl.exe`와 Visual Studio Generator를 사용해 빌드하는 Preset은 다음과 같이 설정할 수 있습니다:

```json
"architecture": {
   "value": "x64",
   "strategy": "set"
},
"cacheVariables": {
   "CMAKE_BUILD_TYPE": "Debug",
   "CMAKE_C_COMPILER": "cl",
   "CMAKE_CXX_COMPILER": "cl",
   "CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}"
}
```
