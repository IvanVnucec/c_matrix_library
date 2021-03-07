/**
 * @file test_setcolumn.c
 * @author Ivan Vnucec
 * @brief MTX_setColumn function test file
 * @date 2021-03-03
 *
 * @copyright Do whatever you want with it. I don't care.
 *
 */

#include "matrix_math.h"
#include "minunit.h"

void test_setup(void) {}

void test_teardown(void) {}

MU_TEST(test_setColumn_fail_null_c) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);

  MTX_setColumn(NULL, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_setColumn_fail_null_c_data) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  MTX_Matrix_S C = {.cols = 3, .rows = 3, .data = (float *)NULL};

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);

  MTX_setColumn(&C, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_setColumn_fail_null_column) {
  MTX_Error_E error;

  float dataC[3][3];

  MTX_Matrix_S C;

  MTX_init(&C, 3, 1, (float *)dataC, &error);

  MTX_setColumn(&C, 0, NULL, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_setColumn_fail_null_column_data) {
  MTX_Error_E error;

  float dataC[3][3];

  MTX_Matrix_S C;
  MTX_Matrix_S column = {.rows = 3, .cols = 1, .data = (float *)NULL};

  MTX_init(&C, 3, 1, (float *)dataC, &error);

  MTX_setColumn(&C, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_setColumn_fail_dim_rows) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  float dataC[4][3]
      = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  MTX_Matrix_S C;

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);
  MTX_init(&C, 4, 3, (float *)dataC, &error);

  MTX_setColumn(&C, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_setColumn_fail_dim_cols) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  float dataC[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  MTX_Matrix_S C;

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);
  MTX_init(&C, 3, 3, (float *)dataC, &error);

  MTX_setColumn(&C, 3, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_setColumn_success_err_null) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  float dataC[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  MTX_Matrix_S C;

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);
  MTX_init(&C, 3, 3, (float *)dataC, &error);

  MTX_setColumn(&C, 0, &column, NULL);

  mu_assert_double_eq(1.0, C.data[0]);
  mu_assert_double_eq(0.0, C.data[1]);
  mu_assert_double_eq(0.0, C.data[2]);

  mu_assert_double_eq(2.0, C.data[3]);
  mu_assert_double_eq(0.0, C.data[4]);
  mu_assert_double_eq(0.0, C.data[5]);

  mu_assert_double_eq(3.0, C.data[6]);
  mu_assert_double_eq(0.0, C.data[7]);
  mu_assert_double_eq(0.0, C.data[8]);
}

MU_TEST(test_setColumn_success_c) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  float dataC[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  MTX_Matrix_S C;

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);
  MTX_init(&C, 3, 3, (float *)dataC, &error);

  MTX_setColumn(&C, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(1.0, C.data[0]);
  mu_assert_double_eq(0.0, C.data[1]);
  mu_assert_double_eq(0.0, C.data[2]);

  mu_assert_double_eq(2.0, C.data[3]);
  mu_assert_double_eq(0.0, C.data[4]);
  mu_assert_double_eq(0.0, C.data[5]);

  mu_assert_double_eq(3.0, C.data[6]);
  mu_assert_double_eq(0.0, C.data[7]);
  mu_assert_double_eq(0.0, C.data[8]);
}

MU_TEST(test_setColumn_success_column_not_column) {
  MTX_Error_E error;

  float dataColumn[3][2] = {{1.0, 1.0}, {2.0, 1.0}, {3.0, 1.0}};

  MTX_Matrix_S column;

  float dataC[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  MTX_Matrix_S C;

  MTX_init(&column, 3, 2, (float *)dataColumn, &error);
  MTX_init(&C, 3, 3, (float *)dataC, &error);

  MTX_setColumn(&C, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(1.0, C.data[0]);
  mu_assert_double_eq(0.0, C.data[1]);
  mu_assert_double_eq(0.0, C.data[2]);

  mu_assert_double_eq(2.0, C.data[3]);
  mu_assert_double_eq(0.0, C.data[4]);
  mu_assert_double_eq(0.0, C.data[5]);

  mu_assert_double_eq(3.0, C.data[6]);
  mu_assert_double_eq(0.0, C.data[7]);
  mu_assert_double_eq(0.0, C.data[8]);
}

MU_TEST(test_setColumn_success_inplace) {
  MTX_Error_E error;

  float dataColumn[3][1] = {{1.0}, {2.0}, {3.0}};

  MTX_Matrix_S column;

  MTX_init(&column, 3, 1, (float *)dataColumn, &error);

  MTX_setColumn(&column, 0, &column, &error);

  mu_check(error == MTX_Matrix_ERROR_NONE);
  mu_assert_double_eq(1.0, column.data[0]);
  mu_assert_double_eq(2.0, column.data[1]);
  mu_assert_double_eq(3.0, column.data[2]);
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_setColumn_fail_null_c);
  MU_RUN_TEST(test_setColumn_fail_null_c_data);
  MU_RUN_TEST(test_setColumn_fail_null_column);
  MU_RUN_TEST(test_setColumn_fail_null_column_data);

  MU_RUN_TEST(test_setColumn_fail_dim_cols);
  MU_RUN_TEST(test_setColumn_fail_dim_rows);

  MU_RUN_TEST(test_setColumn_success_err_null);

  MU_RUN_TEST(test_setColumn_success_c);
  MU_RUN_TEST(test_setColumn_success_column_not_column);
  MU_RUN_TEST(test_setColumn_success_inplace);
}

int main(int argc, char *argv[]) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
