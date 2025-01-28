# `__declspec` 사용법

## 개요
`__declspec`는 Microsoft Visual C++(MSVC) 컴파일러에서 제공하는 확장 기능으로, 변수, 함수, 클래스 등에 특정한 속성을 지정할 때 사용됩니다.

---

## 기본 문법

```cpp
__declspec(attribute) 선언문;
```
또는

```cpp
attribute 선언문 __declspec(attribute);
```

---

## 주요 속성(attribute)

### 1. `dllexport` / `dllimport`

- **`dllexport`**: 동적 라이브러리(DLL)에서 함수를 내보낼 때 사용
- **`dllimport`**: 동적 라이브러리(DLL)에서 함수를 가져올 때 사용

#### 예제

**DLL 헤더 파일 (mydll.h)**
```cpp
#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif

DLL_EXPORT void HelloWorld();
```

**DLL 구현 파일 (mydll.cpp)**
```cpp
#include "mydll.h"
#include <iostream>

void HelloWorld() {
    std::cout << "Hello from DLL!" << std::endl;
}
```

**사용 예제 (main.cpp)**
```cpp
#include "mydll.h"

int main() {
    HelloWorld();
    return 0;
}
```

---

### 2. `naked`

- 함수 프로로그/에필로그 코드 없이 어셈블리 코드를 직접 작성할 때 사용

#### 예제

```cpp
__declspec(naked) void NakedFunction() {
    __asm {
        mov eax, 1
        ret
    }
}
```

---

### 3. `align(n)`

- 특정한 메모리 정렬을 지정할 때 사용
- `n`은 정렬 크기(예: 16, 32 등)

#### 예제

```cpp
struct __declspec(align(16)) AlignedStruct {
    int a;
    float b;
};
```

---

### 4. `thread`

- 스레드 로컬 변수를 선언할 때 사용

#### 예제

```cpp
__declspec(thread) int thread_local_var;
```

---

### 5. `selectany`

- 여러 개의 개체가 정의될 경우 중복 정의를 방지

#### 예제

```cpp
__declspec(selectany) int globalVar = 42;
```

---

### 6. `novtable`

- 가상 함수 테이블(vtable)을 생성하지 않도록 최적화할 때 사용

#### 예제

```cpp
class __declspec(novtable) Base {
public:
    virtual void foo() = 0;
};
```

---

### 7. `deprecated`

- 사용하지 않도록 경고를 표시

#### 예제

```cpp
__declspec(deprecated) void OldFunction();
```

---

### 8. `noinline`

- 컴파일러가 해당 함수를 인라인 확장하지 않도록 강제 지정

#### 예제

```cpp
__declspec(noinline) void NoInlineFunction() {
    std::cout << "This function will not be inlined." << std::endl;
}
```

---

### 9. `allocate(section_name)`

- 특정한 메모리 섹션에 변수를 할당할 때 사용

#### 예제

```cpp
#pragma section("my_section", read, write)
__declspec(allocate("my_section")) int myData = 100;
```

---

### 10. `uuid("GUID")`

- 클래스에 전역 고유 식별자(GUID)를 할당

#### 예제

```cpp
#include <objbase.h>

class __declspec(uuid("12345678-1234-1234-1234-1234567890AB")) MyClass {
};
```

---

## 결론

`__declspec`는 Windows 환경에서 다양한 최적화 및 메모리 관리, DLL 내보내기/가져오기 등에 유용하게 사용됩니다. 각 속성의 목적을 이해하고 적절한 상황에서 활용하면 보다 최적화된 C++ 프로그램을 작성할 수 있습니다.

