#include <string.h>

void reverse_string(char *s, int sSize) {
  char *p1 = s;
  char *p2 = s + sSize - 1;

  while (p1 < p2) {
    char temp = *p1;
    *p1++ = *p2;
    *p2-- = temp;
  }
  return;
}

int from_roman(char* roman) {
  return 0;
}


// 4 IV 40 XL 400 CD
// 6 VI 60 LX 600 DC
// 9 IX 90 XC 900 CM
void to_roman(int number, char* destination) {
  int n = number;
  char *roman = malloc(sizeof(char) * 128);

  int thousandth = n / 1000;
  int hundredth = (n - (thousandth * 1000)) / 100;
  int tenth = (n - (thousandth * 1000) - (hundredth * 100)) / 10;
  int d = (n - (thousandth * 1000) - (hundredth * 100) - (tenth * 10));

  while (thousandth != 0) {
    strcat(roman, "M");
    thousandth--;
  }

  if (hundredth > 5) {
    while (hundredth > 5) {
      strcat(roman, "X");
      hundredth--;
    }
    strcat(roman, "L");
  } else if (hundredth == 4) {
    strcat(roman, "LX");
  }
}

int main() {
  return 0;
}