# GCC / Clang Compiler Options Overview

| Flag | Description | Notes |
|--------|-------------|-------|
| **Basic Compilation Options** |||
| `-c` | Compile only, do not link | Generates `.o` file |
| `-o <filename>` | Specify output file name | Default: `a.out` / `a.exe` |
| `-v` | Verbose output | Shows internal toolchain commands |
| `--version` | Print compiler version info | Includes target triple |
| `--help` | List options | `--help-hidden` for Clang internals |
| **Optimization Options** |||
| `-O0` | No optimization | Best for debugging |
| `-O1` | Basic optimization | Fast compile time |
| `-O2` | General optimization | Common in production |
| `-O3` | Aggressive optimization | Larger, faster binaries |
| `-Os` | Optimize for size | Ideal for embedded |
| `-Oz` | Clang-only: maximize size reduction | Smaller than `-Os` |
| `-Ofast` | `-O3` + unsafe optimizations | May break standard compliance |
| `-march=native` | Optimize for current CPU | Not portable |
| `-mtune=<cpu>` | Tune for CPU, keep compatibility | Performance hint |
| `-flto` | Link Time Optimization | Cross-TU optimization |
| ** Debugging / Analysis Options** |||
| `-g`, `-g3`, `-ggdb` | Include debug symbols | `-g3` includes macros |
| `-pg` | gprof profiling info | Used with `gprof` |
| `-fno-omit-frame-pointer` | Retain frame pointer | Needed by some profilers |
| `-fsanitize=address` | Detect memory errors | e.g., use-after-free |
| `-fsanitize=undefined` | Detect UB | null deref, etc. |
| `-fsanitize=thread` | Detect data races | For multithreading |
| `-fstack-protector`, `-strong`, `-all` | Stack canaries | Overflow protection |
| **Language / Standard Options** |||
| `-std=c11`, `-std=c++20` | Specify standard | Clang has latest |
| `-ansi` | Enable ANSI mode | C89 / C++98 |
| `-fno-exceptions` | Disable C++ exceptions | Smaller binaries |
| `-fno-rtti` | Disable RTTI | Lightweight builds |
| `-pedantic` | Warn on non-standard code | Strict conformance |
| `-fms-extensions` | Enable MSVC compatibility | Windows porting |
| **Preprocessor Options** |||
| `-E` | Run preprocessor only | Output to stdout |
| `-I<path>` | Add include path | Relative/absolute |
| `-isystem <path>` | Add system include path | Silences `-Wall` |
| `-Dmacro=value` | Define macro | Conditional builds |
| `-Umacro` | Undefine macro | Cancel predefined |
| `-P` | Suppress `#line` in output | Clean preprocessor output |
| **Architecture / Target / Platform Options** |||
| `-m32`, `-m64` | Generate 32/64-bit code | Depends on toolchain |
| `--target=<triple>` | Set target triple | e.g., `x86_64-linux-gnu` |
| `-fPIC` | Position Independent Code | Required for shared libs |
| `-fPIE`, `-pie` | PIE executables | Enables ASLR |
| **Diagnostics / Formatting Options** |||
| `-fcolor-diagnostics` | Enable color output | Default in Clang |
| `-fdiagnostics-color=always` | Force color (GCC) | Use with `auto`, `never` |
| `-fsyntax-only` | Check syntax only | No output |
| **Static Analysis (Clang Only)** |||
| `--analyze` | Clang static analyzer | Bug detection |
| `-Xclang` | Pass Clang internal options | Advanced |
| `-Rpass=<pass>` | Report optimizations | e.g., `inline` |
| `-print-target-triple` | Show current target triple | Useful for debugging |
| **Basic Warning Options** |||
| `-Wall` | Common warnings | Default set |
| `-Wextra` | Extra warnings | Stricter code |
| `-Werror` | Warnings = errors | Use in CI/CD |
| `-Wno-<name>` | Disable specific warning | e.g., `-Wno-unused` |
| `-W<name>` | Enable specific warning | e.g., `-Wshadow` |
| `-w` | Disable all warnings | Not recommended |
| `-pedantic` | Warn on standard violations | Same as above |
| `-pedantic-errors` | Violations = errors | Like `-Werror` |
| **Common Specific Warning Options** |||
| `-Wunused-variable` | Warn on unused variables |  |
| `-Wunused-parameter` | Warn on unused parameters |  |
| `-Wshadow` | Warn on shadowed variables |  |
| `-Wsign-compare` | Signed/unsigned comparison |  |
| `-Wconversion` | Implicit type conversions |  |
| `-Wfloat-equal` | Float equality | Risky comparison |
| `-Wformat` | Printf/scanf format issues | Format string bugs |
| `-Wnull-dereference` | Null pointer usage | Clang only |
| `-Wswitch` | Incomplete switch | Not all cases handled |
| `-Wswitch-enum` | All enum values handled? |  |
| `-Wreorder` | Member init order mismatch | C++ only |
| `-Wimplicit-fallthrough` | Case fallthrough | Missing comment |
| `-Wuninitialized` | Uninitialized variables | Runtime bugs |
| `-Wreturn-type` | Missing return value | Common bug |
| `-Wmissing-braces` | Init braces | Struct/array init |
| `-Wcast-align` | Cast alignment risks |  |

---

#### Example: Suppress a Specific Warning

```bash
clang++ main.cpp -Wall -Wextra -Wno-unused-parameter
```