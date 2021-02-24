## About The Project
Statically linked Matrix library written in C language. Suitable for Embedded systems and for Unscented Kalman filtering math. Row-major order optimized.

### Built With
Project is build using Meson and Unit tested in Docker container. Also, it uses Conda as package manager:
* [Meson](https://mesonbuild.com/)
* [Docker](https://www.docker.com/)
* [Conda](https://docs.conda.io/en/latest/)

## Getting Started
1. Git clone this repository.
2. Build Conda environment by running `conda env update -f environment.yml`.
3. Activate Conda environment by running `conda activate matrix_lib_env`
4. Optionally, run Unit tests locally with Docker by running `./scripts/docker_build_image.sh` and then `./scripts/docker_run_container.sh`.

### Prerequisites
* Docker

### Installation
1. Copy `matrix_math.c` and `matrix_math.h` into your project.

## Usage
```c
#include "matrix_math.h"

int main(void) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_add(&C, &A, &B, &error);

    MTX_print(&C, &error);

    return 0;
}
```

## License
Do whatever you want with it. I don't care.
