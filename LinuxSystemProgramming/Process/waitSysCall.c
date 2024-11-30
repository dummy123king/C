#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>


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
        // Wait function returns child process id 
        printf("child PID ----->> %d\n", wait(&status));
        printf("Status    ----->> %d\n", status);
        printf("Exiting Parent process\n");
    }
    

}
