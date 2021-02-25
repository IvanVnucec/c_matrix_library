#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_print_fail_err_null) {
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

    MTX_print(&A, NULL);

    mu_check(1);
}

MU_TEST(test_print_fail_null_c) {
    MTX_Error_E error;

    MTX_print(NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_print_fail_null_c_data) {
    MTX_Error_E error;

    MTX_Matrix_S C = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_print(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_print_success) {
    MTX_Error_E error;

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

    MTX_print(&C, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_print_fail_err_null);

    MU_RUN_TEST(test_print_fail_null_c);
    MU_RUN_TEST(test_print_fail_null_c_data);
    
    MU_RUN_TEST(test_print_success);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}