#ifndef MATRIX_MATH_H_
#define MATRIX_MATH_H_

struct MTX_Matrix_STRUCT {
    const unsigned int rows;
    const unsigned int cols;
    float *data;
};

enum MTX_Error_ENUM {
    MTX_Matrix_ERROR_NONE,
    MTX_Matrix_ERROR_DIMENSIONS
};

typedef struct MTX_Matrix_STRUCT MTX_Matrix_S;
typedef enum MTX_Error_ENUM MTX_Error_E;

void MTX_add(MTX_Matrix_S *c, const MTX_Matrix_S *a, const MTX_Matrix_S *b, MTX_Error_E *error);
void MTX_print(const MTX_Matrix_S *c);

#endif /* MATRIX_MATH_H_ */