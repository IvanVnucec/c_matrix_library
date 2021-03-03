#!/bin/bash

# Generate Doxygen documentation
echo "Generating Doxygen documentation."
mkdir docs
mkdir docs/Doxygen
doxygen Doxyfile ./../Doxyfile
exit $?
