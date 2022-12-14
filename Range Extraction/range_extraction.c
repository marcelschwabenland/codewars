#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

char *range_extraction(const int *args, size_t n) {
  if (n == 0) {
    return NULL;
  }

  bool flag = false;
  int string_index = 0, range_size = 1, size = (int)n;
  char *out = malloc(sizeof(char));

  for (int i = 0; i < size; i++) {
    if (abs(args[i] - args[i + 1]) == 1) {
      if(flag == false) {
        if (args[i] < 0) {
          out[string_index] = '-';
          out = realloc(out, (++string_index) + 1);
        }
        if (args[i] >= -9 && args[i] <= 9) {
          out[string_index] = abs(args[i]) + '0';
          out = realloc(out, (++string_index) + 1);
        } else {
          char number[16] = {'\0'};
          sprintf(number, "%d", abs(args[i]));
          for (int buffer_index = 0; buffer_index < 16 && number[buffer_index] != '\0'; buffer_index++) {
            out[string_index] = number[buffer_index];
            out = realloc(out, (++string_index) + 1);
          }
        }

        flag = true;
      }
      range_size++;
    } else if (abs(args[i] - args[i + 1]) > 1 && flag == true) {
      if (range_size > 2) {
        out[string_index] = '-';
        out = realloc(out, (++string_index) + 1);
      } else {
        out[string_index] = ',';
        out = realloc(out, (++string_index) + 1);
      }
      if (args[i] < 0) {
        out[string_index] = '-';
        out = realloc(out, (++string_index) + 1);
      }
      if (args[i] >= -9 && args[i] <= 9) {
        out[string_index] = abs(args[i]) + '0';
        out = realloc(out, (++string_index) + 1);
      } else {
        char number[16] = {'\0'};
        sprintf(number, "%d", abs(args[i]));
        for (int buffer_index = 0; buffer_index < 16 && number[buffer_index] != '\0'; buffer_index++) {
          out[string_index] = number[buffer_index];
          out = realloc(out, (++string_index) + 1);
        }
      }
      if(i < size - 1) {
        out[string_index] = ',';
        out = realloc(out, (++string_index) + 1);
      } else {
        out[string_index] = '\0';
      }
      range_size = 1;
      flag = false;
    } else if (abs(args[i] - args[i + 1]) > 1 && flag == false) {
      if (args[i] < 0) {
        out[string_index] = '-';
        out = realloc(out, (++string_index) + 1);
      }
      if (args[i] >= -9 && args[i] <= 9) {
        out[string_index] = abs(args[i]) + '0';
        out = realloc(out, (++string_index) + 1);
      } else {
        char number[16] = {'\0'};
        sprintf(number, "%d", abs(args[i]));
        for (int buffer_index = 0; buffer_index < 16 && number[buffer_index] != '\0'; buffer_index++) {
          out[string_index] = number[buffer_index];
          out = realloc(out, (++string_index) + 1);
        }
      }

      if(i < size - 1) {
        out[string_index] = ',';
        out = realloc(out, (++string_index) + 1);
      } else {
        out[string_index] = '\0';
      }
    }
  }
  return out;
}

int main() {
  const int r1[23] = {-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
  const int r2[20] = {-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20};
  const int r3[17] = {-41,-40,-39,-31,-30,-29,-28,-21,-20,-19,-18,-8,-7,-6,-5,-2,-1};

  char *s1 = range_extraction(r1, 23);
  char *s2 = range_extraction(r2, 20);
  char *s3 = range_extraction(r3, 17);
  printf("%s\n", s1);
  printf("%s\n", s2);
  printf("%s\n", s3);

  free(s1);
  free(s2);
  free(s3);
  return 0;
}