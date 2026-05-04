/**
 * @file file_operations.c
 * @brief Demonstrates basic file I/O operations in Linux (open, read, write, lseek, close).
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/**
 * @brief Main function to demonstrate file operations.
 *
 * Opens a file, reads its contents, writes new data to it, seeks to the
 * beginning, and reads the updated contents.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on success, -1 on failure.
 */
int main(int argc, char **argv)
{
    int fd, data_read_len = 0;
    char buff[1000];
    char data_to_be_written[] = "This Data has written to the file";

    fd = open("test.txt", O_RDWR, 0777);

    if (fd == -1)
    {
        printf("Error occured : %d\n", errno);
        perror("Erro");
        return -1;
    }

    data_read_len = read(fd, buff, 1000);
    if (data_read_len == 0)
    {
        printf("Reached EOF\n");
    }

    printf("Size : %d\n", data_read_len);
    buff[data_read_len] = '\0';
    printf("data : %s\n", buff);


    if (write(fd, data_to_be_written, strlen(data_to_be_written)) == -1)
    {
        perror("Error");
    }
    
    lseek(fd, 0, 0);
    data_read_len = read(fd, buff, 1000);
    if (data_read_len == 0)
    {
        printf("Reached EOF\n");
    }
    
    printf("Size : %d\n", data_read_len);
    buff[data_read_len] = '\0';
    printf("data : %s\n", buff);
    
    close(fd);

    return 0;
}

/*
Expected Output (assuming test.txt is initially empty):
Reached EOF
Size : 0
data : 
Size : 33
data : This Data has written to the file
*/