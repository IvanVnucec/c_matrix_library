#include "minunit.h"
#include "matrix_math.h"


void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_add) {
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

    MTX_add(&C, &A, &B, &error);

    mu_check(error == MTX_Matrix_ERROR_NONE);
    mu_assert_double_eq(C.data[0],  2.0);
    mu_assert_double_eq(C.data[1],  4.0);
    mu_assert_double_eq(C.data[2],  6.0);
    mu_assert_double_eq(C.data[3],  8.0);
    mu_assert_double_eq(C.data[4], 10.0);
    mu_assert_double_eq(C.data[5], 12.0);
    mu_assert_double_eq(C.data[6], 14.0);
    mu_assert_double_eq(C.data[7], 16.0);
    mu_assert_double_eq(C.data[8], 18.0);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_add);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}