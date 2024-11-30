#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>

// Command to check zombie process in Terminal "ps aux | grep Z"

/*
In Linux, a zombie process is a process that has completed execution but still has an entry in the process table.
This occurs when the process's parent has not yet called the wait() or waitpid()
system call to retrieve the process's exit status. Until the parent retrieves the exit status of the child process,
the child process remains in a "zombie" state, consuming very few system resources but still taking up an entry in the process table.

Zombie processes are typically very short-lived and usually exist only briefly until their parent process retrieves their exit status.
Once the parent process retrieves the exit status of its child process, the zombie process is removed from the process table,
and its entry is completely cleared from memory,
releasing any resources associated with it.

Zombie processes do not pose an immediate threat to system stability or performance,
but if a large number of zombie processes accumulate, it may indicate a problem with the parent process not properly managing its child processes.
In such cases, it's essential to identify and fix the issue with the parent process to prevent excessive resource consumption.

To avoid the accumulation of zombie processes, it's good practice for parent processes to
promptly handle the termination of their child processes by calling wait() or waitpid() to retrieve their exit statuses.
This ensures that zombie processes are promptly removed from the system, preventing any potential issues with resource exhaustion.

*/


int main(int argc, char **argv)
{
    pid_t id  = fork();

    if(id < 0)
    {
        printf("Fork function failed\n");
        exit(-1);
    }

    if (id == 0)
    {
        printf("Child Id %d\n", getpid());
        sleep(5);
        printf("Child process terminated\n");
    }
    else
    {
        printf("Parent process\n");
        sleep(14);
        waitpid(id, NULL, 0);
        sleep(20);
        printf("Parent process terminated\n");
    }
    
    return 0;
}