#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>

int main(int atgc, char **argv)
{
    int fd[2];
    char writeBuf[] = "Hello from Write END";
    char readBuf[100];
    int noOfBytesRead = 0;
    if (pipe(fd) != 0)
    {
        printf("Unable to create pipe\n");
        exit(EXIT_FAILURE);
    }
    
    if(write(fd[1], writeBuf, strlen(writeBuf)) == -1)
    {
        printf("Unable to write into the pipe\n");
        exit(EXIT_FAILURE);
    }

    sleep(1);
    
    noOfBytesRead = read(fd[0], readBuf, strlen(writeBuf));

    if( noOfBytesRead == -1)
    {
        printf("Unable to Read into the pipe\n");
        exit(EXIT_FAILURE);
    }
    readBuf[noOfBytesRead] = '\0';

    printf("Read Buffer: %s\n", readBuf);

    return 0;
}