#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int i = 1;

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  if (argc == 1) {
    printf("Error, too few arguments! \n");
  }
  else if (argc > 4) {
    printf("Error, too many arguments! \n");
  }
  else {
    for (; i < argc; i++) {
      printf("PID:= %d, mem address of i:= %p, value of i = %i, arg[%i]=%s \n", getpid(), (void*)&i, i, i, argv[i]);
      int delay = (rand()%6)+1;
      sleep(delay);
    }
  }
  exit(0);
  return 0;
}
