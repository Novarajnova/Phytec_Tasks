#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024
#define SHM_KEY 1234

int main() {
    int shmid;
    char *shmaddr;

    // Get the shared memory
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to it
    shmaddr = (char *)shmat(shmid, NULL, 0);
    if (shmaddr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Read and print
    printf("Data read from shared memory: %s\n", shmaddr);

    // Detach
    shmdt(shmaddr);

    // Optionally remove the shared memory
    // shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

