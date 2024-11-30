#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_COUNT 2
#define SUCCESS 0
#define FAILURE -1

static volatile int shared_data = 0;
pthread_mutex_t mutex; 


void *task(void *params)
{
    int iteration_count = *(int *)params;
    printf("iteration count = %d\n", iteration_count);
    for (int i = 0; i < iteration_count; i++)
    {
        pthread_mutex_lock(&mutex);
        shared_data++;
        pthread_mutex_unlock(&mutex);  
    }
}


int main()
{   
    pthread_t handle[THREAD_COUNT];
    pthread_mutex_init(&mutex, NULL);
    int iteration_count = 1000000; 
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (pthread_create(&handle[i], NULL, &task, &iteration_count) != SUCCESS)
        {
            printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }

    for (int  i = 0; i < THREAD_COUNT; i++)
    {
        if(pthread_join(handle[i], NULL) != SUCCESS)
        {
            printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }
    pthread_mutex_destroy(&mutex);

    printf("==========================>>shared data %d\n", shared_data);
    return 0;
}