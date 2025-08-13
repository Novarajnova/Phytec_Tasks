// file: mq_create.c
#include <stdio.h>
#include <fcntl.h>      // For O_* constants
#include <sys/stat.h>   // For mode constants
#include <mqueue.h>
#include <stdlib.h>

int main() {
    mqd_t mq;
    const char *queue_name = "/myqueue";

    mq = mq_open(queue_name, O_CREAT | O_RDWR, 0644, NULL);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    printf("Message queue '%s' created and opened successfully.\n", queue_name);

    mq_close(mq);       // Always close after use
    return 0;
}

