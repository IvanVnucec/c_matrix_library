#!/bin/bash

# load constants
. ./scripts/constants.env

# build and run Docker image
echo "Building Docker containter."
docker build -t="$IMAGE_NAME" .
exit $?
