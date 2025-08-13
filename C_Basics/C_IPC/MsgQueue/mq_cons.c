#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>

int main() {
    const char *queue_name = "/myqueue";
    mqd_t mq;
    char buffer[256];
    struct mq_attr attr;

    // Open existing queue
    mq = mq_open(queue_name, O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // Get attributes
    mq_getattr(mq, &attr);

    // Receive message
    ssize_t bytes_read = mq_receive(mq, buffer, attr.mq_msgsize, NULL);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0';
        printf("Received message: %s\n", buffer);
    } else {
        perror("mq_receive");
    }

    mq_close(mq);
    mq_unlink(queue_name);  // Optional: delete queue after receive
    return 0;
}

