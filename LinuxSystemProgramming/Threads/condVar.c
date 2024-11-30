#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

static volatile uint32_t sharedData = 0;
static volatile uint8_t isDataFilled = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVar = PTHREAD_COND_INITIALIZER;


static void *task1(void *params)
{
    for (;;)
    {
        pthread_mutex_lock(&mutex);
        sharedData += 1;
        isDataFilled = 1;
        pthread_cond_signal(&condVar);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }    
}

static void *task2(void *params)
{
    int readData = 0;
    for (;;)
    {
        pthread_mutex_lock(&mutex);
        if (isDataFilled == 0)
            pthread_cond_wait(&condVar, &mutex);
        
        readData = sharedData;
        printf("read data = %d\n", readData);
        isDataFilled = 0;
        pthread_mutex_unlock(&mutex);
    }    
}

int main()
{
    pthread_t tid1, tid2;

    if (pthread_create(&tid1, NULL, task1, NULL) == -1)
    {
        printf("Unable to create thread - 1\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&tid2, NULL, task2, NULL) == -1)
    {
        printf("Unable to create thread - 2\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_join(tid1, NULL) == -1)
    {
        printf("Unable to Join thread - 1\n");
        exit(EXIT_FAILURE);
    }

   if(pthread_join(tid2, NULL) == -1)
    {
        printf("Unable to Join thread - 2\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}