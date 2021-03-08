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
