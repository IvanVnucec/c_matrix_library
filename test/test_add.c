/**
 * @file test_add.c
 * @author Ivan Vnucec
 * @brief MTX_add function test file
 * @date 2021-03-03
 *
 * @copyright Do whatever you want with it. I don't care.
 *
 */

#include "matrix_math.h"
#include "minunit.h"

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_add_fail_dim_a) {
  MTX_Error_E error;

  float dataA[4][3] = {{1.0, 2.0, 3.0},
                       {4.0, 5.0, 6.0},
                       {7.0, 8.0, 9.0},
                       {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S A = {.rows = 4, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_add_fail_dim_b) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[4][3] = {{1.0, 2.0, 3.0},
                       {4.0, 5.0, 6.0},
                       {7.0, 8.0, 9.0},
                       {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 4, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_add_fail_dim_c) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[4][3];

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 4, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_add_fail_null_a) {
  MTX_Error_E error;

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, NULL, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_add_fail_null_a_data) {
  MTX_Error_E error;

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = NULL};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_add_fail_null_b) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, NULL, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_add_fail_null_b_data) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)NULL};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_add_fail_null_c) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_add(NULL, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_add_fail_null_c_data) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)NULL};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_add_success_err_null) {
  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_add(&A, &A, &B, NULL);

  mu_assert_double_eq(A.data[0], 2.0);
  mu_assert_double_eq(A.data[1], 4.0);
  mu_assert_double_eq(A.data[2], 6.0);
  mu_assert_double_eq(A.data[3], 8.0);
  mu_assert_double_eq(A.data[4], 10.0);
  mu_assert_double_eq(A.data[5], 12.0);
  mu_assert_double_eq(A.data[6], 14.0);
  mu_assert_double_eq(A.data[7], 16.0);
  mu_assert_double_eq(A.data[8], 18.0);
}

MU_TEST(test_add_success_C_A_B) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataC[3][3];

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(2.0, C.data[0]);
  mu_assert_double_eq(4.0, C.data[1]);
  mu_assert_double_eq(6.0, C.data[2]);
  mu_assert_double_eq(8.0, C.data[3]);
  mu_assert_double_eq(10.0, C.data[4]);
  mu_assert_double_eq(12.0, C.data[5]);
  mu_assert_double_eq(14.0, C.data[6]);
  mu_assert_double_eq(16.0, C.data[7]);
  mu_assert_double_eq(18.0, C.data[8]);
}

MU_TEST(test_add_success_A_A_B) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_add(&A, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(2.0, A.data[0]);
  mu_assert_double_eq(4.0, A.data[1]);
  mu_assert_double_eq(6.0, A.data[2]);
  mu_assert_double_eq(8.0, A.data[3]);
  mu_assert_double_eq(10.0, A.data[4]);
  mu_assert_double_eq(12.0, A.data[5]);
  mu_assert_double_eq(14.0, A.data[6]);
  mu_assert_double_eq(16.0, A.data[7]);
  mu_assert_double_eq(18.0, A.data[8]);
}

MU_TEST(test_add_success_A_B_A) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  float dataB[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 3, .data = (float *)dataB};

  MTX_add(&A, &B, &A, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(2.0, A.data[0]);
  mu_assert_double_eq(4.0, A.data[1]);
  mu_assert_double_eq(6.0, A.data[2]);
  mu_assert_double_eq(8.0, A.data[3]);
  mu_assert_double_eq(10.0, A.data[4]);
  mu_assert_double_eq(12.0, A.data[5]);
  mu_assert_double_eq(14.0, A.data[6]);
  mu_assert_double_eq(16.0, A.data[7]);
  mu_assert_double_eq(18.0, A.data[8]);
}

MU_TEST(test_add_success_A_A_A) {
  MTX_Error_E error;

  float dataA[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  MTX_Matrix_S A = {.rows = 3, .cols = 3, .data = (float *)dataA};

  MTX_add(&A, &A, &A, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(2.0, A.data[0]);
  mu_assert_double_eq(4.0, A.data[1]);
  mu_assert_double_eq(6.0, A.data[2]);
  mu_assert_double_eq(8.0, A.data[3]);
  mu_assert_double_eq(10.0, A.data[4]);
  mu_assert_double_eq(12.0, A.data[5]);
  mu_assert_double_eq(14.0, A.data[6]);
  mu_assert_double_eq(16.0, A.data[7]);
  mu_assert_double_eq(18.0, A.data[8]);
}

MU_TEST(test_add_success_C_A_B_rowVect) {
  MTX_Error_E error;

  float dataA[1][3] = {{1, 4, 7}};

  float dataB[1][3] = {{1, 4, 7}};

  float dataC[1][3];

  MTX_Matrix_S A = {.rows = 1, .cols = 3, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 1, .cols = 3, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 1, .cols = 3, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(2.0, C.data[0]);
  mu_assert_double_eq(8.0, C.data[1]);
  mu_assert_double_eq(14.0, C.data[2]);
}

MU_TEST(test_add_success_C_A_B_colVect) {
  MTX_Error_E error;

  float dataA[3][1] = {{1.0}, {4.0}, {7.0}};

  float dataB[3][1] = {{1.0}, {4.0}, {7.0}};

  float dataC[3][1];

  MTX_Matrix_S A = {.rows = 3, .cols = 1, .data = (float *)dataA};

  MTX_Matrix_S B = {.rows = 3, .cols = 1, .data = (float *)dataB};

  MTX_Matrix_S C = {.rows = 3, .cols = 1, .data = (float *)dataC};

  MTX_add(&C, &A, &B, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(2.0, C.data[0]);
  mu_assert_double_eq(8.0, C.data[1]);
  mu_assert_double_eq(14.0, C.data[2]);
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_add_fail_dim_a);
  MU_RUN_TEST(test_add_fail_dim_b);
  MU_RUN_TEST(test_add_fail_dim_c);

  MU_RUN_TEST(test_add_fail_null_a);
  MU_RUN_TEST(test_add_fail_null_a_data);
  MU_RUN_TEST(test_add_fail_null_b);
  MU_RUN_TEST(test_add_fail_null_b_data);
  MU_RUN_TEST(test_add_fail_null_c);
  MU_RUN_TEST(test_add_fail_null_c_data);

  MU_RUN_TEST(test_add_success_err_null);

  MU_RUN_TEST(test_add_success_C_A_B);
  MU_RUN_TEST(test_add_success_A_A_B);
  MU_RUN_TEST(test_add_success_A_B_A);
  MU_RUN_TEST(test_add_success_A_A_A);

  MU_RUN_TEST(test_add_success_C_A_B_rowVect);
  MU_RUN_TEST(test_add_success_C_A_B_colVect);
}

int main(int argc, char *argv[]) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}