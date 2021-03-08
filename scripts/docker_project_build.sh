#!/bin/bash

# load constants
. ./scripts/constants.env

readonly HOST_WORKDIR=/app  # defined in Dockerfile

echo "Running Docker container."
docker exec $IMAGE_NAME rm -rf builddir
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME meson setup builddir -Db_coverage=true
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME meson compile -C builddir
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
