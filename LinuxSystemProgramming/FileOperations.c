#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int fd, dataReadLen = 0;
    char buff[1000];
    char dataTobeWritten[] = "This Data has written to the file";

    fd = open("test.txt", O_RDWR, 0777); //Open the file in Read and write mode

    if (fd == -1)
    {
        printf("Error occured : %d\n", errno);
        perror("Erro");
        return -1;
    }

    dataReadLen = read(fd, buff, 1000);// Read data from test.txt file.
    if (dataReadLen == 0)
    {
        printf("Reached EOF\n");
    }

    printf("Size : %d\n", dataReadLen);
    buff[dataReadLen] = '\0';
    printf("data : %s\n", buff);


    if (write(fd, dataTobeWritten, strlen(dataTobeWritten)) == -1)
    {
        perror("Error");
    }
    
    lseek(fd, 0, 0);
    dataReadLen = read(fd, buff, 1000);// Read data from test.txt file.
    if (dataReadLen == 0)
    {
        printf("Reached EOF\n");
    }
    
    printf("Size : %d\n", dataReadLen);
    buff[dataReadLen] = '\0';
    printf("data : %s\n", buff);
    
    close(fd);

    return 0;
}