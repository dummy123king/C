#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>

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