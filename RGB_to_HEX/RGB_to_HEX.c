#include <stdio.h>

void decToHex(int n, int offset, char *color) {
  for(int i = 1; i <= 2; i++) {
    switch(n % 16) {
      case 10:
        color[(2 - i) + offset] = (char)'A';
        break;
      case 11:
        color[(2 - i) + offset] = (char)'B';
        break;
      case 12:
        color[(2 - i) + offset] = (char)'C';
        break;
      case 13:
        color[(2 - i) + offset] = (char)'D';
        break;
      case 14:
        color[(2 - i) + offset] = (char)'E';
        break;
      case 15:
        color[(2 - i) + offset] = (char)'F';
        break;
      default: 
        color[(2 - i) + offset] = (char)((n % 16) + '0');
    }
    n = n/16;
  }
}

int rgb(int r, int g, int b, char *output)
{
  //pass the result to the 'char *output'
  // mod 256

  r = r > 255 ? 255 : r < 0 ? 0 : r;
  g = g > 255 ? 255 : g < 0 ? 0 : g;
  b = b > 255 ? 255 : b < 0 ? 0 : b;
  
  decToHex(r, 0, output);
  decToHex(g, 2, output);
  decToHex(b, 4, output);
  output[6] = '\0';

  return 0;
}

int main(int argc, char const *argv[])
{
  char output[4][7];

  rgb(255, 255, 255, output[0]); // FFFFFF
  printf("%s\n", output[0]);
  rgb(255, 255, 300, output[1]); // FFFFFF
  printf("%s\n", output[1]);
  rgb(0, 0, 0, output[2]);       // 000000
  printf("%s\n", output[2]);
  rgb(148, 0, 211, output[3]);   // 9400D3
  printf("%s\n", output[3]);

  return 0;
}