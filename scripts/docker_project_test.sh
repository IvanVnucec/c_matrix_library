#!/bin/bash

# load constants
. ./scripts/constants.env

readonly HOST_WORKDIR=/app  # defined in Dockerfile

docker exec -i $IMAGE_NAME bash -c "meson test -C builddir"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "ninja coverage -v -C builddir"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
