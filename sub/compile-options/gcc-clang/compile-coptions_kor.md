# GCC / Clang 컴파일 옵션 
---
#### 기본 컴파일 옵션

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-c` | 컴파일만 수행하고 링크는 하지 않음 | `.o`(오브젝트) 파일 생성 |
| `-o <파일명>` | 출력 파일 이름 지정 | 기본값: `a.out` 또는 `a.exe` |
| `-v` | 컴파일 진행 로그 출력 | 내부 명령어 확인 가능 |
| `--version` | 컴파일러 버전 정보 출력 | 버전 및 트리플 확인용 |
| `--help` | 사용 가능한 옵션 목록 출력 | Clang은 `--help-hidden`도 있음 |

---

#### 최적화 옵션

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-O0` | 최적화 비활성화 | 디버깅에 적합 |
| `-O1` | 기본적인 최적화 | 컴파일 속도 빠름 |
| `-O2` | 일반적인 최적화 | 실무에서 가장 널리 사용 |
| `-O3` | 고급 최적화 | 실행 속도 향상, 바이너리 커질 수 있음 |
| `-Os` | 코드 크기 최적화 | 임베디드/저용량 목적 |
| `-Oz` | Clang 전용, 더 aggressive한 크기 최적화 | `-Os`보다 작은 출력물 |
| `-Ofast` | `-O3` + 정확성 희생 | 표준 위반 가능성 있음 |
| `-march=native` | 현재 CPU에 최적화 | 타 머신 실행 시 오류 가능 |
| `-mtune=<cpu>` | 실행 성능을 특정 CPU에 맞춤 | 바이너리 호환 유지 |
| `-flto` | Link Time Optimization | 전체 프로그램 최적화 수행 |

---

#### 디버깅/분석 옵션

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-g`, `-g3`, `-ggdb` | 디버깅 심볼 포함 | `-g3`은 매크로 정보 포함 |
| `-pg` | gprof용 프로파일링 정보 생성 | `gprof` 사용 시 필요 |
| `-fno-omit-frame-pointer` | 스택 추적 가능 | perf, sanitizer, gdb 등에 유용 |
| `-fsanitize=address` | 메모리 오류 검출 | 런타임에 메모리 접근 검사 |
| `-fsanitize=undefined` | 정의되지 않은 동작 검사 | shift overflow, null deref 등 |
| `-fsanitize=thread` | 데이터 레이스 탐지 | 병렬 처리 환경 필수 도구 |
| `-fstack-protector[-strong|-all]` | 스택 보호 삽입 | 보안 취약점 완화 |

---

#### 표준/언어 관련 옵션

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-std=c11`, `-std=c++20` | 언어 표준 지정 | 최신 C/C++ 버전 가능 |
| `-ansi` | C89/C++98로 제한 | 구식 시스템 호환 목적 |
| `-fno-exceptions` | 예외 기능 제거 (C++) | 바이너리 크기 감소 |
| `-fno-rtti` | RTTI 제거 (C++) | 객체 타입 정보 제거 |
| `-pedantic` | 표준 위반시 경고 | 엄격한 표준 준수 검사 |
| `-fms-extensions` | MSVC 확장 허용 | Windows 이식 시 사용 |

---

#### 전처리 관련 옵션

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-E` | 전처리만 수행 | 출력은 stdout |
| `-I<경로>` | 헤더 검색 경로 지정 | 상대/절대 경로 모두 가능 |
| `-isystem <경로>` | 시스템 헤더로 간주 | `-Wall` 경고 무시됨 |
| `-D<매크로>=값` | 매크로 정의 | 컴파일 시 조건부 분기 처리 |
| `-U<매크로>` | 매크로 제거 | 기존 정의 무효화 |
| `-P` | `#line` 제거 | 전처리 결과 정리용 |

---

#### 아키텍처/타겟/플랫폼

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-m32`, `-m64` | 32/64비트 바이너리 생성 | 타겟 아키텍처 설정 |
| `--target=<트리플>` | Clang 크로스 컴파일용 | 예: `x86_64-w64-windows-gnu` |
| `-fPIC` | 포인터 독립 코드 | 공유 라이브러리용 필수 |
| `-fPIE`, `-pie` | PIE(위치 독립 실행 파일) 생성 | 보안용 |

---

#### 출력 / 진단 관련

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-fcolor-diagnostics` | 컬러 출력 (Clang 기본값) | 오류/경고 하이라이트 |
| `-fdiagnostics-color=always` | GCC에서도 컬러 출력 | `never`, `auto` 등도 가능 |
| `-fsyntax-only` | 문법만 검사 | 빌드 시간 줄이기용 |

---

#### 정적 분석 (Clang 전용)

| 옵션 | 설명 | 비고 |
|------|------|------|
| `--analyze` | 정적 분석 수행 | `clang-analyzer` |
| `-Xclang` | 내부 Clang 옵션 전달 | 고급 사용자용 |
| `-Rpass=...` | 최적화 로그 출력 | `inline`, `loop-vectorize` 등 |
| `-print-target-triple` | 컴파일 타겟 트리플 출력 | 크로스 컴파일 디버그용 |

---

#### 기본 경고 옵션

| 옵션 | 설명 | 비고 |
|------|------|------|
| `-Wall` | 일반적인 경고 대부분 활성화 | 기본적으로 거의 항상 사용 |
| `-Wextra` | 추가 경고 활성화 | `-Wall`에 포함되지 않은 항목까지 |
| `-Werror` | 모든 경고를 컴파일 오류로 처리 | CI 환경 등에서 유용 |
| `-Wno-<name>` | 특정 경고 비활성화 | 예: `-Wno-unused-variable` |
| `-W<name>` | 특정 경고만 개별 활성화 | 예: `-Wshadow` |
| `-w` | 모든 경고 비활성화 | 비추천: 디버깅 어려워짐 |
| `-pedantic` | 표준 위반에 대해 경고 | 엄격한 C/C++ 표준 적용 |
| `-pedantic-errors` | 표준 위반 시 에러 처리 | `-Werror`와 함께 사용 가능 |

---

#### 유용한 경고 옵션 모음

| 옵션 | 설명 |
|------|------|
| `-Wunused-variable` | 사용되지 않은 변수 경고 |
| `-Wunused-parameter` | 사용되지 않은 함수 인자 경고 |
| `-Wshadow` | 변수 그림자 경고 (지역 변수 vs 멤버 변수 등) |
| `-Wsign-compare` | 부호 있는/없는 타입 비교 경고 |
| `-Wconversion` | 암묵적 형변환 경고 |
| `-Wfloat-equal` | 부동소수점 직접 비교 경고 |
| `-Wformat` | `printf`, `scanf` 포맷 오류 |
| `-Wnull-dereference` | 널 포인터 역참조 경고 |
| `-Wswitch` | switch 문에 빠진 case 경고 |
| `-Wswitch-enum` | enum switch에 빠진 항목 경고 |
| `-Wreorder` | C++ 멤버 초기화 순서 경고 |
| `-Wimplicit-fallthrough` | switch/case fallthrough 경고 |
| `-Wuninitialized` | 초기화되지 않은 변수 사용 경고 |
| `-Wreturn-type` | 함수 리턴 타입 오류 경고 |
| `-Wmissing-braces` | 중첩 초기화 괄호 누락 경고 |
| `-Wcast-align` | 잘못된 정렬 변환 경고 |

#### 특정 경고 무시
```bash
clang++ main.cpp -Wall -Wextra -Wno-unused-parameter
```