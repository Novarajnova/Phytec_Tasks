#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main() {
    mqd_t mq;
    struct mq_attr attr;

    // Set custom attributes
    attr.mq_flags = 0;        // 0 means blocking mode
    attr.mq_maxmsg = 10;      // Maximum number of messages allowed in queue
    attr.mq_msgsize = 256;    // Maximum size of each message
    attr.mq_curmsgs = 0;      // Number of messages currently in queue (read-only)

    // Create or open the queue with custom attributes
    mq = mq_open("/myqueue", O_CREAT | O_RDWR, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    printf("Message queue created with custom attributes.\n");

    // Optional: print the actual attributes
    struct mq_attr actual_attr;
    mq_getattr(mq, &actual_attr);
    printf("mq_maxmsg: %ld\n", actual_attr.mq_maxmsg);
    printf("mq_msgsize: %ld\n", actual_attr.mq_msgsize);

    mq_close(mq);
    return 0;
}

