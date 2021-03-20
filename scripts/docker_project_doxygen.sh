#!/bin/bash

# load constants
. ./scripts/constants.env

echo "Generate Doxygen documentation."
docker exec -i $IMAGE_NAME bash -c "mkdir -p docs"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "mkdir -p docs/Doxygen" ./../Doxyfile
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec -i $IMAGE_NAME bash -c "doxygen docker_project_doxygenDoxyfile"
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

echo "Done Generate Doxygen documentation."

exit 0
