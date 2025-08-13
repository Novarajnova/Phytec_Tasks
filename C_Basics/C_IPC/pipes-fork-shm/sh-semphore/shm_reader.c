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

void sem_wait(int semid) {
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

int main() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid < 0) { perror("shmget"); exit(1); }

    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)(-1)) { perror("shmat"); exit(1); }

    int semid = semget(SEM_KEY, 1, 0666);
    if (semid < 0) { perror("semget"); exit(1); }

    // Wait until writer signals
    sem_wait(semid);

    printf("Reader: Read from shared memory: %s\n", shmaddr);

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    return 0;
}

