#include <stdio.h>

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    printf("Error, too few arguments! \n");
  }
  else if (argc > 4) {
    printf("Error, too many arguments! \n");
  }
  else {
    for (int i = 1; i < argc; i++) {
      printf("arg[%i]=%s \n", i, argv[i]);
    }
  }

  return 0;
}
