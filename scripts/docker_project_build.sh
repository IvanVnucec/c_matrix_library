#!/bin/bash

# load constants
. ./scripts/constants.env

docker exec -i $IMAGE_NAME bash -c "rm -rf builddir"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "meson setup builddir -Db_coverage=true"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "meson compile -C builddir"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
