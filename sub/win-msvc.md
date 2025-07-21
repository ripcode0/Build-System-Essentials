# Prerequisites for Using VSCode with Microsoft MSVC

<img src="image/msvc.png" alt="msvc logo" width="200">

## Steps to Set Up MSVC with VSCode
* If `visual studio` is installed already, you can skip the installation step
---
#### 1. Download MSVC
1. Visit the official [visual studio releases page](https://visualstudio.microsoft.com/ko/downloads/).
2. Select the latest release version of visual studio.
3. Download the installer (e.g., `VisualStudioSetup.exe`).
---
#### Use The **Kits** On VSCode
* the finding visuall studio development command prompt
```cmd
where /R "C:\Program Files\Microsoft Visual Studio" VsDevCmd.bat
```
* apear the `VsDevCmd.bat` path
```
C:\Program Files\Microsoft Visual Studio\...\Common7\Tools\VsDevCmd.bat
```

---
#### 2. Verify Installation
1. in the vscode ctrl + shift + p open the pallete
2. choose the c/c++ `Open the Workspace setting`
2. Add the following configuration to your `setting.json` file :
```json
{
    //Adjust the settings to match the installed VS version
    //Professional|Community|Enterpise
    "terminal.integrated.profiles.windows": {
    "develop-vs2022-cmd" : {
        "path": "C:\\Windows\\System32\\cmd.exe",
        "args": [
             "/k",
             "C:\\Program Files\\Microsoft Visual Studio\\2022\\Professional\\Common7\\Tools\\VsDevCmd.bat"
        ]
        }
    }
}
```
4. From now on, you can use the new command prompt 'develop-vs2022-cmd' in the terminal window.
5. checkout msvc compiler
```bash
where cl.exe    //to get locate cl.exe
cl.exe          //to get version
```
---
#### 3. Set Up VSCode with CMake Tools (Optional)
1. Install the `CMake Tools` extension from the `VSCode` marketplace.
2. Open the command palette with `Ctrl + Shift + P`.
3. Choose a kit that includes the MSVC toolset (e.g., Visual Studio ...).
4. If the kit is detected, your setup is complete.

[Back To Main](../README.md)