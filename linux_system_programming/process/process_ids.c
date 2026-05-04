/**
 * @file process_ids.c
 * @brief Demonstrates retrieving the current process ID and parent process ID.
 */

#include <stdio.h>
#include <unistd.h>

/**
 * @brief Main function to print process IDs.
 *
 * Uses getpid() to get the current process ID and getppid() to get the
 * parent process ID, then prints them to standard output.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    printf("ProcessID        --> PID  = %d\n", getpid());
    printf("Parent ProcessID --> PPID = %d\n", getppid());
    return 0;
}

/*
Expected Output (PIDs will vary):
ProcessID        --> PID  = 12345
Parent ProcessID --> PPID = 12344
*/