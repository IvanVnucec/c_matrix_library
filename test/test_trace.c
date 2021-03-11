/**
 * @file test_trace.c
 * @author Ivan Vnucec
 * @brief MTX_trace function test file
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

MU_TEST(test_trace_fail_null_t) {
    MTX_Error_E error;

    float dataA[2][2] = {
        {1.0, 2.0},
        {2.0, 1.0}
    };

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 2,
        .data = (float *)dataA
    };

    MTX_trace(NULL, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trace_fail_null_a) {
    MTX_Error_E error;

    float t;

    MTX_trace(&t, NULL, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trace_fail_null_a_data) {
    MTX_Error_E error;

    float t;
    MTX_Matrix_S A = {
        .rows = 3,
        .cols = 3,
        .data = (float *)NULL
    };

    MTX_trace(&t, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NULL);
}

MU_TEST(test_trace_fail_dim_a) {
    MTX_Error_E error;

    float t;
    float dataA[2][3];

    MTX_Matrix_S A = {
        .rows = 2,
        .cols = 3,
        .data = (float *)dataA
    };

    MTX_trace(&t, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NOT_SQUARE);
}

MU_TEST(test_trace_success_err_null) {
    float t;

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

    MTX_trace(&t, &A, NULL);

    mu_assert_double_eq(15.0, t);
}

MU_TEST(test_trace_success_a) {
    MTX_Error_E error;

    float t;

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

    MTX_trace(&t, &A, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(15.0, t);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_trace_fail_null_t);
    MU_RUN_TEST(test_trace_fail_null_a);
    MU_RUN_TEST(test_trace_fail_null_a_data);
    
    MU_RUN_TEST(test_trace_fail_dim_a);

    MU_RUN_TEST(test_trace_success_err_null);
    MU_RUN_TEST(test_trace_success_a);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}