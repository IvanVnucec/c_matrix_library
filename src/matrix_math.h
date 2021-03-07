/**
 * @file matrix_math.h
 * @author Ivan Vnucec
 * @brief Header file that holds matrix function definitions.
 * @date 2021-03-03
 *
 * @copyright Do whatever you want with it. I don't care.
 *
 */

#ifndef MATRIX_MATH_H_
#define MATRIX_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Check NULL pointers of one Matrice
 *
 */
#define MTX_CHECK_NULL_PTRS_1(err, a)       \
  ({                                        \
    if ((a) == NULL || (a)->data == NULL) { \
      (err) = MTX_Matrix_ERROR_NULL;        \
    }                                       \
  })

/**
 * @brief Check NULL pointers of two Matrices
 *
 */
#define MTX_CHECK_NULL_PTRS_2(err, a, b)                \
  ({                                                    \
    if ((a) == NULL || (b) == NULL || (a)->data == NULL \
        || (b)->data == NULL) {                         \
      (err) = MTX_Matrix_ERROR_NULL;                    \
    }                                                   \
  })

/**
 * @brief Check NULL pointers of three Matrices
 *
 */
#define MTX_CHECK_NULL_PTRS_3(err, a, b, c)                            \
  ({                                                                   \
    if ((a) == NULL || (b) == NULL || (c) == NULL || (a)->data == NULL \
        || (b)->data == NULL || (c)->data == NULL) {                   \
      (err) = MTX_Matrix_ERROR_NULL;                                   \
    }                                                                  \
  })

/**
 * @brief Check dimensions of two Matrices
 *
 */
#define MTX_MATRIX_CHECK_DIMS_2(err, a, b)                     \
  ({                                                           \
    if (!((a)->rows == (b)->rows && (a)->cols == (b)->cols)) { \
      (err) = MTX_Matrix_ERROR_DIMENSIONS;                     \
    }                                                          \
  })

/**
 * @brief Check dimensions of three Matrices
 *
 */
#define MTX_MATRIX_CHECK_DIMS_3(err, a, b, c)                     \
  ({                                                              \
    if (!((c)->rows == (a)->rows && (c)->cols == (a)->cols        \
          && (a)->rows == (b)->rows && (a)->cols == (b)->cols)) { \
      (err) = MTX_Matrix_ERROR_DIMENSIONS;                        \
    }                                                             \
  })

/* Uncoment the lines below to implement NULL pointers or matrix dimensions
check or leave uncommented to improve execution time. */

//#define MTX_MATRIX_CHECK_DIMS     // This macro enables matrix dimension
// checking. #define MTX_MATRIX_CHECK_PTRS     // This macro enables NULL
// pointer  checking.

/**
 * @brief Matrix data structure
 *
 */
struct MTX_Matrix_STRUCT { //!< Matrix data structure
  unsigned int rows;       //!< Number of matrix rows
  unsigned int cols;       //!< Number of matrix columns
  float *data; //!< Pointer to one dimensional array of matrix elements
};

/**
 * @brief Matrix errors enums
 *
 */
enum MTX_Error_ENUM {          //!< Matrix errors
  MTX_Matrix_ERROR_NONE,       //!< No errors
  MTX_Matrix_ERROR_DIMENSIONS, //!< Dimension mismatch error
  MTX_Matrix_ERROR_NULL,       //!< NULL pointer exeption error
  MTX_Matrix_ERROR_NOT_SQUARE, //!< Matrix is not square error
  MTX_Matrix_ERROR_INPLACE,    //!< Matrix inplace error
  MTX_Matrix_ERROR_ZERO_DIMS,  //!< Matrix with 0 number of rows and/or columns
                               //!< error
  MTX_Matrix_ERROR_NOT_POS_DEF //!< Matrix not positive definite error
};

typedef struct MTX_Matrix_STRUCT
    MTX_Matrix_S;                        //!< Matrix data structure typedef
typedef enum MTX_Error_ENUM MTX_Error_E; //!< Matrix error enum typedef

void MTX_init(MTX_Matrix_S *c,
              unsigned int rows,
              unsigned int cols,
              float *data,
              MTX_Error_E *error);
void MTX_add(MTX_Matrix_S *c,
             const MTX_Matrix_S *a,
             const MTX_Matrix_S *b,
             MTX_Error_E *error);
void MTX_sub(MTX_Matrix_S *c,
             const MTX_Matrix_S *a,
             const MTX_Matrix_S *b,
             MTX_Error_E *error);
void MTX_scale(MTX_Matrix_S *c,
               float k,
               const MTX_Matrix_S *a,
               MTX_Error_E *error);
void MTX_zeros(MTX_Matrix_S *c, MTX_Error_E *error);
void MTX_identity(MTX_Matrix_S *c, MTX_Error_E *error);
void MTX_trans(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error);
void MTX_mult(MTX_Matrix_S *c,
              const MTX_Matrix_S *a,
              const MTX_Matrix_S *b,
              MTX_Error_E *error);
void MTX_setColumn(MTX_Matrix_S *c,
                   unsigned int columnIndex,
                   const MTX_Matrix_S *column,
                   MTX_Error_E *error);
void MTX_getColumn(MTX_Matrix_S *column,
                   MTX_Matrix_S *c,
                   unsigned int columnIndex,
                   MTX_Error_E *error);
void MTX_copy(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error);
void MTX_cholesky(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error);

#ifdef __cplusplus
}
#endif

#endif /* MATRIX_MATH_H_ */
