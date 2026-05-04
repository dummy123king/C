/**
 * @file fork_sys_call.c
 * @brief Demonstrates the use of the fork() system call to create a child process.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>

/**
 * @brief Main function to demonstrate fork().
 *
 * Creates a child process using fork() and prints the process IDs from both
 * the parent and child processes.
 *
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    pid_t id;

    id = fork();

    if (id < 0 )
    {
        printf("Fork function failed\n");
        exit(-1);
    }

    if (id == 0)
    {
        printf("Child ProcessID  --> PID  = %d\n", getpid());
        printf("Parent ProcessID --> PPID = %d\n", getppid());
    }
    else
    {
        sleep(1);
        printf("=================================================================\n");
        printf("ProcessID        --> PID  = %d\n", getpid());
        printf("Parent ProcessID --> PPID = %d\n", getppid());
    }

    return 0;
}

/*
Expected Output (PIDs will vary, and the order of parent/child output may differ):
Child ProcessID  --> PID  = 54322
Parent ProcessID --> PPID = 54321
=================================================================
ProcessID        --> PID  = 54321
Parent ProcessID --> PPID = 12345
*/