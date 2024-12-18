# Prerequisites for Using VSCode with LLVM Clang

<img src="image/llvm.png" alt="LLVM Clang" width="200">

## Steps to Set Up LLVM with VSCode

#### 1. Download LLVM
1. Visit the official [LLVM releases page](https://releases.llvm.org/).
2. Select the latest release version of LLVM.
3. Download the installer (e.g., `LLVM-XX.X.X-win64.exe`).
4. Run the installer and during installation:
   - **Ensure you select the option to add `LLVM` to the system path** for the current user or all users.
   - Use the default installation path: `C:\Program Files\LLVM\`.

#### 2. Verify Installation
1. Open the Command Prompt (`cmd`).
2. Run the following command to check if `clang++` is accessible:
   ```bash
   clang++ --version
   ```
3. If the version information is displayed, the installation is successful.

#### 3. Set Up VSCode with CMake Tools (Optional)
1. Install the `CMake Tools` extension from the `VSCode` marketplace.
2. Open the command palette with `Ctrl + Shift + P`.
3. Select `CMake: Select a Kit`.
4. If `LLVM-Clang` appears in the list of kits, the setup is complete.

#### 4. Install Ninja for Build System Support (Optional)
1. Download the latest Ninja build from [Ninja Releases](https://github.com/ninja-build/ninja/releases).
2. `ninja.exe` and place the contents into the `C:\Program Files\LLVM\bin` directory where `LLVM` is installed.