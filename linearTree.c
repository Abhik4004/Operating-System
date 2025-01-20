#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 3; i++) { // Create 3 processes in a chain
        pid_t pid = fork();
        if (pid == 0) {
            printf("Process: %d, Parent: %d\n", getpid(), getppid());
        } else {
            wait(NULL); // Ensure parent waits for child before exiting
            break;
        }
    }
    return 0;
}
