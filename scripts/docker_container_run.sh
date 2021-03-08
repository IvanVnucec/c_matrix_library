#!/bin/bash

# load constants
. ./scripts/constants.env

readonly HOST_WORKDIR=/app  # defined in Dockerfile

docker run --name $IMAGE_NAME --rm -d -v "$(pwd):$HOST_WORKDIR" -t $IMAGE_NAME
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
