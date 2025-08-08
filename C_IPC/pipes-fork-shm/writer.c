#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define FIFO_PATH "myfifo"

int main() {
    int fd;
    char message[] = "Hello from writer process!";

    // Create FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        // If already exists, continue
    }

    // Open FIFO for writing
    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, message, strlen(message) + 1);
    printf("Writer sent: %s\n", message);
    close(fd);
    return 0;
}

