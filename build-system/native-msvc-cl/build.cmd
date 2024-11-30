@echo off


if not exist bin (
    echo "create bin folder"
    mkdir bin
)


if not exist bin\obj (
    echo "create bin/obj folder"
    mkdir bin\obj
)