#!/bin/bash

# Clang-format
echo "Clang-format code formatting check."
docker exec $IMAGE_NAME mv ./scripts/run-clang-format.py ./ 
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME python run-clang-format.py -r src test
retval=$?
(($retval != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

docker exec $IMAGE_NAME mv ./run-clang-format.py ./scripts
(($? != 0)) && { printf '%s\n' "Command exited with non-zero"; exit 1; }

exit $retval
