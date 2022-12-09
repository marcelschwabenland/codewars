#include <stdbool.h>

bool validParentheses(const char *str_in) {
  int open_bracket_count = 0;
  while (*str_in != '\0') {
    if(*str_in == '(') {
      open_bracket_count++;
    } else if (*str_in == ')' && open_bracket_count > 0) {
      open_bracket_count--;
    } else if (*str_in == ')' && open_bracket_count == 0) {
      return false;
    }
    str_in++;
  }

  if (open_bracket_count == 0) {
    return true;
  }
  return false;
}

int main() {
  char s1[3] = "()";
  char s2[7] = ")(()))";
  char s3[3] = "(";
  char s4[15] = "(())((()())())";
  char s5[7] = "hi())(";

  printf("1 %d\n", validParentheses(s1));
  printf("0 %d\n", validParentheses(s2));
  printf("0 %d\n", validParentheses(s3));
  printf("1 %d\n", validParentheses(s4));
  printf("0 %d\n", validParentheses(s5));

  return 0;
}