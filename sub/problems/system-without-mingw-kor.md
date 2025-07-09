#### MinGW가 설치되지 않은 PC에서 실행 파일 실행하기

* MinGW로 빌드한 실행 파일(simple.exe)은 다른 PC에서 실행하려면 필요한 DLL 파일도 함께 있어야 합니다.
* simple.exe 에 사용된 DLL 리스트 추출
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
    - Windows 10 이상에서는 기본 제공, 따로 복사할 필요 없음
* `libgcc_s_seh-1.dll` `libstdc++-6.dll` 
    - 반드시 실행 파일과 같은 폴더에 복사해서 배포
* 필요한 경우 `libwinpthread-1.dll` 도 함께 포함
```cmd
build/
├── simple.exe
├── libgcc_s_seh-1.dll
├── libstdc++-6.dll
├── libwinpthread-1.dll (필요시)
```