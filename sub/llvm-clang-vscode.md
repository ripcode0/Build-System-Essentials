# Setting Up LLVM Clang with VSCode

<img src="image/llvm.png" alt="LLVM Clang" width="200">

## Windows

#### 1. Install LLVM
1. Visit the official [LLVM releases page](https://releases.llvm.org/).
2. Select the latest release version of LLVM.
3. Download the Windows Installer (e.g., `LLVM-XX.X.X-win64.exe`).
4. During installation:
   - Make sure check the option to add `LLVM` to the system `PATH`
   - Use the default installation path `C:\Program Files\LLVM\`.

#### 2. Verify Installation
1. Open the Command Prompt (`cmd`).
2. Run the following command to check if `clang++` is accessible:
   ```bash
   clang++ --version
   ```
3. If version info appears, LLVM is installed correctly

#### 3. Set Up VSCode with CMake Tools (Optional)
1. Install the `CMake Tools` extension from the `VSCode` marketplace.
2. Open the command palette with `Ctrl + Shift + P`.
3. Select `CMake: Select a Kit`.
4. If `LLVM-Clang` appears in the list of kits, the setup is complete.

#### 4. Install Ninja Build System (Optional)
1. Download the latest Ninja build : [Ninja Releases](https://github.com/ninja-build/ninja/releases). or Run the Installer : [Ninja Installer](../data/ninja-v1.12.1-installer.exe)
2. `ninja.exe` and place the contents into the `C:\Program Files\LLVM\bin` directory where `LLVM` is installed.
