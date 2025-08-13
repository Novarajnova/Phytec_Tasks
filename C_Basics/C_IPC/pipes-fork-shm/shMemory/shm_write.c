#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  // shared memory size in bytes
#define SHM_KEY 1234   // unique key

int main() {
    int shmid;
    char *shmaddr;

    // Create shared memory
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory
    shmaddr = (char *)shmat(shmid, NULL, 0);
    if (shmaddr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Write data
    printf("Writing to shared memory...\n");
    strcpy(shmaddr, "Hello from shm_writer!");

    // Wait so reader gets time to read
    printf("Data written. Waiting before detach...\n");
    sleep(10);

    // Detach
    shmdt(shmaddr);

    return 0;
}

