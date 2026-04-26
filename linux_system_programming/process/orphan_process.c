#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

//  Note: run this command after executing this program ---> ps aux | grep "orphanProcess"


/*
    In Linux, an orphan process is a process whose parent process has terminated or completed before the orphan process.
    When a parent process finishes execution before its child processes, the kernel assigns the init process (with PID 1)
    as the new parent process for these orphaned child processes. The init process is responsible for reaping these orphan processes.
    Orphan processes are not left completely without a parent. 
    They are reassigned to the init process to ensure they do not become zombie processes,
    which are processes that have terminated but still have an entry in the 
    process table because their parent has not yet read their exit status.

    When a parent process terminates before its child processes, these child processes become orphaned.
    The kernel assigns the init process (PID 1) as the new parent process for orphaned child processes.
    The init process periodically checks for terminated child processes and releases the resources associated
    with them, ensuring they do not become zombies.
    Once the init process reaps an orphaned child process, the process entry is removed from the process table,
    and its resources are released.

    Orphan processes are a natural occurrence in multitasking operating 
    systems like Linux and are managed efficiently by the kernel to prevent resource leakage and system instability.
*/


//Entry
int main()
{
    pid_t child_1_Pid;
    child_1_Pid = fork();

    if (child_1_Pid < 0 )
    {
        printf("Fork function failed\n");
        exit(-1);
    }

    if (child_1_Pid == 0)
    {
        printf("Child 1 Process is in execution  ------->>> %d\n", getpid());
        sleep(30);
        printf("Child  1 Process is in execution Completed\n");
        exit(1);
    }
    else
    {
        printf("Exiting Parent process\n");
    }
    
    return 0;
}
