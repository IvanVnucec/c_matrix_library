#!/bin/bash

# load constants
. ./scripts/constants.env

# run cppchecker
echo "Run cppcheck and print results to stdout:"
docker exec $IMAGE_NAME cppcheck --quiet --enable=all --project=./builddir/compile_commands.json 2>&1
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }
echo "Done cppcheck"

exit 0
