/**
 * @file signals.c
 * @brief Demonstrates handling of SIGTERM and SIGINT signals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

/**
 * @brief Signal handler for SIGTERM and SIGINT.
 *
 * Prints a message indicating which signal was caught and then exits the program.
 *
 * @param sig_no The signal number that triggered the handler.
 */
static void signal_handler(int sig_no)
{
    if (sig_no == SIGTERM)
    {
        printf("Caught SIGTERM\n");
    }
    else if (sig_no == SIGINT)
    {
        printf("Caught SIGINT\n");
    }
    exit(EXIT_SUCCESS);
}

/**
 * @brief Main function to set up signal handlers.
 *
 * Prints the process ID, registers the signal handler for SIGTERM (kill -15) 
 * and SIGINT (Ctrl+C), and then enters an infinite loop waiting for signals.
 *
 * @return 0 on successful execution (though it normally exits via the handler).
 */
int main()
{
    printf("Process ID = %d\n", getpid());

    if (signal(SIGTERM, signal_handler) ==  SIG_ERR)
    {
        printf("Unable to handle SIGTERM\n");
        exit(-1);
    }
    if (signal(SIGINT, signal_handler) ==  SIG_ERR)
    {
        printf("Unable to handle SIGINT\n");
        exit(-1);
    }
    while (true);
}

/*
Expected Output (PID will vary. Example shown for terminating with Ctrl+C):
Process ID = 12345
Caught SIGINT
*/