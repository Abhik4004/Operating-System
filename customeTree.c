#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    printf("process: %d, parent: %d\n", (int) getpid(), (int) getppid());
    pid_t firstChild = fork();
    if(firstChild == 0) {
      printf("process: %d, parent: %d\n", (int) getpid(), (int) getppid());
      return 0;
    } else if(firstChild > 0) {
      wait(NULL);
    }

    pid_t secondBranch = fork();
    if (secondBranch == 0) {
        // This is the second child of the main process
        printf("process: %d, parent: %d\n", (int)getpid(), (int)getppid());

        // Three branches from this child
        for (int i = 0; i < 3; i++) {
            pid_t child = fork();
            if (child == 0) {
                printf("process: %d, parent: %d\n", (int)getpid(), (int)getppid());
                return 0;
            } else if (child > 0) {
                wait(NULL); // Parent waits for child to complete
            } else {
                perror("Fork failed");
                return 1;
            }
        }
        return 0;
    } else if (secondBranch > 0) {
        wait(NULL); // Parent waits for secondBranch to complete
    } else {
        perror("Fork failed");
    }
}
