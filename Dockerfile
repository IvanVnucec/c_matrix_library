FROM continuumio/miniconda3

RUN apt-get update && apt-get install build-essential -y

COPY environment.yml tmp/environment.yml

RUN conda env create -f tmp/environment.yml

RUN echo "source activate env" > ~/.bashrc

ENV PATH /opt/conda/envs/env/bin:$PATH

WORKDIR /app

CMD ["/bin/bash", "-c", "meson setup builddir -Db_coverage=true && meson test -C builddir"]
