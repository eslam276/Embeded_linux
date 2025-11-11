#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define key 0x1234

int main() {
    
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 
    char *str = (char*) shmat(shmid, (void*)0, 0);   
    printf("Writing to shared memory...\n");
    strcpy(str, "Hello  Reader Process! I am Writer Process.");

    printf("Data written: %s\n", str);

    
    sleep(10); 
    
    
    shmdt(str);

    printf("Writer process done.\n");

    return 0;
}
