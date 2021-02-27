#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_trans_fail_err_null) {
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

    mu_check(1);
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
    mu_assert_double_eq(C.data[0],   1.0);
    mu_assert_double_eq(C.data[1],   5.0);
    mu_assert_double_eq(C.data[2],   9.0);

    mu_assert_double_eq(C.data[3],   2.0);
    mu_assert_double_eq(C.data[4],   6.0);
    mu_assert_double_eq(C.data[5],  10.0);

    mu_assert_double_eq(C.data[6],   3.0);
    mu_assert_double_eq(C.data[7],   7.0);
    mu_assert_double_eq(C.data[8],  11.0);

    mu_assert_double_eq(C.data[9],   4.0);
    mu_assert_double_eq(C.data[10],  8.0);
    mu_assert_double_eq(C.data[11], 12.0);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_trans_fail_err_null);

    MU_RUN_TEST(test_trans_fail_dim_c_rows);
    MU_RUN_TEST(test_trans_fail_dim_c_cols);

    MU_RUN_TEST(test_trans_fail_null_c);
    MU_RUN_TEST(test_trans_fail_null_c_data);
    
    MU_RUN_TEST(test_trans_success_c);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}