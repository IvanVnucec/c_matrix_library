#!/bin/bash

# load constants
. ./scripts/constants.env

docker container stop $IMAGE_NAME
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit 0
