#!/bin/bash

# Clang-format
echo "Clang-format code formatting check."
mv ./scripts/run-clang-format.py ./ 
python run-clang-format.py -r src test
retval=$?

mv ./run-clang-format.py ./scripts

exit $retval
