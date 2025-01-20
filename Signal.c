#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void mysigint() {
  printf("SIGINT\n");
  return;
}

void mysigkill() {
  printf("SIGKILL\n");
  return;
}

void mysigup() {
  printf("SIGUP\n");
  return;
}

void mysigterm() {
  printf("SIGTERM\n");
  return;
}



int main() {
  if(signal(SIGINT, mysigint) == SIG_ERR) {
    printf("Cannot Handle SIGINT\n");
  }

  if(signal(SIGTERM, mysigterm) == SIG_ERR) {
    printf("Cannot Handle SIGTERM\n");
  }
  if(signal(SIGKILL, mysigkill) == SIG_ERR) {
    printf("Cannot Handle SIGKILL\n");
  }
  if(signal(SIGHUP, mysigup) == SIG_ERR) {
    printf("Cannot Handle SIGHUP\n");
  }

  while(1);
  exit(0);
  return 0;
}