#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "gauss-elimination.h"

#define EPSILON 1e-6

// Prototypes of your functions
void gauss_eliminationl(double *matrix, int rows, int cols, double* b);
void back_substitution(double *matrix, int rows, int cols, double *b, double *x);

void test_matrix_index() {
    // Testing a 3x3 matrix indices
    assert(matrix_index(0, 0, 3) == 0);
    assert(matrix_index(1, 2, 3) == 5);
    assert(matrix_index(2, 2, 3) == 8);
    printf("Test matrix_index: PASSED\n");
}

void test_full_solver() {
    // Simple system: 
    // 2x +  y = 5
    // 4x - 6y = -2
    // Expected Solution: x = 1.75, y = 1.5
    
    double matrix[] = {2.0, 1.0, 4.0, -6.0};
    double b[] = {5.0, -2.0};
    double x[2];

    gauss_eliminationl(matrix, 2, 2, b);
    back_substitution(matrix, 2, 2, b, x);

    assert(fabs(x[0] - 1.75) < EPSILON);
    assert(fabs(x[1] - 1.50) < EPSILON);
    printf("Test Full Solver: PASSED\n");
}

int main() {
    printf("Running suite...\n");
    test_matrix_index();
    test_full_solver();
    printf("All tests passed!\n");
    return 0;
}
