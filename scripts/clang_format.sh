#!/bin/bash

# Clang-format
echo "Clang-format code formatting."
clang-format -i --verbose --style=file src/*.c
clang-format -i --verbose --style=file src/*.h
clang-format -i --verbose --style=file test/*.c
clang-format -i --verbose --style=file test/*.h
