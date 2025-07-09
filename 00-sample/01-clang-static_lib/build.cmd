@echo off
setlocal

::set variables
set cxx=clang++
set flags=-std=c++20
set build_dir=build

if not exist %build_dir% mkdir %build_dir%

echo [CLI Build] compile libraries
%cxx% %flags% -c src/engine.cpp -o %build_dir%/engine.obj

echo [CLI Build] creating static lib
llvm-lib %build_dir%/engine.obj /OUT:"%build_dir%/engine.lib"

echo [CLI Build] build excutable ...
%cxx% src/main.cpp -L%build_dir% -lengine -o %build_dir%/simple.exe
