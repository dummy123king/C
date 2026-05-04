/**
 * @file alarm.c
 * @brief Demonstrates the use of the alarm() system call and SIGALRM signal.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

/**
 * @brief Signal handler for SIGALRM.
 *
 * This function is called when a SIGALRM signal is received. It prints a
 * message and sets another alarm for 2 seconds.
 *
 * @param sig_no The signal number that triggered the handler.
 */
static void call_back(int sig_no)
{
    printf("Called Function\n");
    alarm(2);
}

/**
 * @brief Main function to set up and handle alarms.
 *
 * Sets the default signal handler for SIGALRM, which terminates the process.
 * It then schedules an alarm for 1 second and enters an infinite loop.
 *
 * @return This function does not return.
 */
int main()
{
    if (signal(SIGALRM, SIG_DFL) == SIG_ERR)
    {
        perror("Error");
    }

    alarm(1);
    for (;;);
}

/*
Expected Output:
Alarm clock
*/