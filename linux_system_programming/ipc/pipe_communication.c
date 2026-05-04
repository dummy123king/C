/**
 * @file pipe_communication.c
 * @brief Demonstrates inter-process communication using a pipe between a parent and child process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>

/**
 * @brief Main function to create a pipe and facilitate communication.
 *
 * Creates a pipe, forks a child process, and has the child write to the pipe
 * while the parent reads from it.
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
        if (write(fd[1], write_buf, strlen(write_buf)) == -1)
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

        int no_of_bytes_read = 0;
        if (close(fd[1]) == -1)
        {
            printf("Unable to close the Write end in Parent process\n");
        }

        no_of_bytes_read = read(fd[0], read_buf, strlen(write_buf));
        if (no_of_bytes_read == -1)
        {
            printf("Unable to Read into the pipe\n");
            exit(EXIT_FAILURE);
        }

        read_buf[no_of_bytes_read] = '\0';
        printf("Read Buffer: %s\n", read_buf);
        
        if (close(fd[0]) == -1)
        {
            printf("Unable to close the Read end in Parent process\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

/*
Expected Output (order of first two lines may vary):
parent process
Child process
Read Buffer: Hello from Write END
*/