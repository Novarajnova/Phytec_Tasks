#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>     // For O_* constants
#include <sys/stat.h>  // For mode constants

#define QUEUE_NAME "/myqueue"

int main() {
    mqd_t mq;
    struct mq_attr attr;

    // Open the queue
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // Get queue attributes
    if (mq_getattr(mq, &attr) == -1) {
        perror("mq_getattr");
        exit(EXIT_FAILURE);
    }

    // Allocate buffer based on max message size
    char *buffer = malloc(attr.mq_msgsize + 1);
    if (!buffer) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Receive message
    ssize_t bytes_read = mq_receive(mq, buffer, attr.mq_msgsize, NULL);
    if (bytes_read < 0) {
        perror("mq_receive");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';  // Null-terminate
    printf("Received message: \"%s\"\n", buffer);

    // Cleanup
    free(buffer);
    mq_close(mq);

    return 0;
}

