# 3.3. 워크플로우 (Workflow)

CMake에는 개발자의 워크플로우를 크게 단순화할 수 있는 기능이 있다. 네이티브 빌드 도구는 CMake 소스의 변경 사항을 감지하고 자동으로 구성(configure) 단계를 다시 실행할 수 있다. 즉, 명령줄에서 `cmake -H. -B_builds`를 한 번만 실행하면 이후 `CMakeLists.txt`를 수정해도 다시 `configure`를 실행할 필요 없이 `cmake --build`만 사용하면 된다.

## 3.3.1. Makefile 예제 (Makefile example)

다음은 `message`를 출력하는 간단한 `CMakeLists.txt` 예제이다.

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
project(foo)

add_executable(foo foo.cpp)

message("Processing CMakeLists.txt")
```

### Makefile 생성
```sh
[minimal-with-message]> cmake -H. -B_builds
```
출력 예제:
```sh
-- The C compiler identification is GNU 4.8.4
-- The CXX compiler identification is GNU 4.8.4
...
Processing CMakeLists.txt
-- Configuring done
-- Generating done
-- Build files have been written to: /.../minimal-with-message/_builds
```

### 빌드 실행
```sh
[minimal-with-message]> cmake --build _builds
```
출력 예제:
```sh
Scanning dependencies of target foo
[ 50%] Building CXX object CMakeFiles/foo.dir/foo.cpp.o
[100%] Linking CXX executable foo
[100%] Built target foo
```

### 변경 사항 감지
#### 코드 수정 후 빌드
```sh
[minimal-with-message]> touch foo.cpp
[minimal-with-message]> cmake --build _builds
```
`Make`는 실행 파일이 최신이 아님을 감지하고 다시 빌드한다.

#### `CMakeLists.txt` 수정 후 빌드
```sh
[minimal-with-message]> touch CMakeLists.txt
[minimal-with-message]> cmake --build _builds
```
출력 예제:
```sh
Processing CMakeLists.txt
-- Configuring done
-- Generating done
-- Build files have been written to: /.../minimal-with-message/_builds
[100%] Built target foo
```
`CMakeLists.txt`가 다시 분석되고 새로운 Makefile이 생성되지만, 빌드 방식이 변경되지 않았기 때문에 컴파일/링크 단계는 수행되지 않는다.

#### `CMakeLists.txt` 및 코드 동시 수정 후 빌드
```sh
[minimal-with-message]> touch CMakeLists.txt foo.cpp
[minimal-with-message]> cmake --build _builds
```
출력 예제:
```sh
Processing CMakeLists.txt
-- Configuring done
-- Generating done
-- Build files have been written to: /.../minimal-with-message/_builds
Scanning dependencies of target foo
[ 50%] Building CXX object CMakeFiles/foo.dir/foo.cpp.o
[100%] Linking CXX executable foo
[100%] Built target foo
```

## 3.3.2. Visual Studio 예제 (Visual Studio example)

다른 생성기에서도 동일한 동작을 한다. 예를 들어, `CMakeLists.txt`를 변경하고 Visual Studio에서 `foo` 타겟을 실행하면 IDE가 프로젝트 업데이트를 감지하고 "Reload All" 버튼을 눌러 새로운 구성을 로드할 수 있다.

![Project Reload](../_images/01-reconfigure.png)

![Update Notification](../_images/02-notify.png)

## 3.3.3. UML 활동 다이어그램 (UML activity diagram)

아래는 위의 워크플로우를 설명하는 UML 활동 다이어그램이다.

![Workflow Diagram](../_images/workflow.png)

## 3.3.4. 의심스러운 동작 (Suspicious behavior)

만약 한 번의 `configure` 과정으로 빌드가 이루어지지 않는다면, 잘못 작성된 CMake 코드일 가능성이 있다. 특히 `cmake -H. -B_builds`를 두 번 실행해야 하거나 `cmake --build _builds`가 CMake 코드 변경 사항을 감지하지 못하는 경우, CMake 설정을 다시 확인하는 것이 좋다.
