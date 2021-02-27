#include <stddef.h>
#include <stdio.h>
#include "matrix_math.h"

void MTX_add(MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_3(errorLocal, a, b, c);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_MATRIX_CHECK_DIMS_3(errorLocal, a, b, c);
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows * c->cols; i++) {
            c->data[i] = a->data[i] + b->data[i]; 
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

void MTX_sub(MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_3(errorLocal, a, b, c);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_MATRIX_CHECK_DIMS_3(errorLocal, a, b, c);
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows * c->cols; i++) {
            c->data[i] = a->data[i] - b->data[i];
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

void MTX_scale(MTX_Matrix_S *c, float k, const MTX_Matrix_S *a, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_2(errorLocal, a, c);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_MATRIX_CHECK_DIMS_2(errorLocal, a, c);
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows * c->cols; i++) {
            c->data[i] = k * a->data[i];
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

void MTX_zeros(MTX_Matrix_S *c, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_1(errorLocal, c);
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows * c->cols; i++) {
            c->data[i] = 0.0f;
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_identity(MTX_Matrix_S *c, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_1(errorLocal, c);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (c->rows != c->cols) {
            errorLocal = MTX_Matrix_ERROR_NOT_SQUARE;
        }
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_zeros(c, &errorLocal);
    }

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows; i++) {
            c->data[i + c->cols * i] = 1.0f;
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_trans(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i, j;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_1(errorLocal, c);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (c->rows != a->cols || c->cols != a->rows) {
            errorLocal = MTX_Matrix_ERROR_DIMENSIONS;
        }
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows; i++) {
            for (j = 0; j < c->cols; j++) {
                c->data[j + i * c->cols] = a->data[i + j * a->cols];
            }
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_print(const MTX_Matrix_S *c, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i, j;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_1(errorLocal, c);
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0u; i < c->rows; i++) {
            for (j = 0u; j < c->cols; j++) {
                printf("%6.3f ", c->data[i * c->cols + j]);
            }
            printf("\n");
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}