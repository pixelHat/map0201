#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gauss-elimination.h"

void fill_random(double *matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int index = matrix_index(i, j, cols);
      matrix[index] = ((double) rand() / RAND_MAX) * 10.0;
    }
  }  
}

void print_matrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void gauss_eliminationl(double *matrix, int rows, int cols, double* b) {
  for (int k = 0; k < rows; k++) {
    #pragma omp parallel for
    for (int i = k + 1; i < rows; i++) {
      double m = matrix[matrix_index(i,k,cols)] / matrix[matrix_index(k,k,cols)];
      for (int j = k ; j < rows; j++) {
        matrix[matrix_index(i,j,cols)] = matrix[matrix_index(i,j,cols)] - m * matrix[matrix_index(k,j,cols)];
      }
      b[i] = b[i] - m * b[k];
    }
  }
}

void back_substitution(double *matrix, int rows, int cols, double *b, double *x) {
    for (int i = rows - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < rows; j++) {
            sum += matrix[matrix_index(i, j, cols)] * x[j];
        }
        x[i] = (b[i] - sum) / matrix[matrix_index(i, i, cols)];
    }
}

#ifndef TESTING
int main(int argc, char* argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("Argument %d: %s\n", i, argv[i]);
  }

  int rows = atoi(argv[1]);
  int cols = rows;
  double* matrix = (double*) malloc(rows * cols * sizeof(double));
  double* x = (double*) calloc(rows, sizeof(double));
  double* b = (double*) calloc(rows, sizeof(double));
  for (int i = 1; i <= rows; i++) {
    b[i] = i;
  }

  srand(time(NULL));
  fill_random(matrix, rows, cols);

  if (rows <= 5) {
    print_matrix(matrix, rows, cols);
    printf("-----\n");
  }

  gauss_eliminationl(matrix, rows, cols, b);
  back_substitution(matrix, rows, cols, b, x);

  if (rows <= 5) {
    print_matrix(matrix, rows, cols);

    printf("x = \n");

    for (int i = 0; i < rows; i++) {
      printf("%f ", x[i]);
    }
  }

  free(matrix);
  return 0;
}
#endif
