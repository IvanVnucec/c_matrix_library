#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_mult_fail_err_null) {
    float dataA[2][3];
    float dataB[3][3];
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

    mu_check(1);
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
    mu_assert_double_eq(C.data[0], 30.0);
    mu_assert_double_eq(C.data[1], 36.0);
    mu_assert_double_eq(C.data[2], 42.0);

    mu_assert_double_eq(C.data[3], 66.0);
    mu_assert_double_eq(C.data[4], 81.0);
    mu_assert_double_eq(C.data[5], 96.0);
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
    MU_RUN_TEST(test_mult_fail_err_null);

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
    
    MU_RUN_TEST(test_mult_success_C_A_B);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}