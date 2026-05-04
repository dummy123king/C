#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>

/**
 * @file wait_sys_call.c
 * @brief Demonstrates the use of the wait() system call.
 */
/**
 * @brief Main function to demonstrate wait().
 *
 * Creates a child process and uses wait() in the parent process
 * to block execution until the child process terminates.
 *
 * @return 0 on successful execution.
 */
int main()
{
    pid_t id;
    int status = 0;
    id = fork();

    if (id < 0 )
    {
        printf("Fork function failed\n");
        exit(-1);
    }


    if (id == 0)
    {
        printf("Child Process is in execution  ------->>> %d\n", getpid());
        sleep(10);
        printf("Child Process is in execution Completed\n");
        exit(3);
    }
    else
    {
        sleep(1);
        printf("\nParent process\n");
        printf("waiting for child process to terminate\n");
        printf("child PID ----->> %d\n", wait(&status));
        printf("Status    ----->> %d\n", status);
        printf("Exiting Parent process\n");
    }
    
    return 0;
}

/*
Expected Output (PIDs will vary, order of first line and parent process print may vary):
Child Process is in execution  ------->>> 12346

Parent process
waiting for child process to terminate
Child Process is in execution Completed
child PID ----->> 12346
Status    ----->> 768
Exiting Parent process
*/
