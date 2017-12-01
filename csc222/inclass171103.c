#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Parent Process: %d\n", getpid());

    int pid;
    pid = fork();

    if (pid == 0) {
        printf("This is the Child Process: %d, Parent pid %d\n", getpid(), getppid());
    } else {
        printf("I am the parent...waiting\n");
    }
    return 0;
}