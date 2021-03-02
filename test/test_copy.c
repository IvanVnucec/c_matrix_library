#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_copy_fail_err_null) {
    MTX_Error_E errorLocal = MTX_Matrix_ERROR_NONE;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3] = {
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0}
    };

    MTX_Matrix_S A;
    MTX_Matrix_S C;

    MTX_init(&A, 3, 3, (float *)dataA, &errorLocal);
    MTX_init(&C, 3, 3, (float *)dataC, &errorLocal);

    MTX_copy(&C, &A, NULL);

    mu_assert_double_eq(1.0, C.data[0]);
    mu_assert_double_eq(2.0, C.data[1]);
    mu_assert_double_eq(3.0, C.data[2]);

    mu_assert_double_eq(4.0, C.data[3]);
    mu_assert_double_eq(5.0, C.data[4]);
    mu_assert_double_eq(6.0, C.data[5]);

    mu_assert_double_eq(7.0, C.data[6]);
    mu_assert_double_eq(8.0, C.data[7]);
    mu_assert_double_eq(9.0, C.data[8]);
}

MU_TEST(test_copy_fail_dim_a) {
    MTX_Error_E error = MTX_Matrix_ERROR_NONE;

    float dataA[4][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A;
    MTX_Matrix_S C;

    MTX_init(&A, 4, 3, (float *)dataA, &error);
    MTX_init(&C, 3, 3, (float *)dataC, &error);

    MTX_copy(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_copy_fail_dim_c) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[4][3];

    MTX_Matrix_S A;
    MTX_Matrix_S C;

    MTX_init(&A, 3, 3, (float *)dataA, &error);
    MTX_init(&C, 4, 3, (float *)dataC, &error);

    MTX_copy(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_DIMENSIONS);
}

MU_TEST(test_copy_fail_null_a) {
    MTX_Error_E error;

    float dataC[3][3];

    MTX_Matrix_S C;

    MTX_init(&C, 3, 3, (float *)dataC, &error);

    MTX_copy(&C, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_copy_fail_null_a_data) {
    MTX_Error_E error;

    float dataC[3][3];

    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = NULL
    };

    MTX_Matrix_S C;

    MTX_init(&C, 3, 3, (float *)dataC, &error);

    MTX_copy(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_copy_fail_null_c) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S A;

    MTX_init(&A, 3, 3, (float *)dataA, &error);

    MTX_copy(NULL, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_copy_fail_null_c_data) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_Matrix_S A;

    MTX_init(&A, 3, 3, (float *)dataA, &error);

    MTX_copy(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_copy_success_C_A) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    float dataC[3][3];

    MTX_Matrix_S A;
    MTX_Matrix_S C;

    MTX_init(&A, 3, 3, (float *)dataA, &error);
    MTX_init(&C, 3, 3, (float *)dataC, &error);

    MTX_copy(&C, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(1.0, C.data[0]);
    mu_assert_double_eq(2.0, C.data[1]);
    mu_assert_double_eq(3.0, C.data[2]);
    mu_assert_double_eq(4.0, C.data[3]);
    mu_assert_double_eq(5.0, C.data[4]);
    mu_assert_double_eq(6.0, C.data[5]);
    mu_assert_double_eq(7.0, C.data[6]);
    mu_assert_double_eq(8.0, C.data[7]);
    mu_assert_double_eq(9.0, C.data[8]);
}

MU_TEST(test_copy_success_A_A) {
    MTX_Error_E error;

    float dataA[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S A;

    MTX_init(&A, 3, 3, (float *)dataA, &error);

    MTX_copy(&A, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(1.0, A.data[0]);
    mu_assert_double_eq(2.0, A.data[1]);
    mu_assert_double_eq(3.0, A.data[2]);
    mu_assert_double_eq(4.0, A.data[3]);
    mu_assert_double_eq(5.0, A.data[4]);
    mu_assert_double_eq(6.0, A.data[5]);
    mu_assert_double_eq(7.0, A.data[6]);
    mu_assert_double_eq(8.0, A.data[7]);
    mu_assert_double_eq(9.0, A.data[8]);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_copy_fail_err_null);

    MU_RUN_TEST(test_copy_fail_dim_a);
    MU_RUN_TEST(test_copy_fail_dim_c);

    MU_RUN_TEST(test_copy_fail_null_a);
    MU_RUN_TEST(test_copy_fail_null_a_data);
    MU_RUN_TEST(test_copy_fail_null_c);
    MU_RUN_TEST(test_copy_fail_null_c_data);
    
    MU_RUN_TEST(test_copy_success_C_A);
    MU_RUN_TEST(test_copy_success_A_A);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}