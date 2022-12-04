#include <stdio.h>

int digital_root(int n) {
  int sum = 0;

  while (n != 0) {
    sum += (n % 10);
    n = n/10;
  }

  return sum >= 10 ? digital_root(sum) : sum;
}

int main(int argc, char const *argv[]) {

  printf("%d\n", digital_root(16)); // 1 + 6 = 7
  printf("%d\n", digital_root(195)); // 9 + 4 + 2 = 15  -->  1 + 5 = 6
  printf("%d\n", digital_root(992));
  printf("%d\n", digital_root(167346));
  printf("%d\n", digital_root(0));

  return 0;
}
