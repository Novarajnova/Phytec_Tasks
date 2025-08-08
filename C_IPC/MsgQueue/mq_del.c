#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>

int main() {
    const char *queue_name = "/myqueue";

    // Attempt to unlink (delete) the queue
    if (mq_unlink(queue_name) == -1) {
        perror("mq_unlink");
        return 1;
    }

    printf("Message queue '%s' deleted successfully.\n", queue_name);
    return 0;
}

