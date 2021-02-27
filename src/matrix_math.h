#ifndef MATRIX_MATH_H_
#define MATRIX_MATH_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define MTX_CHECK_NULL_PTRS_1(err, a) ({ \
    if ((a) == NULL || (a)->data == NULL) \
        { \
            (err) = MTX_Matrix_ERROR_NULL; \
        } \
})

#define MTX_CHECK_NULL_PTRS_2(err, a, b) ({\
    if ((a) == NULL || (b) == NULL || \
        (a)->data == NULL || (b)->data == NULL) \
        { \
            (err) = MTX_Matrix_ERROR_NULL; \
        } \
})

#define MTX_CHECK_NULL_PTRS_3(err, a, b, c) ({ \
    if ((a) == NULL || (b) == NULL || (c) == NULL || \
        (a)->data == NULL || (b)->data == NULL || (c)->data == NULL) \
        { \
            (err) = MTX_Matrix_ERROR_NULL; \
        } \
})

#define MTX_MATRIX_CHECK_DIMS_2(err, a, b) ({ \
    if ((a)->rows != (b)->rows || \
        (a)->cols != (b)->cols)   \
    { \
        (err) = MTX_Matrix_ERROR_DIMENSIONS; \
    } \
})

#define MTX_MATRIX_CHECK_DIMS_3(err, a, b, c) ({ \
    if ((a)->rows != (b)->rows || \
        (a)->cols != (b)->cols || \
        (c)->rows != (a)->rows || \
        (c)->cols != (a)->cols || \
        (b)->rows != (c)->rows || \
        (b)->cols != (c)->cols)   \
    { \
        (err) = MTX_Matrix_ERROR_DIMENSIONS; \
    } \
})

struct MTX_Matrix_STRUCT {
    const unsigned int rows;
    const unsigned int cols;
    float *data;
};

enum MTX_Error_ENUM {
    MTX_Matrix_ERROR_NONE,
    MTX_Matrix_ERROR_DIMENSIONS,
    MTX_Matrix_ERROR_NULL,
    MTX_Matrix_ERROR_NOT_SQUARE
};

typedef struct MTX_Matrix_STRUCT MTX_Matrix_S;
typedef enum MTX_Error_ENUM MTX_Error_E;

void MTX_add  (MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error);
void MTX_sub  (MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error);
void MTX_scale(MTX_Matrix_S *c, float k, const MTX_Matrix_S *a, MTX_Error_E *error);
void MTX_zeros(MTX_Matrix_S *c, MTX_Error_E *error);
void MTX_ones (MTX_Matrix_S *c, MTX_Error_E *error);
void MTX_trans(MTX_Matrix_S *c, const MTX_Matrix_S *a, MTX_Error_E *error);

void MTX_print(const MTX_Matrix_S *c, MTX_Error_E *error);

#ifdef __cplusplus 
}
#endif

#endif /* MATRIX_MATH_H_ */