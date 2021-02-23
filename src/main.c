#include <stdio.h>
#include "matrix_math.h"

int test_add(void) {
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

    MTX_print(&C, NULL);

    if (error != MTX_Matrix_ERROR_NONE) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    int retval = 0;
    
    retval |= test_add();
    
    return retval;
}
