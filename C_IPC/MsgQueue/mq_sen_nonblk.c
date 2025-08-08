#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

int main() {
    mqd_t mq;
    const char *message = "Non-blocking Hello!";
    
    // Open message queue with write-only and non-blocking flags
    mq = mq_open("/myqueue", O_WRONLY | O_NONBLOCK);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Try to send a message non-blocking
    if (mq_send(mq, message, strlen(message), 0) == -1) {
        if (errno == EAGAIN) {
            printf("Queue full: Message not sent (non-blocking).\n");
        } else {
            perror("mq_send");
            exit(1);
        }
    } else {
        printf("Message sent: %s\n", message);
    }

    mq_close(mq);
    return 0;
}

