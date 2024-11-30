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
    if (pipe(fd) != 0)
    {
        printf("Unable to create pipe\n");
        exit(EXIT_FAILURE);
    }

    if ((fork() == 0))
    {
        printf("Child process\n");

        if (close(fd[0]) == -1)
        {
            printf("Unable to close the Read end in child process\n");
            exit(EXIT_FAILURE);
        }
        if (write(fd[1], writeBuf, strlen(writeBuf)) == -1)
        {
            printf("Unable to write into the pipe\n");
            exit(EXIT_FAILURE);
        }
        if (close(fd[1]) == -1)
        {
            printf("Unable to close the Write end in child process\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("parent process\n");

        int noOfBytesRead = 0;
        if (close(fd[1]) == -1)
        {
            printf("Unable to close the Write end in Parent process\n");
        }

        noOfBytesRead = read(fd[0], readBuf, strlen(writeBuf));
        if (noOfBytesRead == -1)
        {
            printf("Unable to Read into the pipe\n");
            exit(EXIT_FAILURE);
        }

        readBuf[noOfBytesRead] = '\0';
        printf("Read Buffer: %s\n", readBuf);
        
        if (close(fd[0]) == -1)
        {
            printf("Unable to close the Read end in Parent process\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}