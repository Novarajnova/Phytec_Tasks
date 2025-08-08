#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/types.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// Wait (P) operation
void sem_wait(int semid) {
    struct sembuf sops = {0, -1, 0}; // sem_num=0, sem_op=-1
    semop(semid, &sops, 1);
}

// Signal (V) operation
void sem_signal(int semid) {
    struct sembuf sops = {0, 1, 0}; // sem_num=0, sem_op=1
    semop(semid, &sops, 1);
}

int main() {
    key_t key = ftok("shm_writer.c", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    union semun arg;
    arg.val = 1; // Initialize to 1 for mutual exclusion
    semctl(semid, 0, SETVAL, arg);

    printf("Process %d waiting to enter critical section...\n", getpid());
    sem_wait(semid); // Lock

    // Critical section
    printf("Process %d entered critical section\n", getpid());
    sleep(3); // simulate work
    printf("Process %d exiting critical section\n", getpid());

    sem_signal(semid); // Unlock

    return 0;
}

