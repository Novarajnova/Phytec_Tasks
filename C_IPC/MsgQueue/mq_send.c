#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>      // For O_* constants
#include <sys/stat.h>   // For mode constants
#include <mqueue.h>     // POSIX message queue functions

int main() {
    mqd_t mq;                               // Message queue descriptor
    const char *queue_name = "/myqueue";    // Queue name (must start with '/')
    const char *message = "Hello from sender!";  // Message to send

    // Open the existing message queue for writing
    mq = mq_open(queue_name, O_WRONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    // Send the message
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        mq_close(mq);
        exit(1);
    }

    printf("Message sent successfully: \"%s\"\n", message);

    mq_close(mq);   // Close the message queue
    return 0;
}

