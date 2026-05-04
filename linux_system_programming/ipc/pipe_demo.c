/**
 * @file pipe_demo.c
 * @brief Demonstrates basic data transfer through an unnamed pipe within a single process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>

/**
 * @brief Main function to create a pipe, write to it, and read from it.
 *
 * This program creates a simple pipe, writes a string to the write end,
 * and then reads the string from the read end, printing it to standard output.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    int fd[2];
    char write_buf[] = "Hello from Write END";
    char read_buf[100];
    int no_of_bytes_read = 0;
    if (pipe(fd) != 0)
    {
        printf("Unable to create pipe\n");
        exit(EXIT_FAILURE);
    }
    
    if(write(fd[1], write_buf, strlen(write_buf)) == -1)
    {
        printf("Unable to write into the pipe\n");
        exit(EXIT_FAILURE);
    }

    sleep(1);
    
    no_of_bytes_read = read(fd[0], read_buf, strlen(write_buf));

    if( no_of_bytes_read == -1)
    {
        printf("Unable to Read into the pipe\n");
        exit(EXIT_FAILURE);
    }
    read_buf[no_of_bytes_read] = '\0';

    printf("Read Buffer: %s\n", read_buf);

    return 0;
}

/*
Expected Output:
Read Buffer: Hello from Write END
*/