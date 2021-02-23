#include <stddef.h>
#include <stdio.h>
#include "matrix_math.h"

void MTX_add(MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    // TODO: Check NULL ptrs
    // TODO: Check dimensions.

    for (i = 0; i < a->rows * a->cols; i++) {
        c->data[i] = a->data[i] + b->data[i];
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

void MTX_print(const MTX_Matrix_S *c, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i, j;

    // TODO: Check NULL ptrs

    for (i = 0u; i < c->rows; i++) {
        for (j = 0u; j < c->cols; j++) {
            printf("%6.3f ", c->data[i * c->cols + j]);
        }
        printf("\n");
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}