#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 4; i++) { // Create 4 child processes
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child: %d, Parent: %d\n", getpid(), getppid());
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        wait(NULL); // Parent waits for all children
    }
    return 0;
}
