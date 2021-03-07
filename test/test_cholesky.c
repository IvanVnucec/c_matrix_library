/**
 * @file test_cholesky.c
 * @author Ivan Vnucec
 * @brief MTX_cholesky function test file
 * @date 2021-03-03
 *
 * @copyright Do whatever you want with it. I don't care.
 *
 */

#include "matrix_math.h"
#include "minunit.h"

void test_setup(void)
{
}

void test_teardown(void)
{
}

MU_TEST(test_cholesky_fail_dim_not_square)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[4][3] = {{4.0, 12.0, -16.0},
                         {12.0, 37.0, -43.0},
                         {-16.0, -43.0, 98.0},
                         {-16.0, -43.0, 98.0}};

    float dataC[4][3] = {0};

    MTX_Matrix_S A = {.rows = 4, .cols = 3, .data = (float *)dataA};

    MTX_Matrix_S C = {.rows = 4, .cols = 3, .data = (float *)dataC};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NOT_SQUARE);
}

MU_TEST(test_cholesky_fail_dim_a)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[4][3] = {{4.0, 12.0, -16.0},
                         {12.0, 37.0, -43.0},
                         {-16.0, -43.0, 98.0},
                         {-16.0, -43.0, 98.0}};

    float dataC[3][3] = {0};

    MTX_Matrix_S A = {.rows = 4, .cols = 3, .data = (float *)dataA};

    MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_cholesky_fail_dim_c)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    float dataC[3][4] = {0};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

    MTX_Matrix_S C = {.rows = 3, .cols = 4, .data = (float *)dataC};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_cholesky_fail_null_c)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

    MTX_cholesky(NULL, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_cholesky_fail_null_c_data)
{
    MTX_Error_E error;

    float dataA[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

    MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)NULL};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_cholesky_fail_null_a)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataC[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

    MTX_cholesky(&C, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_cholesky_fail_null_a_data)
{
    MTX_Error_E error;

    float dataC[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)NULL};

    MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_cholesky_fail_not_pos_def)
{
    MTX_Error_E error;

    float dataA[4][4] = {{0.99, 0.78, 0.59, 0.44},
                         {0.78, 0.92, 0.28, 0.81},
                         {0.59, 0.28, 1.12, 0.23},
                         {0.44, 0.81, 0.23, 0.99}};

    MTX_Matrix_S A = {.rows = 4, .cols = 4, .data = (float *)dataA};

    float dataC[4][4] = {0};

    MTX_Matrix_S C = {.rows = 4, .cols = 4, .data = (float *)dataC};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NOT_POS_DEF);
}

MU_TEST(test_cholesky_fail_c_inplace)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

    MTX_cholesky(&A, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_INPLACE);
}

MU_TEST(test_cholesky_success_err_null)
{
    float dataA[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    float dataC[3][3] = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

    MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

    MTX_cholesky(&C, &A, NULL);

    mu_assert_double_eq(2.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
    mu_assert_double_eq(6.0, C.data[3]);
    mu_assert_double_eq(1.0, C.data[4]);
    mu_assert_double_eq(0.0, C.data[5]);
    mu_assert_double_eq(-8.0, C.data[6]);
    mu_assert_double_eq(5.0, C.data[7]);
    mu_assert_double_eq(3.0, C.data[8]);
}

MU_TEST(test_cholesky_success_c)
{
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[3][3] = {{4.0, 12.0, -16.0}, {12.0, 37.0, -43.0}, {-16.0, -43.0, 98.0}};

    float dataC[3][3] = {0};

    MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

    MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

    MTX_cholesky(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(2.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
    mu_assert_double_eq(6.0, C.data[3]);
    mu_assert_double_eq(1.0, C.data[4]);
    mu_assert_double_eq(0.0, C.data[5]);
    mu_assert_double_eq(-8.0, C.data[6]);
    mu_assert_double_eq(5.0, C.data[7]);
    mu_assert_double_eq(3.0, C.data[8]);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_cholesky_fail_dim_not_square);
    MU_RUN_TEST(test_cholesky_fail_dim_a);
    MU_RUN_TEST(test_cholesky_fail_dim_c);

    MU_RUN_TEST(test_cholesky_fail_null_c);
    MU_RUN_TEST(test_cholesky_fail_null_a);
    MU_RUN_TEST(test_cholesky_fail_null_c_data);
    MU_RUN_TEST(test_cholesky_fail_null_a_data);

    MU_RUN_TEST(test_cholesky_fail_not_pos_def);

    MU_RUN_TEST(test_cholesky_fail_c_inplace);

    MU_RUN_TEST(test_cholesky_success_err_null);
    MU_RUN_TEST(test_cholesky_success_c);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}