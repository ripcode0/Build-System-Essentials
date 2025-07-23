### CMake Kits

**CMake Kits** are metadata used by the `CMake Tools` extension in `VSCode`, enabling users to easily switch and manage compiler and build environments. This is especially useful when working with multiple toolchains and switching between projects.

- `cmake-tools-kits.json`: Global user-level configuration
- `.vscode/CMake-Kits.json`: Project-level local configuration

#### How to Use Kits

- Open Command Palette

  - Press `Ctrl + Shift + P` to open the **Command Palette**.

- Select a Kit

  - Type `CMake: Select a Kit` to show the available toolchains.
  - If `CMakePresets` is enabled, the Kit menu will be disabled. You can disable it with the following setting in `.vscode/settings.json`:

  ```json
  "cmake.useCMakePresets": "never"
  ```

- Choose a Toolchain

  - Select the desired compiler environment (e.g., Visual Studio, Clang, GCC).

#### Kit Detection Method

CMake Tools automatically scans for installed compilers and toolchains using the following commands:

- `which` (for Unix-based systems)
- `where` (for Windows)
- `vswhere` (for detecting Visual Studio installations)

This allows automatic detection and setup of Kits suitable for various platforms and compiler environments.

#### Global Kit Configuration File (cmake-tools-kits.json)

CMake Tools supports both global and local Kits configuration.

- To edit the **global kit configuration file**, open the Command Palette (`Ctrl + Shift + P`) and run `CMake: Edit User-Local CMake Kits`.

- Default paths for the global configuration file by platform:

```
[MacOS]     /Users/<user name>/.local/share/CMakeTools/cmake-tools-kits.json
[Windows]   C:\Users\<user name>\AppData\Local\CMakeTools\cmake-tools-kits.json
[Ubuntu]    /home/<user name>/.local/share/CMakeTools/cmake-tools-kits.json
```

Example:

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
    }
]
```

#### Project Local Kits Configuration (cmake-kits.json)

- You can define local Kits in the `.vscode/cmake-kits.json` file.
- However, changes are not applied immediately. Follow these steps:
  - Restart `VSCode`
  - Run `CMake: Select a Kit`
  - Rescan Kits to recognize the new entry

#### Creating Local Kits

##### Example: MSVC

1. Find the path to `vcvars64.bat` using:

```cmd
where /R "C:\Program Files\Microsoft Visual Studio" vcvars64.bat
```

2. Register it in `.vscode/cmake-kits.json` like this:

```json
[
    {
        "name": "msvc-cl",
        "compilers": {
            "C": "cl.exe",
            "CXX": "cl.exe"
        },
        "environmentSetupScript": "C:/Program Files/Microsoft Visual Studio/2022/Professional/VC/Auxiliary/Build/vcvars64.bat"
    }
]
```

- `environmentSetupScript` is a script that initializes Visual Studio's environment variables.
- You must restart VSCode and reselect the Kit after configuring this to apply changes.

