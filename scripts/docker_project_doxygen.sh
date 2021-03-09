#!/bin/bash

# load constants
. ./scripts/constants.env

docker exec -i $IMAGE_NAME bash -c "mkdir docs"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "mkdir docs/Doxygen"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "doxygen Doxyfile ./../Doxyfile"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
