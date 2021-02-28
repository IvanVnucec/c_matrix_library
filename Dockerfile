FROM continuumio/miniconda3 AS base
RUN apt-get update && apt-get install build-essential -y
COPY environment.yml tmp/environment.yml
RUN conda env create -f tmp/environment.yml
RUN echo "source activate env" > ~/.bashrc
ENV PATH /opt/conda/envs/env/bin:$PATH
WORKDIR /app

FROM base AS src
COPY . /app

FROM src AS test
CMD ["/bin/bash", "-c", "meson setup builddir -Db_coverage=true && meson test -C builddir && ninja coverage -v -C builddir"]
