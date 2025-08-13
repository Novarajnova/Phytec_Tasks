#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

int main() {
    mqd_t mq;
    char buffer[256];
    ssize_t bytes_read;

    // Open the message queue in blocking mode (default)
    mq = mq_open("/myqueue", O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    printf("Waiting to receive message (blocking)...\n");

    // Receive a message (this will block if the queue is empty)
    bytes_read = mq_receive(mq, buffer, sizeof(buffer), NULL);
    if (bytes_read == -1) {
        perror("mq_receive");
        exit(1);
    }

    buffer[bytes_read] = '\0'; // Null-terminate the received string
    printf("Received message: %s\n", buffer);

    mq_close(mq);
    return 0;
}

