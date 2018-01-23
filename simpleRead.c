#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  printf("%s %d has started... \n", "An instance of simpleRead with PID: ", getpid());
  srand(time(NULL));
  if (argc < 2) {
    printf("Error, too few arguments! \n");
  }
  else if (argc > 2) {
    printf("Error, too many arguments! \n");
  }
  else {
    FILE *fp = fopen(argv[1], "r");
    char buff[255];

    while(fgets(buff, 255-1, fp) != NULL){
      size_t num_Of_Char = strlen(buff) - 1;

      int delay = (rand()%6)+1;
      sleep(delay);

      printf("Number of Characters on line: %lu , PID:= %d \n", num_Of_Char, getpid());
    }
    fclose(fp);
  }
  printf("%s %d has finished... \n", "An instance of simpleRead with PID: ",getpid());
  return 0;
}
