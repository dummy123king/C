#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

int volatile shared_data = 0;

void *Task1(void *params)
{
    printf("Thread - 1 \n");
    
    while (1)
    {
        if (shared_data != 0)
        {
            break;
        }
    }
    printf("Thread - 1 exited\n");
}

void *Task2(void *params)
{
    printf("Thread - 2 \n");
    sleep(5);
    shared_data = 5;
    printf("Thread - 2 exited\n");
 }

int main()
{
    pthread_t hadle1, hadle2;

    if (pthread_create(&hadle1, NULL, &Task1, NULL) != 0)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_create(&hadle2, NULL, &Task2, NULL) != 0)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_join(hadle1, NULL) != 0)
    {
        printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_join(hadle2, NULL) != 0)
    {
        printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    return 0;
}