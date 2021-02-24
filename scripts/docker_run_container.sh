#!/bin/bash

# load constants
. ./scripts/constants.env

readonly HOST_WORKDIR=/app  # defined in Dockerfile

echo "Running Docker container."
docker run --rm -v "$(pwd):$HOST_WORKDIR" $IMAGE_NAME
docker_exit_code=$?

if [ $docker_exit_code != 0 ]
then
    cat ./builddir/meson-logs/testlog.txt
fi

exit $docker_exit_code
