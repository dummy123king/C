/**
 * @file fifo_write_demo.c
 * @brief Demonstrates writing data to a FIFO (named pipe).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * @brief Main function to write data to a FIFO.
 *
 * Creates the FIFO "myFIFO" and opens it in write-only mode.
 * It continuously writes incrementing integers to it and prints them
 * to the standard output.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    int res = mkfifo("myFIFO", 0777);
    int write_data = 0;

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
        printf("Data written = %d\n", write_data);
        if(write(fd, &write_data, sizeof(write_data)) == -1)
        {
            printf("Unable to write the data\n");
            exit(EXIT_FAILURE);
        }
        write_data++;
        sleep(2);
    }
    
    return 0;
}

/*
Expected Output:
Data written = 0
Data written = 1
Data written = 2
...
*/