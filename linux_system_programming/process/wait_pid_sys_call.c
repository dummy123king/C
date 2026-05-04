#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>

/**
 * @file wait_pid_sys_call.c
 * @brief Demonstrates the use of the waitpid() system call.
 *
 * @details
 * This program demonstrates the functionality of the `waitpid()` system call
 * with and without the `WNOHANG` option.
 * It creates two child processes.
 * - The parent process waits for the second child to terminate using a blocking `waitpid()`.
 * - It then checks the status of the first child using a non-blocking `waitpid()` with `WNOHANG`,
 *   which returns immediately even if the child has not terminated.
 */

/**
 * @brief Main function to demonstrate waitpid().
 *
 * @return 0 on successful execution.
 */
int main()
{
    pid_t child_1_pid;
    int status = 0;
    child_1_pid = fork();

    if (child_1_pid < 0 )
    {
        printf("Fork function failed\n");
        exit(-1);
    }


    if (child_1_pid == 0)
    {
        printf("Child 1 Process is in execution  ------->>> %d\n", getpid());
        sleep(10);
        printf("Child  1 Process is in execution Completed\n");
        exit(1);
    }
    else
    {
        pid_t child_2_pid;
        int status = 0;
        child_2_pid = fork();
        
        if (child_2_pid < 0 )
        {
            printf("Fork function failed\n");
            exit(-1);
        }

        if (child_2_pid == 0)
        {
            printf("Child 2 Process is in execution  ------->>> %d\n", getpid());
            sleep(4);
            printf("Child 2 Process is in execution Completed\n");
            exit(2);
        }

        sleep(1);
        printf("\nParent process\n");
        
        printf("child PID ----->> %d\n", waitpid(child_2_pid, &status, 0));
        printf("Status    ----->> %d\n", status);

        printf("child PID ----->> %d\n", waitpid(child_1_pid, &status, WNOHANG));
    
        printf("Status    ----->> %d\n", status);
        printf("Exiting Parent process\n");
    }
    
    return 0;
}

/*
Expected Output (PIDs will vary, order of first two lines may vary):
Child 1 Process is in execution  ------->>> 12346
Child 2 Process is in execution  ------->>> 12347

Parent process
Child 2 Process is in execution Completed
child PID ----->> 12347
Status    ----->> 512
child PID ----->> 0
Status    ----->> 512
Exiting Parent process
*/
