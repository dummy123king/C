#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_COUNT 2
#define SUCCESS 0
#define FAILURE -1

pthread_mutex_t mutex;
sem_t isEmpty;
sem_t isFull;
int buffer[10];
int count = 0;


void *producer(void *params)
{
    while (1)
    {
        sem_wait(&isEmpty);
        pthread_mutex_lock(&mutex);
        buffer[count] = rand() % 10;
        count++; 
        pthread_mutex_unlock(&mutex);
        sem_post(&isFull);
    }
}


void *consumer(void *params)
{
    while (1)
    {
        sem_wait(&isFull);
        pthread_mutex_lock(&mutex);
        printf("Consumed %d\n", buffer[count - 1]);
        count--;
        pthread_mutex_unlock(&mutex);
        sem_post(&isEmpty);
        sleep(1);
    }
}


int main()
{
    pthread_t handlerProducer;
    pthread_t handlerConsumer;

    srand(time(NULL));

    sem_init(&isEmpty, 0, 10);
    sem_init(&isFull, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    if(pthread_create(&handlerProducer, NULL, &producer, NULL) != SUCCESS)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }

    if(pthread_create(&handlerConsumer, NULL, &consumer, NULL) != SUCCESS)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }

    if(pthread_join(handlerProducer, NULL) != SUCCESS)
    {
        printf("Thread Joining Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }

    if (pthread_join(handlerConsumer, NULL) != SUCCESS)
    {
        printf("Thread Joining Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }
    
    return 0;
}