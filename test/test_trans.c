/**
 * @file test_trans.c
 * @author Ivan Vnucec
 * @brief MTX_trans function test file
 * @date 2021-03-03
 * 
 * @copyright WTFPL – Do What the Fuck You Want to Public License. See LICENSE.md file for more information.
 * 
 */

#include "minunit.h"
#include "matrix_math.h"

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_trans_fail_dim_c_rows) {
    MTX_Error_E error;

    float dataA[3][4];
    float dataC[3][4];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_trans_fail_dim_c_cols) {
    MTX_Error_E error;

    float dataA[3][4];
    float dataC[4][4];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 4,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_trans_fail_null_c) {
    MTX_Error_E error;

    float dataA[3][4] = {
        {1.0,  2.0,  3.0,  4.0},
        {5.0,  6.0,  7.0,  8.0},
        {9.0, 10.0, 11.0, 12.0}
    };

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_trans(NULL, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trans_fail_null_c_data) {
    MTX_Error_E error;

    float dataA[3][4] = {
        {1.0,  2.0,  3.0,  4.0},
        {5.0,  6.0,  7.0,  8.0},
        {9.0, 10.0, 11.0, 12.0}
    };

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trans_fail_null_a) {
    MTX_Error_E error;

    float dataC[4][3];

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_trans(&C, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trans_fail_null_a_data) {
    MTX_Error_E error;

    float dataC[4][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)NULL
    };

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trans_success_err_null) {
    float dataA[3][4] = {
        {1.0,  2.0,  3.0,  4.0},
        {5.0,  6.0,  7.0,  8.0},
        {9.0, 10.0, 11.0, 12.0}
    };

    float dataC[4][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, NULL);

    mu_assert_double_eq( 1.0, C.data[0]);
    mu_assert_double_eq( 5.0, C.data[1]);
    mu_assert_double_eq( 9.0, C.data[2]);

    mu_assert_double_eq( 2.0, C.data[3]);
    mu_assert_double_eq( 6.0, C.data[4]);
    mu_assert_double_eq(10.0, C.data[5]);

    mu_assert_double_eq( 3.0, C.data[6]);
    mu_assert_double_eq( 7.0, C.data[7]);
    mu_assert_double_eq(11.0, C.data[8]);

    mu_assert_double_eq( 4.0, C.data[9] );
    mu_assert_double_eq( 8.0, C.data[10]);
    mu_assert_double_eq(12.0, C.data[11]);
}

MU_TEST(test_trans_success_c) {
    MTX_Error_E error;

    float dataA[3][4] = {
        {1.0,  2.0,  3.0,  4.0},
        {5.0,  6.0,  7.0,  8.0},
        {9.0, 10.0, 11.0, 12.0}
    };

    float dataC[4][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq( 1.0, C.data[0]);
    mu_assert_double_eq( 5.0, C.data[1]);
    mu_assert_double_eq( 9.0, C.data[2]);

    mu_assert_double_eq( 2.0, C.data[3]);
    mu_assert_double_eq( 6.0, C.data[4]);
    mu_assert_double_eq(10.0, C.data[5]);

    mu_assert_double_eq( 3.0, C.data[6]);
    mu_assert_double_eq( 7.0, C.data[7]);
    mu_assert_double_eq(11.0, C.data[8]);

    mu_assert_double_eq( 4.0, C.data[9] );
    mu_assert_double_eq( 8.0, C.data[10]);
    mu_assert_double_eq(12.0, C.data[11]);
}

MU_TEST(test_trans_success_c_rowVect) {
    MTX_Error_E error;

    float dataA[3][1] = {
        {1.0},
        {5.0},
        {9.0}
    };

    float dataC[1][3] = {0};

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(1.0, C.data[0]);
    mu_assert_double_eq(5.0, C.data[1]);
    mu_assert_double_eq(9.0, C.data[2]);
}

MU_TEST(test_trans_success_c_colVect) {
    MTX_Error_E error;

    float dataA[1][4] = {{1.0,  2.0,  3.0,  4.0}};

    float dataC[4][1] = {0};;

    MTX_Matrix_S A = {
        .rows = 1,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 1,
        .data = (float *)dataC
    };

    MTX_trans(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(1.0, C.data[0]);
    mu_assert_double_eq(2.0, C.data[1]);
    mu_assert_double_eq(3.0, C.data[2]);
    mu_assert_double_eq(4.0, C.data[3]);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_trans_fail_dim_c_rows);
    MU_RUN_TEST(test_trans_fail_dim_c_cols);

    MU_RUN_TEST(test_trans_fail_null_c);
    MU_RUN_TEST(test_trans_fail_null_c_data);
    MU_RUN_TEST(test_trans_fail_null_a);
    MU_RUN_TEST(test_trans_fail_null_a_data);
    
    MU_RUN_TEST(test_trans_success_err_null);

    MU_RUN_TEST(test_trans_success_c);
    MU_RUN_TEST(test_trans_success_c_rowVect);
    MU_RUN_TEST(test_trans_success_c_colVect);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}