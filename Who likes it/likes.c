#include <stdlib.h>
#include <stdio.h>

char *insert_into_string(char *out, char *name) {
  while (*name != '\0') {
    *out = *name;
    out++;
    name++;
  }

  return out;
}

// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite
char *likes(size_t n, const char **names) {
  char *out = calloc(128, sizeof(char));
  char *zero = "no one likes this\0";
  char *one = "0 likes this\0";
  char *two = "0 and 0 like this\0";
  char *three = "0, 0 and 0 like this\0";
  char *more = "0, 0 and 1 others like this\0";

  int namecount = 0;
  char *start = out;
  
  switch (n) {
  case 0:
    while (*zero != '\0') {
      *out = *zero;
      out++;
      zero++;
    }
    
    *out = '\0';
    printf("%s\n", start);
    break;
  case 1:
    while (*one != '\0') {
      if(*one == '0') {
        char *name = names[namecount];
        out = insert_into_string(out, name);
        namecount++;
        one++;
      } else {
        *out = *one;
        out++;
        one++;
      }
    }
    *out = '\0';
    printf("%s\n", start);
    break;
  case 2:
    while (*two != '\0') {
      if(*two == '0') {
        char *name = names[namecount];
        out = insert_into_string(out, name);
        namecount++;
        two++;
      } else {
        *out = *two;
        out++;
        two++;
      }
    }
    *out = '\0';
    printf("%s\n", start);
    break;
  case 3:
    while (*three != '\0') {
      if(*three == '0') {
        char *name = names[namecount];
        out = insert_into_string(out, name);
        namecount++;
        three++;
      } else {
        *out = *three;
        out++;
        three++;
      }
    }
    *out = '\0';
    printf("%s\n", start);
    break;
  default:
    while (*more != '\0') {
      if(*more == '0') {
        char *name = names[namecount];
        out = insert_into_string(out, name);
        namecount++;
        more++;
      } else if (*more == '1') {
        char number[3];
        if(n >= 10) {
          n = n - 2;
          number[1] = (char)((n % 10) + '0');
          number[0] = (char)((((n / 10) % 10)) + '0');
          number[2] = '\0';
          out = insert_into_string(out, number);
        } else {
          *out = (char)((n - 2) + '0');
          out++;
        }        
        more++;
      } else {
        *out = *more;
        out++;
        more++;
      }
    }
    *out = '\0';
    printf("%s\n", start);
    break;
  }
  return start;
}

int main() {
  char *case1[1] = {"Peter"};
  char *case2[2] = {"Jacob", "Alex"};
  char *case3[3] = {"Max", "John", "Mark"};
  char *case4[4] = {"Alex", "Jacob", "Mark", "Max"};

  likes(0, NULL);
  likes(1, case1);
  likes(2, case2);
  likes(3, case3);
  likes(61, case4);

  return 0;
}