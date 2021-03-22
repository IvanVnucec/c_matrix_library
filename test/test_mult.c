/**
 * @file test_mult.c
 * @author Ivan Vnucec
 * @brief MTX_mult function test file
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

MU_TEST(test_mult_fail_dim_a) {
    MTX_Error_E error;

    float dataA[2][3];
    float dataB[2][3];
    float dataC[2][3];

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_mult_fail_dim_b) {
    MTX_Error_E error;

    float dataA[2][3];
    float dataB[2][3];
    float dataC[2][3];

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 2,
        .cols = 2,
        .data = (float *)dataC
    };

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_mult_fail_dim_c) {
    MTX_Error_E error;

    float dataA[2][3];
    float dataB[3][3];
    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 2,
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

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_mult_fail_null_a) {
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

    MTX_mult(&C, NULL, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_mult_fail_null_a_data) {
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

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_mult_fail_null_b) {
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

    MTX_mult(&C, &A, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_mult_fail_null_b_data) {
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

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_mult_fail_null_c) {
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

    MTX_mult(NULL, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_mult_fail_null_c_data) {
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

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_mult_success_err_null) {
    float dataA[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
    };

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[2][3];

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_mult(&C, &A, &B, NULL);

    mu_assert_double_eq(30.0, C.data[0]);
    mu_assert_double_eq(36.0, C.data[1]);
    mu_assert_double_eq(42.0, C.data[2]);

    mu_assert_double_eq(66.0, C.data[3]);
    mu_assert_double_eq(81.0, C.data[4]);
    mu_assert_double_eq(96.0, C.data[5]);
}

MU_TEST(test_mult_success_C_A_B) {
    MTX_Error_E error;

    float dataA[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
    };

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[2][3];

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(30.0, C.data[0]);
    mu_assert_double_eq(36.0, C.data[1]);
    mu_assert_double_eq(42.0, C.data[2]);

    mu_assert_double_eq(66.0, C.data[3]);
    mu_assert_double_eq(81.0, C.data[4]);
    mu_assert_double_eq(96.0, C.data[5]);
}

MU_TEST(test_mult_success_C_Arow_Bcol) {
    MTX_Error_E error;

    float dataA[2][1] = {
        {1.0},
        {2.0},
    };

    float dataB[1][3] = {
        {1.0, 2.0, 3.0}
    };

    float dataC[2][3];

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 1,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(1.0, C.data[0]);
    mu_assert_double_eq(2.0, C.data[1]);
    mu_assert_double_eq(3.0, C.data[2]);

    mu_assert_double_eq(2.0, C.data[3]);
    mu_assert_double_eq(4.0, C.data[4]);
    mu_assert_double_eq(6.0, C.data[5]);
}

MU_TEST(test_mult_success_C_Acol_Brow) {
    MTX_Error_E error;

    float dataA[1][3] = {
        {1.0, 2.0, 3.0},
    };

    float dataB[3][1] = {
        {1.0},
        {2.0},
        {3.0}
    };

    float dataC[1][1];

    MTX_Matrix_S A = {
        .rows = 1,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 1,
        .data = (float *)dataB
    };

    MTX_Matrix_S C = {
        .rows = 1,
        .cols = 1,
        .data = (float *)dataC
    };

    MTX_mult(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(14.0, C.data[0]);
}

MU_TEST(test_mult_fail_inplace_A_A_B) {
    MTX_Error_E error;

    float dataA[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
    };

    float dataB[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataB
    };

    MTX_mult(&A, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_INPLACE);
}

MU_TEST(test_mult_fail_inplace_A_B_A) {
    MTX_Error_E error;

    float dataA[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
    };

    float dataB[2][2] = {
        {1.0, 2.0},
        {3.0, 4.0},
    };

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_Matrix_S B = {
        .rows = 2,
        .cols = 2,
        .data = (float *)dataB
    };

    MTX_mult(&A, &B, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_INPLACE);
}

MU_TEST(test_mult_fail_inplace_A_A_A) {
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

    MTX_mult(&A, &A, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_INPLACE);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_mult_fail_dim_a);
    MU_RUN_TEST(test_mult_fail_dim_b);
    MU_RUN_TEST(test_mult_fail_dim_c);

    MU_RUN_TEST(test_mult_fail_null_a);
    MU_RUN_TEST(test_mult_fail_null_a_data);
    MU_RUN_TEST(test_mult_fail_null_b);
    MU_RUN_TEST(test_mult_fail_null_b_data);
    MU_RUN_TEST(test_mult_fail_null_c);
    MU_RUN_TEST(test_mult_fail_null_c_data);

    MU_RUN_TEST(test_mult_fail_inplace_A_A_B);
    MU_RUN_TEST(test_mult_fail_inplace_A_B_A);
    MU_RUN_TEST(test_mult_fail_inplace_A_A_A);
    
    MU_RUN_TEST(test_mult_success_err_null);

    MU_RUN_TEST(test_mult_success_C_A_B);
    MU_RUN_TEST(test_mult_success_C_Arow_Bcol);
    MU_RUN_TEST(test_mult_success_C_Acol_Brow);
}

int main(int argc, char *argv[]) {

    (void)argc;
    (void)argv;

	MU_RUN_SUITE(test_suite);
	MU_REPORT();
    
	return MU_EXIT_CODE;
}