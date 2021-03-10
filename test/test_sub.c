/**
 * @file test_sub.c
 * @author Ivan Vnucec
 * @brief MTX_sub function test file
 * @date 2021-03-03
 * 
 * @copyright WTFPL – Do What the Fuck You Want to Public License. See .LICENSE.md file for more information.
 * 
 */

#include "minunit.h"
#include "matrix_math.h"

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_sub_fail_dim_a_rows) {
    MTX_Error_E error;

    float dataA[4][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {7.0, 8.0, 9.0}
    };

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_sub_fail_dim_a_cols) {
    MTX_Error_E error;

    float dataA[3][4] = {
        {1.0, 2.0, 3.0, 0.0},
        {4.0, 5.0, 6.0, 0.0},
        {7.0, 8.0, 9.0, 0.0},
    };

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_sub_fail_dim_b_rows) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataB[4][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_sub_fail_dim_b_cols) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataB[3][4] = {
        {1.0, 2.0, 3.0, 0.0},
        {4.0, 5.0, 6.0, 0.0},
        {7.0, 8.0, 9.0, 0.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_sub_fail_dim_c_rows) {
    MTX_Error_E error;

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

    float dataC[4][3];

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

    MTX_Matrix_S C = {
        .rows = 4,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_sub_fail_dim_c_cols) {
    MTX_Error_E error;

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

    float dataC[3][4];

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

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 4,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_sub_fail_null_a) {
    MTX_Error_E error;

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, NULL, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_sub_fail_null_a_data) {
    MTX_Error_E error;

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = NULL
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_sub_fail_null_b) {
    MTX_Error_E error;

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

    MTX_sub(&C, &A, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_sub_fail_null_b_data) {
    MTX_Error_E error;

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

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_sub_fail_null_c) {
    MTX_Error_E error;

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

    MTX_sub(NULL, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_sub_fail_null_c_data) {
    MTX_Error_E error;

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

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_sub_success_err_null) {
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

    MTX_sub(&A, &A, &B, NULL);

    mu_assert_double_eq(0.0, A.data[0]);
    mu_assert_double_eq(0.0, A.data[1]);
    mu_assert_double_eq(0.0, A.data[2]);
    mu_assert_double_eq(0.0, A.data[3]);
    mu_assert_double_eq(0.0, A.data[4]);
    mu_assert_double_eq(0.0, A.data[5]);
    mu_assert_double_eq(0.0, A.data[6]);
    mu_assert_double_eq(0.0, A.data[7]);
    mu_assert_double_eq(0.0, A.data[8]);
}

MU_TEST(test_sub_success_C_A_B) {
    MTX_Error_E error;

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

    float dataC[3][3];

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

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

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

MU_TEST(test_sub_success_A_A_B) {
    MTX_Error_E error;

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

    MTX_sub(&A, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, A.data[0]);
    mu_assert_double_eq(0.0, A.data[1]);
    mu_assert_double_eq(0.0, A.data[2]);
    mu_assert_double_eq(0.0, A.data[3]);
    mu_assert_double_eq(0.0, A.data[4]);
    mu_assert_double_eq(0.0, A.data[5]);
    mu_assert_double_eq(0.0, A.data[6]);
    mu_assert_double_eq(0.0, A.data[7]);
    mu_assert_double_eq(0.0, A.data[8]);
}

MU_TEST(test_sub_success_A_B_A) {
    MTX_Error_E error;

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

    MTX_sub(&A, &B, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, A.data[0]);
    mu_assert_double_eq(0.0, A.data[1]);
    mu_assert_double_eq(0.0, A.data[2]);
    mu_assert_double_eq(0.0, A.data[3]);
    mu_assert_double_eq(0.0, A.data[4]);
    mu_assert_double_eq(0.0, A.data[5]);
    mu_assert_double_eq(0.0, A.data[6]);
    mu_assert_double_eq(0.0, A.data[7]);
    mu_assert_double_eq(0.0, A.data[8]);
}

MU_TEST(test_sub_success_A_A_A) {
    MTX_Error_E error;

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

    MTX_sub(&A, &A, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, A.data[0]);
    mu_assert_double_eq(0.0, A.data[1]);
    mu_assert_double_eq(0.0, A.data[2]);
    mu_assert_double_eq(0.0, A.data[3]);
    mu_assert_double_eq(0.0, A.data[4]);
    mu_assert_double_eq(0.0, A.data[5]);
    mu_assert_double_eq(0.0, A.data[6]);
    mu_assert_double_eq(0.0, A.data[7]);
    mu_assert_double_eq(0.0, A.data[8]);
}

MU_TEST(test_sub_success_C_A_B_colVect) {
    MTX_Error_E error;

    float dataA[1][3] = {
        {1, 4, 7}
    };

    float dataB[1][3] = {
        {1, 4, 7}
    };

    float dataC[1][3];

    MTX_Matrix_S A = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
}

MU_TEST(test_sub_success_C_A_B_rowVect) {
    MTX_Error_E error;

    float dataA[3][1] = {
        {1.0},
        {4.0},
        {7.0}
    };

    float dataB[3][1] = {
        {1.0},
        {4.0},
        {7.0}
    };

    float dataC[3][1] = {
        {1.0},
        {1.0},
        {1.0}
    };

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataC
    };

    MTX_sub(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(0.0, C.data[0]);
    mu_assert_double_eq(0.0, C.data[1]);
    mu_assert_double_eq(0.0, C.data[2]);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_sub_fail_dim_a_rows);
    MU_RUN_TEST(test_sub_fail_dim_a_cols);
    MU_RUN_TEST(test_sub_fail_dim_b_rows);
    MU_RUN_TEST(test_sub_fail_dim_b_cols);
    MU_RUN_TEST(test_sub_fail_dim_c_rows);
    MU_RUN_TEST(test_sub_fail_dim_c_cols);

    MU_RUN_TEST(test_sub_fail_null_a);
    MU_RUN_TEST(test_sub_fail_null_a_data);
    MU_RUN_TEST(test_sub_fail_null_b);
    MU_RUN_TEST(test_sub_fail_null_b_data);
    MU_RUN_TEST(test_sub_fail_null_c);
    MU_RUN_TEST(test_sub_fail_null_c_data);
    
    MU_RUN_TEST(test_sub_success_err_null);

    MU_RUN_TEST(test_sub_success_C_A_B);
    MU_RUN_TEST(test_sub_success_A_A_B);
    MU_RUN_TEST(test_sub_success_A_B_A);
    MU_RUN_TEST(test_sub_success_A_A_A);

    MU_RUN_TEST(test_sub_success_C_A_B_rowVect);
    MU_RUN_TEST(test_sub_success_C_A_B_colVect);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}