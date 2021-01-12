#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

static void transfer(const char* fileName){
  FILE* fptr;
  if (strcmp(fileName, "-") == 0){
    fptr = stdin;
  } else {
    fptr = fopen(fileName, "r");
  }
  if (fptr == NULL){
    // strerror(errno) prints meaningful error messages
    fprintf(stderr, "%s: %s\n", fileName, strerror(errno));
    exit(EXIT_FAILURE);
  }

  while (!feof(fptr) && !ferror(fptr) && !ferror(stdout)){
    // BUFSIZ is constant defined in C++
    char buffer[BUFSIZ];
    fread(buffer, 1, BUFSIZ, fptr);
    printf("%s\n", buffer);
    // size_t nr = fread(buffer, 1, BUFSIZ, fptr);
    // (void) fwrite(buffer, 1, nr, stdout);
  }

  // print out error messages
  if (ferror(fptr) || ferror(stdout)){
      fprintf(stderr, "%s\n", strerror(errno));
      exit(EXIT_FAILURE);
  }

  if (fptr != stdin){
    // close file if not in stdin
    fclose(fptr);
  }

}

int main(int argc, char** argv){
  // no args - read from standard input
  if (argc == 1){
    transfer("-");
  } else{
    for (int i = 1; i < argc; i++){
      transfer(argv[i]);
    }
  }
}
