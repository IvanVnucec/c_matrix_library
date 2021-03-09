[![CI](https://github.com/IvanVnucec/c_matrix_library/actions/workflows/main.yml/badge.svg)](https://github.com/IvanVnucec/c_matrix_library/actions/workflows/main.yml)
[![codecov](https://codecov.io/gh/IvanVnucec/c_matrix_library/branch/master/graph/badge.svg?token=DIJ1KJMVTM)](https://codecov.io/gh/IvanVnucec/c_matrix_library)
[![docs](https://img.shields.io/docsrs/regex?color=blue)](https://ivanvnucec.github.io/c_matrix_library/)

## About The Project
* Statically linked Matrix library written in C language.  
* Suitable for Embedded systems.  
* Row-major order optimized.  
* Unit tested.  

## Built With
Project is built using [Meson](https://mesonbuild.com/) build system.

## Getting Started
0. Clone repository and position yourself in the project root directory,
1. Build Docker image `./scripts/docker_image_build.sh`,
2. Run Docker container `./scripts/docker_container_run.sh`,
3. (Optional) Run Clang format `./scripts/docker_project_clang_format.sh`,
4. (Optional) Run CppCheck `./scripts/docker_project_cppcheck.sh`,
5. Build project `./scripts/docker_project_build.sh`.
6. Run Unit tests by running `./scripts/docker_project_test.sh`,
7. (Optional) Debug Unit tests with VS Code by going into `Run` tab and pressing green start button `(gdb) Docker`. To change a file to debug, modify `launch.json` file `"program"` key value,
8. (Optional) Generate Doxygen documentation by running `./scripts/docker_project_doxygen.sh`. Doxygen documentation is generated in `docs/Doxygen` folder,
9. Stop running container `./scripts/docker_container_stop.sh`. Container will remove itself automatically,
10. To build and test user could just call `./scripts/docker_build_and_run_tests.sh`.
 
## Prerequisites
* [Docker](https://www.docker.com/)

## Installation
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
