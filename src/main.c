// clang-format off

#include "matrix_math.h"

#include <stdio.h>

int main(void)
{
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0f, 2.0f, 3.0f}, 
        {4.0f, 5.0f, 6.0f}, 
        {7.0f, 8.0f, 9.0f}};

    float dataB[3][3] = {
        {1.0f, 2.0f, 3.0f}, 
        {4.0f, 5.0f, 6.0f}, 
        {7.0f, 8.0f, 9.0f}};

    float dataC[3][3];

    MTX_Matrix_S A, B, C;

    MTX_init(&A, 3, 3, (float *)dataA, &error);
    MTX_init(&B, 3, 3, (float *)dataB, &error);
    MTX_init(&C, 3, 3, (float *)dataC, &error);

    // C = cholesky(A)
    MTX_cholesky(&C, &A, &error);

    // B = A + B
    MTX_add(&B, &A, &B, &error);

    // C = A * B
    MTX_mult(&C, &A, &B, &error);

    // print A matrix if MTX_mult succesfull
    if (error == MTX_Matrix_ERROR_NONE) {
        unsigned int i, j;
        for (i = 0; i < C.cols; i++) {
            for (j = 0; j < C.rows; j++) {
                printf("%.4f ", C.data[i + j * C.cols]);
            }
            printf("\n");
        }
    }

    return 0;
}

// clang-format on
