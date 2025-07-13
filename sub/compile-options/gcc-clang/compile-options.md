## GCC / Clang Compiler Options Overview

---

#### Basic Compilation Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-c` | Compile only, do not link | Generates `.o` (object) file |
| `-o <filename>` | Specify output file name | Default is `a.out` or `a.exe` |
| `-v` | Verbose output | Shows internal toolchain commands |
| `--version` | Print compiler version info | Also displays target triple |
| `--help` | List all available options | `--help-hidden` for Clang internal flags |

---

#### Optimization Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-O0` | No optimization | Best for debugging |
| `-O1` | Basic optimization | Fast compilation |
| `-O2` | General-purpose optimization | Widely used in production |
| `-O3` | Aggressive optimization | Increases performance and binary size |
| `-Os` | Optimize for size | Embedded systems / limited space |
| `-Oz` | Clang-only: maximize size reduction | Smaller than `-Os` |
| `-Ofast` | `-O3` + unsafe optimizations | May break standards compliance |
| `-march=native` | Optimize for current CPU | Binary might not run on other systems |
| `-mtune=<cpu>` | Tune performance for given CPU | Maintains binary compatibility |
| `-flto` | Enable Link Time Optimization | Cross-translation-unit optimization |

---

#### Debugging / Analysis Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-g`, `-g3`, `-ggdb` | Include debug symbols | `-g3` includes macros |
| `-pg` | Add gprof profiling info | Use with `gprof` |
| `-fno-omit-frame-pointer` | Retain frame pointer | Required for some profilers |
| `-fsanitize=address` | Detect memory errors | Use-after-free, buffer overflows, etc. |
| `-fsanitize=undefined` | Detect undefined behavior | e.g., invalid shifts, null derefs |
| `-fsanitize=thread` | Detect data races | For multithreaded programs |
| `-fstack-protector[-strong|-all]` | Add stack canaries | Mitigates stack buffer overflows |

---

#### Language / Standard Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-std=c11`, `-std=c++20` | Specify language standard | Clang supports newest standards |
| `-ansi` | Enable ANSI mode | Equivalent to C89 / C++98 |
| `-fno-exceptions` | Disable C++ exceptions | Reduces binary size |
| `-fno-rtti` | Disable RTTI | For lightweight C++ builds |
| `-pedantic` | Warn on non-standard code | Enforces strict standard compliance |
| `-fms-extensions` | Enable MSVC compatibility | Useful for Windows ports |

---

#### Preprocessor Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-E` | Run preprocessor only | Output sent to stdout |
| `-I<path>` | Add include search path | Accepts relative or absolute path |
| `-isystem <path>` | Add system include path | Silences `-Wall` warnings |
| `-Dmacro=value` | Define macro | Used in conditional compilation |
| `-Umacro` | Undefine macro | Cancels predefined values |
| `-P` | Suppress `#line` output | For clean preprocessed output |

---

#### Architecture / Target / Platform Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-m32`, `-m64` | Generate 32/64-bit binaries | Depends on toolchain support |
| `--target=<triple>` | Set target triple | e.g., `x86_64-w64-windows-gnu` |
| `-fPIC` | Position Independent Code | Required for shared libraries |
| `-fPIE`, `-pie` | Generate Position Independent Executables | Improves security (ASLR) |

---

#### Diagnostics / Output Formatting

| Option | Description | Notes |
|--------|-------------|-------|
| `-fcolor-diagnostics` | Enable color diagnostics | Default in Clang |
| `-fdiagnostics-color=always` | Force color output in GCC | Accepts `never`, `auto`, `always` |
| `-fsyntax-only` | Only check syntax, no compilation | Speeds up static analysis |

---

#### Static Analysis (Clang Only)

| Option | Description | Notes |
|--------|-------------|-------|
| `--analyze` | Run Clang Static Analyzer | Detects common bugs |
| `-Xclang` | Pass internal options to Clang | Advanced usage |
| `-Rpass=<pass>` | Report successful optimizations | e.g., `loop-vectorize`, `inline` |
| `-print-target-triple` | Print current target triple | Useful for debugging cross-compilation |

---

#### Basic Warning Options

| Option | Description | Notes |
|--------|-------------|-------|
| `-Wall` | Enable most common warnings | Recommended |
| `-Wextra` | Enable extra warnings | Complements `-Wall` |
| `-Werror` | Treat warnings as errors | Strict mode for CI/CD |
| `-Wno-<name>` | Disable specific warning | e.g., `-Wno-unused-variable` |
| `-W<name>` | Enable specific warning | e.g., `-Wshadow` |
| `-w` | Disable all warnings | Not recommended |
| `-pedantic` | Warn on all standard violations | Strict standard conformance |
| `-pedantic-errors` | Treat standard violations as errors | Similar to `-Werror` |

---

#### Commonly Useful Warning Options

| Option | Description |
|--------|-------------|
| `-Wunused-variable` | Warn about unused variables |
| `-Wunused-parameter` | Warn about unused function arguments |
| `-Wshadow` | Warn about variable shadowing |
| `-Wsign-compare` | Warn about signed/unsigned comparisons |
| `-Wconversion` | Warn about implicit type conversions |
| `-Wfloat-equal` | Warn about direct float comparisons |
| `-Wformat` | Warn about incorrect printf/scanf formats |
| `-Wnull-dereference` | Warn about null pointer usage |
| `-Wswitch` | Warn on incomplete switch statements |
| `-Wswitch-enum` | Warn if enum values not fully handled |
| `-Wreorder` | Warn on C++ member initializer order |
| `-Wimplicit-fallthrough` | Warn on case fallthrough |
| `-Wuninitialized` | Warn about uninitialized variables |
| `-Wreturn-type` | Warn if return types are missing |
| `-Wmissing-braces` | Warn on missing initializer braces |
| `-Wcast-align` | Warn on potentially unsafe cast alignments |

---

#### Example: Suppress a Specific Warning

```bash
clang++ main.cpp -Wall -Wextra -Wno-unused-parameter
```

[Back To Main](../../../README.md)