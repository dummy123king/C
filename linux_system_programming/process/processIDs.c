#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    printf("ProcessID        --> PID  = %d\n", getpid());
    printf("Parent ProcessID --> PPID = %d\n", getppid());
    return 0;
}