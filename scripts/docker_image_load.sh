#!/bin/bash

# load constants
. ./scripts/constants.env

echo "Loading Docker containter."
docker load --input ./"$IMAGE_SAVE_DIR"/"$IMAGE_NAME".tar
exit $?
