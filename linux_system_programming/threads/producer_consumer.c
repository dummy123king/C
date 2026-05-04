/**
 * @file producer_consumer.c
 * @brief Demonstrates the producer-consumer problem using pthreads, mutexes, and semaphores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/** @brief The number of threads to create. */
#define THREAD_COUNT 2
/** @brief Success return code. */
#define SUCCESS 0
/** @brief Failure return code. */
#define FAILURE -1

/** @brief Mutex to protect the shared buffer. */
pthread_mutex_t mutex;
/** @brief Semaphore to track empty slots in the buffer. */
sem_t is_empty;
/** @brief Semaphore to track filled slots in the buffer. */
sem_t is_full;
/** @brief Shared buffer for the producer and consumer. */
int buffer[10];
/** @brief Number of items currently in the buffer. */
int count = 0;

/**
 * @brief Producer thread function that generates random data and adds it to the buffer.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
void *producer(void *params)
{
    while (1)
    {
        sem_wait(&is_empty);
        pthread_mutex_lock(&mutex);
        buffer[count] = rand() % 10;
        count++; 
        pthread_mutex_unlock(&mutex);
        sem_post(&is_full);
    }
    return NULL;
}

/**
 * @brief Consumer thread function that reads data from the buffer and prints it.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
void *consumer(void *params)
{
    while (1)
    {
        sem_wait(&is_full);
        pthread_mutex_lock(&mutex);
        printf("Consumed %d\n", buffer[count - 1]);
        count--;
        pthread_mutex_unlock(&mutex);
        sem_post(&is_empty);
        sleep(1);
    }
    return NULL;
}

/**
 * @brief Main function to initialize semaphores/mutexes and start threads.
 *
 * @return 0 on successful execution, -1 on failure.
 */
int main()
{
    pthread_t handler_producer;
    pthread_t handler_consumer;

    srand(time(NULL));

    sem_init(&is_empty, 0, 10);
    sem_init(&is_full, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    if(pthread_create(&handler_producer, NULL, &producer, NULL) != SUCCESS)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }

    if(pthread_create(&handler_consumer, NULL, &consumer, NULL) != SUCCESS)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }

    if(pthread_join(handler_producer, NULL) != SUCCESS)
    {
        printf("Thread Joining Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }

    if (pthread_join(handler_consumer, NULL) != SUCCESS)
    {
        printf("Thread Joining Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return FAILURE;
    }
    
    return 0;
}

/*
Expected Output (runs infinitely):
Consumed 3
Consumed 6
Consumed 7
Consumed 5
...
*/