#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg {
    long msg_type;
    int id;
    float value;
    char name[50];
};

int main() {
    key_t key;
    int msgid;
    struct my_msg msg;

    // Generate key
    key = ftok("mq_struct_send.c", 65);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Get the message queue
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Receive message
    if (msgrcv(msgid, &msg, sizeof(msg) - sizeof(long), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    // Print structured message
    printf("Received Structured Message:\n");
    printf("  ID: %d\n", msg.id);
    printf("  Value: %.2f\n", msg.value);
    printf("  Name: %s\n", msg.name);

    return 0;
}

