# Setting Up MSYS2 MinGW with VSCode

<img src="image/msys2.png" alt="MSYS2 Logo" width="200">

## [ Windows ]

#### 1. Install MSYS2
* Downloading Official installer [msys2-x86_64-installer.exe](https://github.com/msys2/msys2-installer/releases/download/2025-06-22/msys2-x86_64-20250622.exe)
* During installation:
   - Use the default installation path `C:\msys64`.
   - in Finished section check the "Run MSYS2 now."
* MSYS2 turminal is ready
```bash
$ pacman -S mingw-w64-ucrt-x86_64-gcc
```

#### 2. Add the Environment Variables
* Press `Win + R` to open the Run dialog.
* Type the following command with double quotes and press Enter:
   ```bash
   SystemPropertiesAdvanced.exe
   ```
* This will directly open the Advanced tab of the System Properties window, where you can click the `Environment Variables...` button.

    - Add `Path` `C:\msys64\ucrt64\bin`
* Verify Installation
    ```cmd
    where gcc
    gcc --version
    ```
    
[Back To Main](../README.md)