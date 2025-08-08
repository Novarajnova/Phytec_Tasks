#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child Process
    if (pid == 0) {
        close(pipefd[1]);  // Close write end in child

        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);

        close(pipefd[0]);  // Close read end
    }
    // Parent Process
    else {
        close(pipefd[0]);  // Close read end in parent

        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]);  // Close write end
    }

    return 0;
}

