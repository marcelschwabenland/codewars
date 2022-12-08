#include <stdio.h>
#include <stdbool.h>

bool alphanumeric(const char* strin) {
  if (strin[0] == '\0') {
    return false;
  }

  while (*strin != '\0') {
    if((*strin >= '0' && *strin <= '9') || (*strin >= 'A' && *strin <= 'Z') || (*strin >= 'a' && *strin <= 'z')) {
      // do nothing
    } else {
      return false;
    }
    strin++;
  }
  return true;
}

int main() {
  printf("%d\n", alphanumeric("hello_world"));
  printf("%d\n", alphanumeric("PassW0rd"));
  printf("%d\n", alphanumeric("     "));
  printf("%d\n", alphanumeric("a"));
  printf("%d\n", alphanumeric(""));

  return 0;
}