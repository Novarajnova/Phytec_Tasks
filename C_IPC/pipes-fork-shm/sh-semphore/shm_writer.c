#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_KEY 1234
#define SEM_KEY 5678
#define SHM_SIZE 1024

void sem_signal(int semid) {
    struct sembuf op = {0, 1, 0};
    semop(semid, &op, 1);
}

int main() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) { perror("shmget"); exit(1); }

    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)(-1)) { perror("shmat"); exit(1); }

    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid < 0) { perror("semget"); exit(1); }

    // Initialize semaphore to 0
    semctl(semid, 0, SETVAL, 0);

    printf("Writer: Writing to shared memory...\n");
    strcpy(shmaddr, "Hello from writer!");

    // Signal reader that data is ready
    sem_signal(semid);

    shmdt(shmaddr);
    return 0;
}

