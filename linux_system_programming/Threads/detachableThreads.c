#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static void *task1(void *params)
{
    printf("Thread in execution\n");
    sleep(3);
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
    //Detach thread    
    if (pthread_detach(thandle) != 0) {
        perror("Thread detachment failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main thread execution done\n");

    pthread_exit(0);  
}