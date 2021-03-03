[![CI](https://github.com/IvanVnucec/c_matrix_library/actions/workflows/main.yml/badge.svg)](https://github.com/IvanVnucec/c_matrix_library/actions/workflows/main.yml)
[![codecov](https://codecov.io/gh/IvanVnucec/c_matrix_library/branch/master/graph/badge.svg?token=DIJ1KJMVTM)](https://codecov.io/gh/IvanVnucec/c_matrix_library)
[![docs](https://img.shields.io/docsrs/regex?color=blue)](https://ivanvnucec.github.io/c_matrix_library/)

## About The Project
* Statically linked Matrix library written in C language.  
* Suitable for Embedded systems and for the Unscented Kalman filtering math.  
* Row-major order optimized.  
* Unit tested.  

### Built With
Project is build using Meson and Unit tested in Docker container. Also, it uses Conda as package manager:
* [Meson](https://mesonbuild.com/)
* [Docker](https://www.docker.com/)
* [Conda](https://docs.conda.io/en/latest/)

## Getting Started
0. Clone repository and position yourself in the project root directory.
1. Build Docker image by running `docker build -t="c_matrix_library_container" .`
2. Run Docker image by running `docker run --rm -v "$(pwd):/app" c_matrix_library_container`
3. Docker image would build and run unit tests. Build logs and code coverage reports are written in `builddir/meson-logs` folder.

### Prerequisites
* Docker

### Installation
1. Copy `matrix_math.c` and `matrix_math.h` into your project.
2. To implement NULL pointers checking uncomment `#define MTX_MATRIX_CHECK_PTRS` preprocessor macro in `matrix_math.h` file.
3. To implement matrix dimensions checking uncomment `#define MTX_MATRIX_CHECK_DIMS` preprocessor macro in `matrix_math.h` file.

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

    // C = A + A
    MTX_add(&C, &A, &A, &error);

    // C = A * B
    MTX_mult(&C, &A, &B, &error);

    // A = cholesky(C)
    MTX_cholesky(&A, &C, &error);

    MTX_print(&C, &error);

    return 0;
}
```

## License
Do whatever you want with it. I don't care.
