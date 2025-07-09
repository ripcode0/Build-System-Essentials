#### Running an Executable on a System Without MinGW Installed

* If you built an executable `simple.exe` using `MinGW`, you must include the required `DLL` files to run it on a system that doesn't have MinGW installed.
* To check which `DLLs` `simple.exe` depends on, run:
```cmd
objdump -p simple.exe | findstr "DLL"
```
```yaml
        DLL Name: libgcc_s_seh-1.dll
        DLL Name: KERNEL32.dll
        DLL Name: api-ms-win-crt-convert-l1-1-0.dll
        ...
        DLL Name: libstdc++-6.dll
```
* `KERNEL32.dll`, `api-ms-win-crt-*.dll`
    - These are built into **Windows 10 and later**, so you do not need to copy them.
* `libgcc_s_seh-1.dll` `libstdc++-6.dll` 
    - You **must** copy these to the same folder as the executable.
* Include `libwinpthread-1.dll` as well if needed.
```cmd
build/
├── simple.exe
├── libgcc_s_seh-1.dll
├── libstdc++-6.dll
├── libwinpthread-1.dll (if needed)
```

[Back](../../README.md)