#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    int res = mkfifo("myFIFO", 0777); // FIFO creation
    int writeData = 0;

    if (res == -1)
    {
        printf("Unable to create FiFo\n");
        exit(EXIT_FAILURE);
    }

    int fd = open("myFIFO", O_WRONLY);

    if (fd == -1)
    {
        printf("Unable to open the FIFO in Write mode\n");
        exit(EXIT_FAILURE);
    }
    
    for (;;)
    {
        printf("Data written = %d\n", writeData);
        if(write(fd, &writeData, sizeof(writeData)) == -1)
        {
            printf("Unable to write the data\n");
            exit(EXIT_FAILURE);
        }
        writeData++;
        sleep(2);
    }
    
    return 0;
}