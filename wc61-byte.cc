// Write a program wc61 that counts the number of bytes in its
// standard input and prints the result to standard output.

#include <stdio.h>
// stdin and stdout to read from standard input and output

int main() {
  unsigned long n = 0;
  while (true){
    if (fgetc(stdin) == EOF){
      // fgetc returns the next byte
      break;
    }
    ++n;
  }
  fprintf(stdout, "%lu\n", n);
}
