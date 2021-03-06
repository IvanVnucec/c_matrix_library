# About: File to be used to build Docker image.
# Author: Ivan Vnucec
# License: Do whatever you want with it. I don't care.

# Clone Docker image with Miniconda package manager installed
FROM continuumio/miniconda3

# Get gcc compiler
RUN apt-get update && apt-get install build-essential -y

# Copy environment.yml used by Miniconda package manager
COPY environment.yml tmp/environment.yml

# Run Miniconda environment
RUN conda env create -f tmp/environment.yml
RUN echo "source activate env" > ~/.bashrc
ENV PATH /opt/conda/envs/env/bin:$PATH

WORKDIR /app

# Run Meson build manager to compile, run tests, and save code coverage results
CMD ["/bin/bash", "-c", \
    "rm -rf builddir && \
    meson setup builddir -Db_coverage=true && \
    meson compile -C builddir && \
    meson test -C builddir && \
    ninja coverage -v -C builddir"]
