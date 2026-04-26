#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define THREAD_COUNT 2
#define SUCCESS 0
#define FAILURE -1

static volatile int shared_data = 0;

sem_t semaphore;

void *Task(void *params)
{
    printf("From Task %d\n", *(int *)params);
    
    for (int  i = 0; i < 1000000; i++)
    {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
    free(params);
}

int main()
{
    pthread_t hadle[THREAD_COUNT];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        int *threadNumber = malloc(sizeof(int));
        *threadNumber = i + 1;
        if (pthread_create(&hadle[i], NULL, &Task, threadNumber) != SUCCESS)
        {
            printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }
    
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (pthread_join(hadle[i], NULL) != SUCCESS)
        {
            printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }

    sem_destroy(&semaphore);
    printf("Shared Data = %d\n", shared_data);
    return 0;
}
