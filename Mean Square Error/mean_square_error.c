#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double mean_square_error(size_t n, const int *a, const int *b) {
  double sum_diff = 0;
  
  for (size_t index = 0; index < n; index++) {
    sum_diff += (double)abs(a[index] - b[index]) * (double)abs(a[index] - b[index]);
  }

  return (double)(sum_diff / n);
}

int main() {
  int a1[3] = {1,2,3};
  int a2[3] = {4,5,6};
  int a3[4] = {10, 20, 10, 2};
  int a4[4] = {10,25,5,-2};
  int a5[2] = {-1,0};
  int a6[2] = {0,-1};

  printf("%f\n", mean_square_error(3, a1, a2));
  printf("%f\n", mean_square_error(4, a3, a4));
  printf("%f\n", mean_square_error(2, a5, a6));

  return 0;
}