#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>

int main() {
    const char *queue_name = "/myqueue";
    mqd_t mq;
    struct mq_attr attr;

    // Set queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    // Open or create the message queue
    mq = mq_open(queue_name, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    char message[256];
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline if present
    message[strcspn(message, "\n")] = '\0';

    // Send message
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", message);
    mq_close(mq);
    return 0;
}

