#include <stdio.h>

char *order_words (char *ordered, const char *words)
{
// ordered is pre-allocated and has enough room for a trailing space character ' '
// but dont forget to trim it !
// write to ordered and return it
  int start = 0;
  int end = 0;
  int position = 0;
  int positions[10][2];

  int wordIndex = 0;
  int orderedIndex = 0;

  int wordCount = 0;
  char c = words[0];

  // return empty string if an empty string is being read
  if(c == '\000') {
    ordered[0] = '\000';
    return ordered;
  }

  // iterate through each character in string
  while(c != '\000') {
    // if c is a number from 1 to 9, save it as a position
    if(c > '0' && c <= '9') {
      position = c - '1'; // from char to int by subtracting '1'
    }

    // end of word has been reached save start and end of word including trailing whitespace
    if(words[wordIndex] == ' ') {
      positions[position][0] = start;
      positions[position][1] = end;

      end++;
      start = end;
      wordCount++; // count words
    } else {
      end++;
    }
    // next character
    wordIndex++;
    c = words[wordIndex]; 
  }

  // end of line is not being checked inside while so last word of line is being saved here.
  positions[position][0] = start;
  positions[position][1] = end;

	for(int i = 0; i <= wordCount; i++) {
    int startOfWord = positions[i][0];
    int endOfWord = positions[i][1];
    // each character in words is being mapped to a character in ordered, resulting in an string with ordered words
    for(int j = startOfWord; j < endOfWord; j++) {
      ordered[orderedIndex] = words[j];
      orderedIndex++;
    }
    ordered[orderedIndex] = ' ';
    orderedIndex++;
  }

  // add end of line character
  ordered[orderedIndex - 1] = '\0';
	return ordered;
}

int main(int argc, char const *argv[]) {
  /* code */
  char ordered[100];
  order_words(ordered, "");

  return 0;
}
