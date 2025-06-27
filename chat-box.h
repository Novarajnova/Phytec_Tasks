#ifndef UDP_CHAT_COMMON_H
#define UDP_CHAT_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024
#define USERNAME_LEN 32
#define PORT 9090

typedef struct {
    char username[USERNAME_LEN];
    struct sockaddr_in addr;
    socklen_t addr_len;
    int active;
} Client;

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

#endif

