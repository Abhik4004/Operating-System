#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
  pid_t child_p;
  child_p = fork();
  switch (child_p)
  {
  case -1:
    printf("Child can not be formed\n");
    break;
  case 0:
    printf("Printf parent %d\n", (int) getppid());
  default:
    printf("Code running...\n");
    break;
  }
  printf("Hello World from %d\n", (int) getpid());
  return 0;
}