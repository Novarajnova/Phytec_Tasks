#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MAX 100

struct msg_buffer {
    long msg_type;
    char msg_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer msg;

    // Generate unique key
    key = ftok("mq_nowait_send.c", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the message queue id
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Try to receive message without blocking
    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message of type 1 available now (non-blocking).\n");
        } else {
            perror("msgrcv");
        }
    } else {
        printf("Received message: %s\n", msg.msg_text);
    }

    return 0;
}

