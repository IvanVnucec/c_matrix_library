#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "matrix_math.h"

void MTX_init (MTX_Matrix_S *c, unsigned int rows, unsigned int cols, float *data, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;

    #ifdef MTX_MATRIX_CHECK_PTRS
    if (c == NULL || data == NULL) {
        errorLocal = MTX_Matrix_ERROR_NULL;
    }
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (rows == 0 || cols == 0) {
        errorLocal = MTX_Matrix_ERROR_ZERO_DIMS;
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        c->rows = rows;
        c->cols = cols;
        c->data = data;
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

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
    MTX_CHECK_NULL_PTRS_2(errorLocal, c, a);
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

void MTX_mult(MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int m, r, k;
    
    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_3(errorLocal, c, a, b);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (a->cols != b->rows ||
            a->rows != c->rows ||
            b->cols != c->cols) 
        {
            errorLocal = MTX_Matrix_ERROR_DIMENSIONS;
        }
    }
    #endif

    // can't do A = A * B 
    // or A = B * A 
    // or A = A * A
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (c->data == a->data ||
            c->data == b->data) 
        {
            errorLocal = MTX_Matrix_ERROR_INPLACE;
        }
    }

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (m = 0; m < a->rows; m++) {
            for (r = 0; r < b->cols; r++) {
                c->data[r + m * c->cols] = 0.0f;

                for (k = 0; k < b->rows; k++) {
                    c->data[r + m * c->cols] = c->data[r + m * c->cols] + a->data[k + m * a->cols] * b->data[r + k * b->cols];
                }
            }
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_setColumn(MTX_Matrix_S *c, unsigned int columnIndex, const MTX_Matrix_S *column, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_2(errorLocal, c, column);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (columnIndex >= c->cols || 
            column->rows != c->rows) {
            errorLocal = MTX_Matrix_ERROR_DIMENSIONS;
        }
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows; i++) {
            c->data[columnIndex + i * c->cols] = column->data[0 + i * column->cols];
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_getColumn(MTX_Matrix_S *column, MTX_Matrix_S *c, unsigned int columnIndex, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_2(errorLocal, c, column);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (columnIndex >= c->cols || column->rows != c->rows) {
            errorLocal = MTX_Matrix_ERROR_DIMENSIONS;
        }
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < column->rows; i++) {
            column->data[0 + i * column->cols] = c->data[columnIndex + i * c->cols];
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_copy(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_2(errorLocal, c, a);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_MATRIX_CHECK_DIMS_2(errorLocal, a, c);
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows * c->cols; i++) {
            c->data[i] = a->data[i];
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return; 
}

void MTX_cholesky(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int i, j, k;
    float sum, val;

    #ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_2(errorLocal, c, a);
    #endif

    #ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_MATRIX_CHECK_DIMS_2(errorLocal, a, c);
    }

    if (errorLocal ==MTX_Matrix_ERROR_NONE) {
        if (c->rows != c->cols) {
            errorLocal = MTX_Matrix_ERROR_NOT_SQUARE;
        }
    }
    #endif

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (c->data == a->data) {
            errorLocal = MTX_Matrix_ERROR_INPLACE;
        }
    }

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        MTX_zeros(c, &errorLocal);
    }

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (i = 0; i < c->rows && errorLocal != MTX_Matrix_ERROR_NOT_POS_DEF; i++) {
            for (j = 0; j < (i+1) && errorLocal != MTX_Matrix_ERROR_NOT_POS_DEF; j++) {
                sum = 0.0f;

                for (k = 0; k < j; k++) {
                    sum += c->data[i * c->cols + k] * c->data[j * c->cols + k];
                }

                if (i == j) {
                    val = a->data[i * a->cols + i] - sum;

                    if (val >= 0.0f) {
                        c->data[i * c->cols + j] = sqrtf(val);

                    } else {
                        errorLocal = MTX_Matrix_ERROR_NOT_POS_DEF;
                    }

                } else {
                    c->data[i * c->cols + j] = (1.0f / c->data[j * c->cols + j] * (a->data[i * a->cols + j] - sum));

                }
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
