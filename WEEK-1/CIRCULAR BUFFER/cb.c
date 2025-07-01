#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5  // Size of circular buffer

typedef struct {
    int buffer[SIZE];   // Actual buffer array
    int head;           // Write index
    int tail;           // Read index
    int count;          // Current number of elements
} CircularBuffer;

// Initialize buffer
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if buffer is full
bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// Check if buffer is empty
bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// Add item to buffer
bool enqueue(CircularBuffer *cb, int value) {
    if (isFull(cb)) {
        printf("Buffer is full!\n");
        return false;
    }

    cb->buffer[cb->head] = value;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
    return true;
}

// Remove item from buffer
bool dequeue(CircularBuffer *cb, int *value) {
    if (isEmpty(cb)) {
        printf("Buffer is empty!\n");
        return false;
    }

    *value = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return true;
}

// Display contents
void printBuffer(CircularBuffer *cb) {
    printf("Buffer: ");
    for (int i = 0; i < cb->count; i++) {
        int index = (cb->tail + i) % SIZE;
        printf("%d ", cb->buffer[index]);
    }
    printf("\n");
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    // Add 5 values
    for (int i = 1; i <= 5; i++) {
        enqueue(&cb, i * 10);
    }
    printBuffer(&cb);

    // Remove 2 values
    int val;
    dequeue(&cb, &val);
    dequeue(&cb, &val);
    printBuffer(&cb);

    // Add 2 more
    enqueue(&cb, 60);
    enqueue(&cb, 70);
    printBuffer(&cb);

    return 0;
}

