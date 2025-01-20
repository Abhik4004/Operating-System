#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_binary_tree(int depth) {
    if (depth == 0) return;

    pid_t left = fork();
    if (left == 0) {
        printf("Left Child: %d, Parent: %d\n", getpid(), getppid());
        create_binary_tree(depth - 1);
    } else {
        pid_t right = fork();
        if (right == 0) {
            printf("Right Child: %d, Parent: %d\n", getpid(), getppid());
            create_binary_tree(depth - 1);
        } else {
            wait(NULL); // Wait for left child
            wait(NULL); // Wait for right child
        }
    }
}

int main() {
    create_binary_tree(3); // 3 levels of the binary tree
    return 0;
}
