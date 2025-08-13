#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Create or get the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Prepare structured message
    msg.msg_type = 1;
    msg.id = 101;
    msg.value = 45.67;
    strcpy(msg.name, "Nova Macha");

    // Send message (excluding msg_type size)
    if (msgsnd(msgid, &msg, sizeof(msg) - sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Structured message sent.\n");
    return 0;
}

