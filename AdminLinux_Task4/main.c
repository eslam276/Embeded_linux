#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
 {

    int fd = open("/sys/class/leds/input3::capslock/brightness" , O_RDWR);

    if(argv[1][0]=='0')
    {
        printf("The first character is zero.\n");
        dprintf(fd, "0");
    }
    else if(argv[1][0]=='1')
    {
        printf("The first character is one.\n");
        dprintf(fd, "1");
    }
    else
    {
        printf("The first character is neither zero nor one.\n");
    }

    close(fd);
    


    return 0;
}