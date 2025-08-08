#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

int main() {
    mqd_t mq;
    char buffer[256];
    ssize_t bytes_read;

    // Open message queue with read-only and non-blocking flags
    mq = mq_open("/myqueue", O_RDONLY | O_NONBLOCK);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Try to receive a message non-blocking
    bytes_read = mq_receive(mq, buffer, sizeof(buffer), NULL);
    if (bytes_read == -1) {
        if (errno == EAGAIN) {
            printf("Queue empty: No message received (non-blocking).\n");
        } else {
            perror("mq_receive");
            exit(1);
        }
    } else {
        buffer[bytes_read] = '\0';
        printf("Message received: %s\n", buffer);
    }

    mq_close(mq);
    return 0;
}

