#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define USERNAME_LEN 32
#define PORT 9090

typedef enum {
    EVENT_JOIN = 1,
    EVENT_LEAVE,
    EVENT_MSG
} ChatEventType;

typedef struct {
    ChatEventType type;
    char username[USERNAME_LEN];
    char message[BUF_SIZE];
} __attribute__((packed)) ChatPacket;

int client_socket;
struct sockaddr_in server_addr;
char username[USERNAME_LEN];

void send_event(ChatEventType type, const char *msg) {
    ChatPacket pkt = {0};
    pkt.type = type;
    strncpy(pkt.username, username, USERNAME_LEN);
    if (msg)
        strncpy(pkt.message, msg, BUF_SIZE);

    sendto(client_socket, &pkt, sizeof(pkt), 0,
           (struct sockaddr*)&server_addr, sizeof(server_addr));
}

void *receive_task(void *arg) {
    ChatPacket pkt;
    while (1) {
        ssize_t len = recvfrom(client_socket, &pkt, sizeof(pkt), 0, NULL, NULL);
        if (len > 0 && pkt.type == EVENT_MSG) {
            printf("\r[%s]: %s> ", pkt.username, pkt.message);
            fflush(stdout);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <username>\n", argv[0]);
        return 1;
    }

    strncpy(username, argv[2], USERNAME_LEN);
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    send_event(EVENT_JOIN, NULL);

    pthread_t recv_thread;
    pthread_create(&recv_thread, NULL, receive_task, NULL);

    char msg[BUF_SIZE];
    while (1) {
        printf("[Client]");
        fflush(stdout);
        if (fgets(msg, BUF_SIZE, stdin)) {
            if (strncmp(msg, "/exit", 5) == 0) break;
            send_event(EVENT_MSG, msg);
        }
    }

    send_event(EVENT_LEAVE, NULL);
    close(client_socket);
    return 0;
}

