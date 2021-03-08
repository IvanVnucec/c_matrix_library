#!/bin/bash

# load constants
. ./scripts/constants.env

readonly HOST_WORKDIR=/app  # defined in Dockerfile

docker container stop $IMAGE_NAME
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
