# Setting Up LLVM Clang with VSCode

<img src="image/llvm.png" alt="LLVM Clang" width="200">

## [ Windows ]

#### 1. Install LLVM
* Visit the official [LLVM releases page](https://releases.llvm.org/).
* Select the latest release version of `LLVM`.
* Download the Windows Installer (e.g., `LLVM-XX.X.X-win64.exe`).
* During installation:
   - Make sure check the option to add `LLVM` to the system `PATH`
   - Use the default installation path `C:\Program Files\LLVM\`.

#### 2. Verify Installation
* Open the Command Prompt (`cmd`).
* Run the following command to check if `clang++` is accessible:
   ```bash
   clang++ --version
   ```
* If version info appears, `LLVM` is installed correctly

#### 3. Set Up VSCode with CMake Tools (Optional)
* Install the `CMake Tools` extension from the `VSCode` marketplace.
* Open the command palette with `Ctrl + Shift + P`.
* Select `CMake: Select a Kit`.
* If `LLVM-Clang` appears in the list of kits, the setup is complete.

#### 4. Install Ninja Build System (Optional)
##### (Several ways to install Ninja)
* Download the official latest `Ninja` : [Ninja Releases](https://github.com/ninja-build/ninja/releases)
   * `ninja.exe` and place the contents into the `PATH` environment variables directory
   * recommandation `PATH` environment variables 
   `C:\Program Files (x86)\Ninja`
   `C:\Program Files\LLVM\bin` 
* Python
   * The environment variable is set to 
   `C:\Users\<username>\AppData\Local\Programs\Python\Python313\Scripts`
   ```cmd
   python -m pip install ninja
   ```

* Installer : [Ninja-v1.12.1-Installer](https://github.com/ripcode0/Build-System-Essentials/raw/refs/heads/main/data/ninja-v1.12.1-installer.zip)
   * It is automatically installed to `C:\Program Files (x86)\Ninja` and the environment variable is registered.
* Verify Installation
   ```cmd
   ninja --version
   where ninja
   ```