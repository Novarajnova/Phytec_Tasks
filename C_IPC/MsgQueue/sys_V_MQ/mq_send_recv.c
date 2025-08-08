#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100

// Define message buffer structure
struct msg_buffer {
    long msg_type;
    char msg_text[MAX];
};

int main() {
    key_t key;
    int msgid;

    // Generate unique key
    key = ftok("mq_msgget.c", 65);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct msg_buffer message;

    // ========== SEND MESSAGE ==========
    message.msg_type = 1;  // Must be > 0
    strcpy(message.msg_text, "Hello from sender!");

    // Send the message
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Sent message: %s\n", message.msg_text);

    // ========== RECEIVE MESSAGE ==========
    struct msg_buffer received_msg;

    // Receive message of type 1
    if (msgrcv(msgid, &received_msg, sizeof(received_msg.msg_text), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", received_msg.msg_text);

    return 0;
}

