## CMake `FetchContent`

`FetchContent`는 CMake에서 외부 프로젝트(라이브러리 등)를 다운로드하고 빌드하는 방법 중 하나입니다.  
이는 `ExternalProject_Add`보다 간단하며, **빌드 트리에 직접 추가**할 수 있어 **CMakeLists.txt 내에서 직접 라이브러리를 가져오는 데 유용**합니다.

---

## 1. `FetchContent`란?
CMake의 `FetchContent` 모듈은 **외부 프로젝트를 소스 코드와 함께 가져와서 직접 빌드**할 수 있도록 도와줍니다.

- 외부 프로젝트를 `add_subdirectory()`처럼 다룰 수 있음
- `ExternalProject_Add`보다 간단하게 사용 가능
- 캐싱을 지원하여 동일한 다운로드를 방지
- **CMake의 `add_library()` 또는 `add_executable()`로 빌드 가능**

---

## 2. `FetchContent` 사용 방법
### (1) 기본 사용법
다음은 `GLFW`를 `FetchContent`로 다운로드하여 사용해보는 예제입니다.

```cmake
include(FetchContent)  # FetchContent 모듈 포함

# 프로젝트에 필요한 라이브러리 가져오기
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8  # 사용할 버전 태그
)

# 다운로드 및 프로젝트 추가
FetchContent_MakeAvailable(glfw)

# GLFW를 사용하여 실행 파일 빌드
add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE glfw)
```

**설명**
- `FetchContent_Declare()`: 다운로드할 **외부 프로젝트의 저장소 및 버전 정보**를 설정
- `FetchContent_MakeAvailable()`: 지정된 프로젝트를 다운로드하고 `add_subdirectory()`처럼 사용 가능하도록 처리

---

### (2) 여러 개의 라이브러리 가져오기
여러 개의 외부 프로젝트를 `FetchContent`로 가져올 수도 있습니다.

```cmake
include(FetchContent)

# JSON for Modern C++ 라이브러리 추가
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)

# fmt 라이브러리 추가
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 9.1.0
)

# 다운로드 및 프로젝트 추가
FetchContent_MakeAvailable(json fmt)

# 실행 파일 빌드 및 라이브러리 연결
add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE nlohmann_json fmt)
```

`FetchContent_MakeAvailable(json fmt)`을 한 번 호출하면 여러 개의 라이브러리를 한 번에 가져올 수 있습니다.

---

### (3) `FetchContent`를 CMake 옵션과 함께 사용하기
외부 프로젝트의 CMake 옵션을 설정하려면 `FetchContent_GetProperties()`와 `set()`을 활용할 수 있습니다.

```cmake
include(FetchContent)

# ImGui 라이브러리 추가
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.89.9
)

FetchContent_GetProperties(imgui)
if(NOT imgui_POPULATED)
    set(IMGUI_BUILD_EXAMPLES OFF)  # 불필요한 예제 빌드 끄기
    set(IMGUI_BUILD_TESTS OFF)     # 테스트 빌드 끄기
    FetchContent_Populate(imgui)
    add_subdirectory(${imgui_SOURCE_DIR} ${imgui_BINARY_DIR})
endif()

# 실행 파일에 ImGui 연결
add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE imgui)
```

* `FetchContent_GetProperties(imgui)` → 이미 다운로드된 경우 다시 다운로드하지 않도록 방지

* `set(IMGUI_BUILD_EXAMPLES OFF)` → 라이브러리의 CMake 옵션 설정 가능

---

## 3. `FetchContent` vs `ExternalProject_Add`
| 특징 | `FetchContent` | `ExternalProject_Add` |
|------|--------------|------------------|
| 빌드 방식 | **소스 트리에 추가** | 독립적인 빌드 |
| 다운로드 위치 | **빌드 디렉토리 내에서 직접 포함** | 별도의 다운로드 경로 지정 가능 |
| 사용 방법 | `add_subdirectory()`처럼 사용 가능 | `CMake`의 별도 `install()` 과정 필요 |
| 라이브러리 연결 | `target_link_libraries()`로 직접 연결 가능 | 수동으로 `find_package()` 필요 |

* **`FetchContent`는 단순한 라이브러리(예: GLFW, JSON 등)에 적합**,  
* **`ExternalProject_Add`는 독립적인 소프트웨어(예: LLVM, Qt 등) 빌드에 적합**합니다.

---

## 4. `FetchContent` 캐싱 문제 해결
CMake는 `FetchContent`로 다운로드한 프로젝트를 **캐시**합니다.  
만약 버전을 변경했는데 이전 버전이 계속 사용된다면, 캐시를 초기화해야 합니다.

* **해결 방법: 빌드 디렉토리 초기화**
```sh
rm -rf build
cmake -S . -B build
cmake --build build
```
이렇게 하면 `FetchContent`가 다시 다운로드됩니다.

---

## 5. `FetchContent`의 고급 사용법
### (1) `FetchContent_Populate()`로 직접 다운로드
```cmake
include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
)

FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE spdlog)
```

* **`FetchContent_Populate()`를 사용하면 라이브러리 설정을 직접 변경할 수 있음**

---

## 6. 결론
1. **`FetchContent`는 `add_subdirectory()`처럼 외부 프로젝트를 간단하게 포함하는 방식**  
2. **`ExternalProject_Add`보다 설정이 간단하며, 타겟과 직접 연결 가능**  
3. **여러 개의 라이브러리를 한 번에 가져올 수 있음**  
4. **CMake 옵션을 설정할 수 있으며, 커밋/브랜치 지정도 가능** 

