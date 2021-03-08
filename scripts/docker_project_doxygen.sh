#!/bin/bash

# load constants
. ./scripts/constants.env

docker exec $IMAGE_NAME mkdir docs
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME mkdir docs/Doxygen
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME doxygen Doxyfile ./../Doxyfile
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
