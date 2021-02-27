#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_identity_fail_err_null) {
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

    MTX_identity(&C, NULL);

    mu_check(1);
}

MU_TEST(test_identity_fail_dim_c) {
    MTX_Error_E error;

    float dataC[2][3];

    MTX_Matrix_S C = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_identity(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NOT_SQUARE);
}

MU_TEST(test_identity_fail_null_c) {
    MTX_Error_E error;

    MTX_identity(NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_identity_fail_null_c_data) {
    MTX_Error_E error;

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_identity(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_identity_success_c) {
    MTX_Error_E error;

    float dataC[3][3];

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)dataC
    };

    MTX_identity(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(C.data[0], 1.0);
    mu_assert_double_eq(C.data[1], 0.0);
    mu_assert_double_eq(C.data[2], 0.0);
    mu_assert_double_eq(C.data[3], 0.0);
    mu_assert_double_eq(C.data[4], 1.0);
    mu_assert_double_eq(C.data[5], 0.0);
    mu_assert_double_eq(C.data[6], 0.0);
    mu_assert_double_eq(C.data[7], 0.0);
    mu_assert_double_eq(C.data[8], 1.0);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_identity_fail_err_null);

    MU_RUN_TEST(test_identity_fail_dim_c);

    MU_RUN_TEST(test_identity_fail_null_c);
    MU_RUN_TEST(test_identity_fail_null_c_data);
    
    MU_RUN_TEST(test_identity_success_c);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}