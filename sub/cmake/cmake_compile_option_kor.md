
# MSVC에서 디버그 모드일 때 CMake 컴파일 옵션 설정 방법

CMake에서 **MSVC 컴파일러**를 사용할 때 **디버그 모드(Debug build)** 에 특정 컴파일 옵션을 적용하는 방법을 설명합니다.

---

## 🔹 방법 1: `target_compile_options()` 사용 (추천)
특정 **타겟(Target)** 에 대해 **디버그 모드일 때만** 컴파일 옵션을 추가하는 방법입니다.

```cmake
target_compile_options(MyTarget PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:$<$<CONFIG:Debug>:/D_DEBUG /MTd /Od /Zi>>
)
```

### 🔹 설명
- `$<CXX_COMPILER_ID:MSVC>` → MSVC 컴파일러일 경우만 적용
- `$<CONFIG:Debug>` → Debug 모드일 경우만 적용
- `/D_DEBUG` → `_DEBUG` 매크로 정의
- `/MTd` → 디버그용 멀티스레드 라이브러리 사용
- `/Od` → 최적화 비활성화 (Debug용)
- `/Zi` → 디버그 정보 포함

📌 **이 방법은 특정 타겟에만 적용되므로 가장 안전한 방법입니다.**

---

## 🔹 방법 2: `set_property()` 사용
특정 **타겟(Target)** 에 대한 설정을 변경하는 또 다른 방법입니다.

```cmake
set_property(TARGET MyTarget APPEND PROPERTY COMPILE_OPTIONS
    $<$<CXX_COMPILER_ID:MSVC>:$<$<CONFIG:Debug>:/Od /Zi /D_DEBUG>>
)
```

### 🔹 특징
- 특정 타겟(`MyTarget`)에만 적용됨
- 기존 설정을 유지하면서 추가 옵션을 적용 가능

---

## 🔹 방법 3: `add_compile_options()` 사용 (전체 프로젝트 적용)
전체 프로젝트에 대해 **디버그 모드일 때만** 특정 옵션을 적용하는 방법입니다.

```cmake
add_compile_options(
    $<$<CXX_COMPILER_ID:MSVC>:$<$<CONFIG:Debug>:/Od /Zi /D_DEBUG>>
)
```

### 🔹 특징
- **프로젝트 내 모든 타겟**에 적용됨
- 일부 타겟에서 제외하려면 `target_compile_options()`가 더 적절함

📌 **이 방법은 모든 타겟에 적용되므로 신중히 사용해야 합니다.**

---

## 🔹 방법 4: `CMAKE_CXX_FLAGS_DEBUG` 직접 설정
`CMAKE_CXX_FLAGS_DEBUG` 변수를 사용하여 **Debug 모드에서 추가 옵션을 적용**할 수 있습니다.

```cmake
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi /D_DEBUG")
endif()
```

### 🔹 특징
- Debug 모드(`CMAKE_CXX_FLAGS_DEBUG`)에서 **모든 C++ 타겟**에 적용됨
- 기존 설정을 유지하면서 추가 옵션을 덧붙이는 방식

📌 **이 방법은 특정 타겟이 아닌 전체 프로젝트에 영향을 미칩니다.**

---

## 🔹 방법 5: `CMAKE_MSVC_DEBUG_INFORMATION_FORMAT` 사용
MSVC의 디버그 정보 형식을 설정할 수 있습니다.

```cmake
set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "Embedded") # 또는 "ProgramDatabase"
```

### 🔹 옵션 값
- `"Embedded"` → 개별 객체 파일에 디버그 정보 포함
- `"ProgramDatabase"` → `.pdb` 파일 생성

📌 **디버그 정보를 `.pdb` 파일로 저장하려면 `"ProgramDatabase"`를 사용해야 합니다.**

---

## 🔹 요약

| 방법 | 적용 대상 | 코드 예제 |
|------|----------|-----------|
| `target_compile_options()` | 특정 타겟 | `target_compile_options(MyTarget PRIVATE ...)` |
| `set_property()` | 특정 타겟 | `set_property(TARGET MyTarget PROPERTY COMPILE_OPTIONS ...)` |
| `add_compile_options()` | 전체 프로젝트 | `add_compile_options(...)` |
| `CMAKE_CXX_FLAGS_DEBUG` | 전체 프로젝트 | `set(CMAKE_CXX_FLAGS_DEBUG "...")` |
| `CMAKE_MSVC_DEBUG_INFORMATION_FORMAT` | 디버그 정보 관리 | `set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "...")` |

📌 **추천**
- **개별 타겟**에는 `target_compile_options()`를 사용
- **전체 프로젝트**에는 `add_compile_options()` 또는 `CMAKE_CXX_FLAGS_DEBUG`를 사용
- **디버그 정보 설정**에는 `CMAKE_MSVC_DEBUG_INFORMATION_FORMAT`을 사용

---

이제 프로젝트에 적절한 방법을 적용하여 MSVC의 **디버그 모드 컴파일 옵션**을 효과적으로 설정하세요! 🚀

