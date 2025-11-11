#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#define key 0x1234
int main() {   
    
    sleep(2); 
    
    int shmid = shmget(key, 1024, 0666 ); 
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Reading from shared memory...\n");
    printf("Data read: %s\n", str);

    sleep(5);

    
    shmdt(str);
    

    printf("Reader process done.\n");
    return 0;
}
