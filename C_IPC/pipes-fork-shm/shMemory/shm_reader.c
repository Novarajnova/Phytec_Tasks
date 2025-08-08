#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 0x1234

int main() {
    int shmid;
    char *shm_ptr;

    // Get the existing shared memory segment
    shmid = shmget(SHM_KEY, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach to process's address space
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Read from shared memory
    printf("Reader: Data from shared memory: %s\n", shm_ptr);

    // Detach and delete the shared memory
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);  // remove segment

    return 0;
}

