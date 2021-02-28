#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_init_fail_err_null) {
    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C;

    MTX_init(&C, 3, 3, (float *)dataC, NULL);

    mu_check(1);
}

MU_TEST(test_init_fail_null_c) {
    MTX_Error_E error;

    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_init(NULL, 3, 3, (float *)dataC, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_init_fail_null_c_data) {
    MTX_Error_E error;

    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C;

    MTX_init(&C, 3, 3, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_init_fail_dims_zero_rows) {
    MTX_Error_E error;

    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C;

    MTX_init(&C, 0, 3, (float *)dataC, &error);

    mu_check(error == MTX_Matrix_ERROR_ZERO_DIMS);
}

MU_TEST(test_init_fail_dims_zero_cols) {
    MTX_Error_E error;

    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C;

    MTX_init(&C, 3, 0, (float *)dataC, &error);

    mu_check(error == MTX_Matrix_ERROR_ZERO_DIMS);
}

MU_TEST(test_init_success_c) {
    MTX_Error_E error;

    float dataC[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    MTX_Matrix_S C;

    MTX_init(&C, 3, 3, (float *)dataC, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_check(C.rows == 3);
    mu_check(C.cols == 3);
    mu_check(C.data == dataC);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_init_fail_err_null);

    MU_RUN_TEST(test_init_fail_null_c);
    MU_RUN_TEST(test_init_fail_null_c_data);

    MU_RUN_TEST(test_init_fail_dims_zero_rows);
    MU_RUN_TEST(test_init_fail_dims_zero_cols);
    
    MU_RUN_TEST(test_init_success_c);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}