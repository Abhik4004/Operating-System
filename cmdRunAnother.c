#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childp = fork();
    if (childp < 0) {
        perror("Child process creation failed");
        return 1;
    } else if (childp == 0) {
        printf("Child process ID: %d\n", (int)getpid());
        execl("./addE", NULL);
        perror("execl failed");
        return 1;
    } else {
        printf("Parent process ID: %d\n", (int)getpid());
        wait(NULL); // Wait for child to complete
    }

    return 0;
}
