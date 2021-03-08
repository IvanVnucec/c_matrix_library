#!/bin/bash

# load constants
. ./scripts/constants.env

# Clang-format
echo "Clang-format code formatting."
docker exec $IMAGE_NAME clang-format-11 -i --verbose --style=file src/*.c
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME clang-format-11 -i --verbose --style=file src/*.h
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME clang-format-11 -i --verbose --style=file test/*.c
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME clang-format-11 -i --verbose --style=file test/*.h
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
