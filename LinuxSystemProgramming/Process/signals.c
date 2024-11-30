#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>


static void signalHandler(int sigNo)
{
    if (sigNo == SIGTERM) // Press Ctrl + 
    {
        printf("Cought SIGTERM\n");
    }
    else if (sigNo == SIGINT) // Press Ctrl + C
    {
        printf("Cought SIGINT\n");
    }
    exit(EXIT_SUCCESS);
}

int main()
{
    printf("Process ID = %d\n", getpid());

    if (signal(SIGTERM, signalHandler) ==  SIG_ERR) // Open the another terminal and run this Command "kill -15 processID
    {
        printf("Unbale to handle SIGTERM\n");
        exit(-1);
    }
    if (signal(SIGINT, signalHandler) ==  SIG_ERR) // Press Ctrl + C
    {
        printf("Unbale to handle SIGINT\n");
        exit(-1);
    }
    while (true);    
}