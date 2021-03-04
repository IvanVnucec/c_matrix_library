/**
 * @file test_scale.c
 * @author Ivan Vnucec
 * @brief MTX_scale function test file
 * @date 2021-03-03
 * 
 * @copyright Do whatever you want with it. I don't care.
 * 
 */

#include "minunit.h"
#include "matrix_math.h"

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_scale_fail_dim_a) {
    MTX_Error_E error;

    float dataA[4][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {7.0, 8.0, 9.0}
    };

    float k = 2.0;

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_scale_fail_dim_c) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[4][3];

    float k = 2.0;

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_scale_fail_null_a) {
    MTX_Error_E error;

    float k = 2.0;

    float dataC[3][3];

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_scale_fail_null_a_data) {
    MTX_Error_E error;

    float k = 2.0;

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = NULL
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_scale_fail_null_c) {
    MTX_Error_E error;

    float k = 2.0;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_scale(NULL, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_scale_fail_null_c_data) {
    MTX_Error_E error;

    float k = 2.0;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_scale_success_err_null) {

    float k = 2.0;

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

    MTX_scale(&A, k, &B, NULL);

    mu_assert_double_eq(A.data[0],  2.0);
    mu_assert_double_eq(A.data[1],  4.0);
    mu_assert_double_eq(A.data[2],  6.0);
    mu_assert_double_eq(A.data[3],  8.0);
    mu_assert_double_eq(A.data[4], 10.0);
    mu_assert_double_eq(A.data[5], 12.0);
    mu_assert_double_eq(A.data[6], 14.0);
    mu_assert_double_eq(A.data[7], 16.0);
    mu_assert_double_eq(A.data[8], 18.0);
}

MU_TEST(test_scale_success_C_k_A) {
    MTX_Error_E error;

    float k = 2.0;

    float dataA[3][3] = {
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

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(C.data[0],  2.0);
    mu_assert_double_eq(C.data[1],  4.0);
    mu_assert_double_eq(C.data[2],  6.0);
    mu_assert_double_eq(C.data[3],  8.0);
    mu_assert_double_eq(C.data[4], 10.0);
    mu_assert_double_eq(C.data[5], 12.0);
    mu_assert_double_eq(C.data[6], 14.0);
    mu_assert_double_eq(C.data[7], 16.0);
    mu_assert_double_eq(C.data[8], 18.0);
}

MU_TEST(test_scale_success_A_k_A) {
    MTX_Error_E error;

    float k = 2.0;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_scale(&A, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(A.data[0],  2.0);
    mu_assert_double_eq(A.data[1],  4.0);
    mu_assert_double_eq(A.data[2],  6.0);
    mu_assert_double_eq(A.data[3],  8.0);
    mu_assert_double_eq(A.data[4], 10.0);
    mu_assert_double_eq(A.data[5], 12.0);
    mu_assert_double_eq(A.data[6], 14.0);
    mu_assert_double_eq(A.data[7], 16.0);
    mu_assert_double_eq(A.data[8], 18.0);
}

MU_TEST(test_scale_success_C_k_A_rowVect) {
    MTX_Error_E error;

    float k = 2.0;

    float dataA[3][1] = {
        {1.0},
        {4.0},
        {7.0}
    };

    float dataC[3][1];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(C.data[0],  2.0);
    mu_assert_double_eq(C.data[1],  8.0);
    mu_assert_double_eq(C.data[2],  14.0);
}

MU_TEST(test_scale_success_C_k_A_colVect) {
    MTX_Error_E error;

    float k = 2.0;

    float dataA[1][3] = {{1.0, 2.0, 3.0}};

    float dataC[1][3];

    MTX_Matrix_S A = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_scale(&C, k, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(C.data[0],  2.0);
    mu_assert_double_eq(C.data[1],  4.0);
    mu_assert_double_eq(C.data[2],  6.0);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_scale_fail_dim_a);
    MU_RUN_TEST(test_scale_fail_dim_c);

    MU_RUN_TEST(test_scale_fail_null_a);
    MU_RUN_TEST(test_scale_fail_null_a_data);
    MU_RUN_TEST(test_scale_fail_null_c);
    MU_RUN_TEST(test_scale_fail_null_c_data);
    
    MU_RUN_TEST(test_scale_success_err_null);

    MU_RUN_TEST(test_scale_success_C_k_A);
    MU_RUN_TEST(test_scale_success_A_k_A);

    MU_RUN_TEST(test_scale_success_C_k_A_rowVect);
    MU_RUN_TEST(test_scale_success_C_k_A_colVect);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}