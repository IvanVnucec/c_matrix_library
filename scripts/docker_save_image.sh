#!/bin/bash

# load constants
. ./scripts/constants.env

echo "Saving Docker containter."
mkdir -p "$IMAGE_SAVE_DIR"
docker save --output ./"$IMAGE_SAVE_DIR"/"$IMAGE_NAME".tar "$IMAGE_NAME"
exit $?
