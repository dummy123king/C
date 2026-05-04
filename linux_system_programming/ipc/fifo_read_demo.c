/**
 * @file fifo_read_demo.c
 * @brief Demonstrates reading data from a FIFO (named pipe).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * @brief Main function to read data from a FIFO.
 *
 * Opens the FIFO "myFIFO" in read-only mode and continuously reads
 * integers from it, printing them to the standard output.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    int read_data = 0;

    int read_fd = open("myFIFO", O_RDONLY);
    
    if (read_fd == -1)
    {
        printf("Unable to open the FIFO in Read mode\n");
        exit(EXIT_FAILURE);
    }
    
    for (;;)
    {
        if(read(read_fd, &read_data, sizeof(int)) == -1)
        {
            printf("Unable to read data \n");
            exit(EXIT_FAILURE);
        }
        printf("Read Data = %d\n", read_data);
        sleep(2);
    }
    return 0;
}

/*
Expected Output:
Read Data = 0
Read Data = 1
Read Data = 2
...
*/