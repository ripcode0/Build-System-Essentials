### CMake Toolchain

#### What is a Toolchain File?

In `CMake`, a *toolchain file* is a configuration script that defines the build environment ahead of time.  
It specifies the **compiler path**, **linker**, **system root**, and **environment variables**.  
This enables you to build using custom toolsets like `LLVM`, `MinGW` etc or other toolchains instead of relying on the system default.

#### Manually Using a Toolchain File

You can manually specify a toolchain file when configuring your project:

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=<path>/xxx-toolchain.cmake
```
