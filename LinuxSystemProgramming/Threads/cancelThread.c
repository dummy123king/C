#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static void *task1(void *params)
{
    for(;;)
    {
        printf("Thread in execution\n");
        sleep(3);
    }
    printf("Thread Execution Done\n");
}

int main(int argc, char **argv)
{
    pthread_t thandle;

    if (pthread_create(&thandle, NULL, task1, NULL) != 0)
    {
        perror("Thread Creation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("Main Thread is executing...\n");
        sleep(2);
    }
    
    //Cancel thread    
    if (pthread_cancel(thandle) != 0) {
        perror("Thread cancel failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main thread execution done\n");

    pthread_exit(0);  
}