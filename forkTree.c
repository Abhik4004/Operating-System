#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void create_tree(int depth){
  if(depth > 0) {
    pid_t left_child = fork();
    if(left_child == 0) {
      printf("Left child at depth %d, PID: %d, PPID: %d\n", depth, (int) getpid(), (int) getppid());
      create_tree(depth-1);
      exit(0);
    } else {
      pid_t right_child = fork();
      if(right_child == 0) {
        printf("Right child at depth %d, PID: %d, PPID: %d\n", depth, (int) getpid(), (int) getppid());
        create_tree(depth - 1);
        exit(0);
      }
    }
  }
}

int main() {
  int depth;
  printf("Enter depth: ");
  scanf("%d", &depth);
  printf("\nRoot process, PID: %d\n", (int) getpid());
  create_tree(depth);
  return 0;
}