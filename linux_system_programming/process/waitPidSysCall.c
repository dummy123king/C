#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>

//Entry
int main()
{
    pid_t child_1_Pid;
    int status = 0;
    child_1_Pid = fork();

    if (child_1_Pid < 0 )
    {
        printf("Fork function failed\n");
        exit(-1);
    }


    if (child_1_Pid == 0)
    {
        printf("Child 1 Process is in execution  ------->>> %d\n", getpid());
        sleep(10);
        printf("Child  1 Process is in execution Completed\n");
        exit(1);
    }
    else
    {
        pid_t child_2_Pid;
        int status = 0;
        child_2_Pid = fork();
        
        if (child_1_Pid < 0 )
        {
            printf("Fork function failed\n");
            exit(-1);
        }

        if (child_2_Pid == 0)
        {
            printf("Child 2 Process is in execution  ------->>> %d\n", getpid());
            sleep(4);
            printf("Child 2 Process is in execution Completed\n");
            exit(2);
        }

        sleep(1);
        printf("\nParent process\n");
        
        // Wait function returns child process id 
        printf("child PID ----->> %d\n", waitpid(child_2_Pid, &status, 0));
        printf("Status    ----->> %d\n", status);

        // Parent process will not wait for child prcoess to terminate
        printf("child PID ----->> %d\n", waitpid(child_1_Pid, &status, WNOHANG));
    
        printf("Status    ----->> %d\n", status);
        printf("Exiting Parent process\n");
    }
    
    return 0;
}
