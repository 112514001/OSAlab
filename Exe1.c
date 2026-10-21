#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int id = shmget(1234, 1024, 0666 | IPC_CREAT);
    char *p = shmat(id, NULL, 0);
    strcpy(p, "Hello from Writer!");
    printf("Data written\n");
    shmdt(p);
    return 0;
}