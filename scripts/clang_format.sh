#!/bin/bash

# Clang-format
echo "Clang-format code formatting."
clang-format -i --style=file src/*.c
clang-format -i --style=file src/*.h
clang-format -i --style=file test/*.c
clang-format -i --style=file test/*.h
