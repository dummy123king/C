#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    int readData = 0;

    int readFd = open("myFIFO", O_RDONLY);
    
    if (readFd == -1)
    {
        printf("Unbale to open the FIFO in Read mode\n");
        exit(EXIT_FAILURE);
    }
    
    for (;;)
    {
        if(read(readFd, &readData, sizeof(int)) == -1)
        {
            printf("Unable to read data \n");
            exit(EXIT_FAILURE);
        }
        printf("Read Data = %d\n", readData);
        sleep(2);
    }
    return 0;
}