#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void callBack(int sigNo)
{
    printf("Called Function\n");
    alarm(2);   
}


int main()
{
    // if (signal(SIGALRM, callBack) == SIG_ERR)
    // {
    //     perror("Error");
    // }
    if (signal(SIGALRM, SIG_DFL) == SIG_ERR)
    {
        perror("Error");
    }

    alarm(1);

    for (;;);    
}