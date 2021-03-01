[![CI](https://github.com/IvanVnucec/c_matrix_library/actions/workflows/main.yml/badge.svg)](https://github.com/IvanVnucec/c_matrix_library/actions/workflows/main.yml)
[![codecov](https://codecov.io/gh/IvanVnucec/c_matrix_library/branch/master/graph/badge.svg?token=DIJ1KJMVTM)](https://codecov.io/gh/IvanVnucec/c_matrix_library)

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
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    float dataB[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    float dataC[3][3];
    
    MTX_Matrix_S A, B, C;

    MTX_init(&A, 3, 3, dataA, &error);
    MTX_init(&B, 3, 3, dataB, &error);
    MTX_init(&C, 3, 3, dataC, &error);

    /* C = A + B */
    MTX_add(&C, &A, &B, &error);

    MTX_print(&C, &error);

    return 0;
}
```

## License
Do whatever you want with it. I don't care.
