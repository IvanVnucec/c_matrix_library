#!/bin/bash

# run cppchecker
echo "Run cppcheck and print results to stdout:"
cppcheck --quiet --enable=all --project=./builddir/compile_commands.json 2>&1
echo "Done cppcheck"
