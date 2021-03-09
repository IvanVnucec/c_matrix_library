/**
 * @file matrix_math.c
 * @author Ivan Vnucec
 * @brief Functions to perform matrix operations.
 * @date 2021-03-03
 *
 * @copyright WTFPL – Do What the Fuck You Want to Public License. See .LICENSE.md file for more information.
 *
 */

#include "matrix_math.h"

#include <math.h>
#include <stddef.h>

/**
 * @brief Function initializes MTX_Matrix_S data structure. Call init function
 * before you want to work with MTX_Matrix_S data type variable.
 *
 * @param c Destination data structure where rows, cols and data will be
 * written.
 * @param rows Number of matrix rows.
 * @param cols Number of matrix columns.
 * @param data Pointer to a (float *) data.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c or float *data was NULL,
 *      - MTX_Matrix_ERROR_ZERO_DIMS - variable rows or cols has 0 value.
 */
void MTX_init(MTX_Matrix_S *c,
              unsigned int rows,
              unsigned int cols,
              float *data,
              MTX_Error_E *error)
{
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

/**
 * @brief Function adds a and b matrixes and puts the result into the c matrix:
 * c = a + b
 * @note  Can be inplaced:
 *      - A = A + A
 *      - A = A + B
 *      - A = B + A
 *
 * @param c Result of operation matrix.
 * @param a First operand to add.
 * @param b Second operand to add.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *a or *b or their *->data
 * equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - Matrices a, b and c don't have the same
 * dimensions.
 */
void MTX_add(MTX_Matrix_S *c,
             const MTX_Matrix_S *a,
             const MTX_Matrix_S *b,
             MTX_Error_E *error)
{
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

/**
 * @brief Function subtracts matrix b from a matrix and puts the result into the
 * c matrix: c = a - b
 * @note  Can be inplaced:
 *          - A = A - A
 *          - A = A - B
 *          - A = B - A.
 *
 * @param c Result of operation matrix.
 * @param a First operand to subtract from.
 * @param b Second operand to subctract.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *a or *b or their *->data
 * equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - Matrices a, b and c don't have the same
 * dimensions.
 */
void MTX_sub(MTX_Matrix_S *c,
             const MTX_Matrix_S *a,
             const MTX_Matrix_S *b,
             MTX_Error_E *error)
{
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

/**
 * @brief Function scales every element of matrix c by scalar term k: c = k * a.
 * @note  Can be inplaced:
 *      - A = k * A
 *
 * @param c Result of operation matrix.
 * @param k Scalar scale term.
 * @param a Matrix to scale from.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c or *a or c->data or a->data
 * were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - Matrices a and c don't have the same
 * dimensions.
 */
void MTX_scale(MTX_Matrix_S *c, float k, const MTX_Matrix_S *a, MTX_Error_E *error)
{
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

/**
 * @brief Function fills the matrix with zeros (0.0f).
 *
 * @param c Result of operation matrix.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c or c->data was NULL
 */
void MTX_zeros(MTX_Matrix_S *c, MTX_Error_E *error)
{
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

/**
 * @brief Function returns identity matrix.
 *
 * @param c Result of operation matrix.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c or c->data was NULL,
 *      - MTX_Matrix_ERROR_NOT_SQUARE - MTX_Matrix_S *c is not square matrix.
 */
void MTX_identity(MTX_Matrix_S *c, MTX_Error_E *error)
{
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

/**
 * @brief Returns matrix transpose.
 *
 * @param c Result of operation matrix.
 * @param a Matrix to transpose.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *a or c->data, a->data were
 * NULL,
 *      - MTX_Matrix_ERROR_DIMENSIONS - MTX_Matrix_S *c has invalid dimensions.
 */
void MTX_trans(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error)
{
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

/**
 * @brief Multiplies two matrices a and b and puts the result in matrix c: c = a
 * * b.
 * @warning Can not be inplaced: ex. `A = A * A` or `B = A * B` or `B = B * A`
 *
 * @param c Result of operation matrix.
 * @param a First operand.
 * @param b Second operand.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *a or *b or their *->data
 * equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - MTX_Matrix_S *c has invalid dimensions.
 *      - MTX_Matrix_ERROR_INPLACE - It occured because you presumably did: A =
 * A * A or B = A * B or similar.
 */
void MTX_mult(MTX_Matrix_S *c,
              const MTX_Matrix_S *a,
              const MTX_Matrix_S *b,
              MTX_Error_E *error)
{
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;
    int m, r, k;

#ifdef MTX_MATRIX_CHECK_PTRS
    MTX_CHECK_NULL_PTRS_3(errorLocal, c, a, b);
#endif

#ifdef MTX_MATRIX_CHECK_DIMS
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (a->cols != b->rows || a->rows != c->rows || b->cols != c->cols) {
            errorLocal = MTX_Matrix_ERROR_DIMENSIONS;
        }
    }
#endif

    // can't do A = A * B
    // or A = B * A
    // or A = A * A
    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        if (c->data == a->data || c->data == b->data) {
            errorLocal = MTX_Matrix_ERROR_INPLACE;
        }
    }

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
        for (m = 0; m < a->rows; m++) {
            for (r = 0; r < b->cols; r++) {
                c->data[r + m * c->cols] = 0.0f;

                for (k = 0; k < b->rows; k++) {
                    c->data[r + m * c->cols] =
                        c->data[r + m * c->cols]
                        + a->data[k + m * a->cols] * b->data[r + k * b->cols];
                }
            }
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

/**
 * @brief Function fills columnIndex column of matrix c with values in column
 * matrix.
 * @note Function can be inplaced.
 * @note If column is matrix then it will copy its values from the 0'th column.
 *
 * @param c Matrix to fill its column with values.
 * @param columnIndex Index of column to fill. Starts with index 0.
 * @param column Values to fill. Must have the same number of rows as c data.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *column or *b or their
 * *->data equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - MTX_Matrix_S *c and MTX_Matrix_S *column
 * has != number of rows or columnIndex is greather then c matrix columns.
 */
void MTX_setColumn(MTX_Matrix_S *c,
                   unsigned int columnIndex,
                   const MTX_Matrix_S *column,
                   MTX_Error_E *error)
{
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
        for (i = 0; i < c->rows; i++) {
            c->data[columnIndex + i * c->cols] = column->data[0 + i * column->cols];
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}

/**
 * @brief Function copies columnIndex column vector of matrix c to column vector
 * column.
 * @note Function can be inplaced.
 * @note If column is matrix then it will copy c column values to its 0'th
 * column.
 *
 * @param column Column vector to fill with values. Must have the same number of
 * rows as c data.
 * @param c Values to copy from.
 * @param columnIndex Index of column to fill. Starts with index 0.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *column or *b or their
 * *->data equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - MTX_Matrix_S *c and MTX_Matrix_S *column
 * has != number of rows or columnIndex is larger then number of columns that c
 * matrix has.
 */
void MTX_getColumn(MTX_Matrix_S *column,
                   MTX_Matrix_S *c,
                   unsigned int columnIndex,
                   MTX_Error_E *error)
{
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

/**
 * @brief Function copies values from <a> matrix to c matrix.
 *
 * @param c Matrix to copy to.
 * @param a Matrix to copy from.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *column or *a or their
 * *->data equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - MTX_Matrix_S *c and MTX_Matrix_S *a have
 * different dimensions.
 */
void MTX_copy(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error)
{
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

/**
 * @brief Function performs the Cholesky–Banachiewicz algorithm. Returns lower
 * triangular matrix. C = cholesky(A)
 * @warning Function can not be inplaced: A = cholesky(A)!
 *
 * @param c Lower triangular matrix.
 * @param a Matrix to perform Cholesky decomposition.
 * @param error Variable used to return error. It can have the following values:
 *      - MTX_Matrix_ERROR_NONE - No errors occured,
 *      - MTX_Matrix_ERROR_NULL - MTX_Matrix_S *c, *column or *a or their
 * *->data equivalents were NULL.
 *      - MTX_Matrix_ERROR_DIMENSIONS - MTX_Matrix_S *c and MTX_Matrix_S *a have
 * different dimensions.
 *      - MTX_Matrix_ERROR_NOT_SQUARE - MTX_Matrix_S *c is not square matrix.
 *      - MTX_Matrix_ERROR_INPLACE - It occured because you presumably did: A =
 * cholesky(A)
 *      - MTX_Matrix_ERROR_NOT_POS_DEF - MTX_Matrix_S *a is not positive
 * definite.
 */
void MTX_cholesky(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error)
{
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

    if (errorLocal == MTX_Matrix_ERROR_NONE) {
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
            for (j = 0; j < (i + 1) && errorLocal != MTX_Matrix_ERROR_NOT_POS_DEF; j++) {
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
                    c->data[i * c->cols + j] = 1.0f / c->data[j * c->cols + j]
                                               * (a->data[i * a->cols + j] - sum);
                }
            }
        }
    }

    if (error != NULL) {
        *error = errorLocal;
    }

    return;
}
