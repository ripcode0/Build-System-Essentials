##### LLVM Clang Basic On CLI (Command Line Interface)

* `타겟 트리플` 이란?
    * 3가지 혹은 4가지 조합의 구성 요소로 이루어진 문자열
    * `arch-vendor-os[-abi]` 형식
    * 예
        * `x86_64-w64-windows-gnu`
        * `x86_64-pc-windows-msvc`
        * `aarch64-unknown-linux-gnu`
* 설치된 `Clang` 의 `타겟 트리플` 확인
    ```cmd
    clang++ -v

    clang version 19.1.0
    Target: x86_64-pc-windows-msvc
    Thread model: posix
    InstalledDir: C:\Program Files\LLVM\bin
    ```
* 간단한 `hello wolrd` 컴파일 하기
    * `ABI` 가 `msvc` 나 `gnu` 일 경우 링커나 툴 오브젝트의 이름이 다름