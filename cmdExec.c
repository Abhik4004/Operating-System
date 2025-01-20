#include<stdio.h>
// #include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
  printf("Running command inside another programm.....\n");
  execl("/bin/ls", "ls", "-l", NULL);
  perror("execl failed\n");
  return 1;
}

