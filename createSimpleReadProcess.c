#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void recursive_fork(int num_Instances);

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    recursive_fork(1);
  }
  else if (argc > 2) {
    printf("Error, too many arguments! \n");
  }
  else {
    char *ptr;
    long num = strtol(argv[1], &ptr, 10);
    recursive_fork(num);
  }
  
  return 0;
}

void recursive_fork(int num_Instances){
  pid_t pid;

  if (num_Instances > 0) {
    if ((pid = fork()) == 0) {
      printf("%s\n", "Child process...");
      char *args[3];
      args[0] = "simpleRead";
      args[1] = "data.txt";
      args[2] = NULL;
      execv("simpleRead", args);
      printf("%s\n", "Failed to execute");
      exit(127);
    } else if (pid < 0) {
      printf("%s\n", "Fork error");
    } else {
      recursive_fork(num_Instances-1);
    }
  }
}
