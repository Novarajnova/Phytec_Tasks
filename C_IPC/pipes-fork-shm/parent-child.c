#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];  // fd[0]: read end, fd[1]: write end
    pid_t pid;
    char message[] = "Message from parent to child";
    char buffer[100];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child process
    if (pid == 0) {
        close(fd[1]);  // Close write end in child
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }
    // Parent process
    else {
        close(fd[0]);  // Close read end in parent
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }

    return 0;
}

