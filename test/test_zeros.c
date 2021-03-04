/**
 * @file test_zeros.c
 * @author Ivan Vnucec
 * @brief MTX_zeros function test file
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

MU_TEST(test_zeros_fail_null_c) {
    MTX_Error_E error;

    MTX_zeros(NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_zeros_fail_null_c_data) {
    MTX_Error_E error;

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_zeros(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_zeros_success_err_null) {
    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_zeros(&C, NULL);

    mu_assert_double_eq(0.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
    mu_assert_double_eq(0.0, C.data[3]);
    mu_assert_double_eq(0.0, C.data[4]);
    mu_assert_double_eq(0.0, C.data[5]);
    mu_assert_double_eq(0.0, C.data[6]);
    mu_assert_double_eq(0.0, C.data[7]);
    mu_assert_double_eq(0.0, C.data[8]);
}

MU_TEST(test_zeros_success_c) {
    MTX_Error_E error;

    float dataC[3][3];

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_zeros(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
    mu_assert_double_eq(0.0, C.data[3]);
    mu_assert_double_eq(0.0, C.data[4]);
    mu_assert_double_eq(0.0, C.data[5]);
    mu_assert_double_eq(0.0, C.data[6]);
    mu_assert_double_eq(0.0, C.data[7]);
    mu_assert_double_eq(0.0, C.data[8]);
}

MU_TEST(test_zeros_success_c_rowVect) {
    MTX_Error_E error;

    float dataC[3][1];

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataC
    };

    MTX_zeros(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
}

MU_TEST(test_zeros_success_c_colVect) {
    MTX_Error_E error;

    float dataC[1][3];

    MTX_Matrix_S C = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_zeros(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_zeros_fail_null_c);
    MU_RUN_TEST(test_zeros_fail_null_c_data);
    
    MU_RUN_TEST(test_zeros_success_err_null);

    MU_RUN_TEST(test_zeros_success_c);
    MU_RUN_TEST(test_zeros_success_c_rowVect);
    MU_RUN_TEST(test_zeros_success_c_colVect);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}