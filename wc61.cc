// Write a program wc61 that counts the number of bytes in its
// standard input and prints the result to standard output.

#include <cstdio>
#include <ctype.h>
// stdin and stdout to read from standard input and output

int main() {
  unsigned long bytes = 0, lines = 0, words = 0;
  bool prev_space = true;
  while (true){
    char ch = fgetc(stdin);
    if (ch == EOF){
      // fgetc returns the next byte
      break;
    }
    ++bytes;
    // good practice to make unsigned char to prevent
    // crashes with negative numbers
    bool cur_space = isspace((unsigned char) ch);
    if (prev_space && !cur_space){
      ++words;
    }
    prev_space = cur_space;

    if (ch == '\n'){
      ++lines;
    }
  }
  fprintf(stdout, "%8lu %7lu %7lu\n", lines, words, bytes);
}
