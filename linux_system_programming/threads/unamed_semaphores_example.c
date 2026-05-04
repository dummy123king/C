/**
 * @file unamed_semaphores_example.c
 * @brief Demonstrates thread synchronization using POSIX unnamed semaphores.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

/** @brief The number of threads to create. */
#define THREAD_COUNT 2
/** @brief Success return code. */
#define SUCCESS 0
/** @brief Failure return code. */
#define FAILURE -1

/** @brief Shared data variable incremented by multiple threads. */
static volatile int shared_data = 0;

/** @brief Unnamed semaphore used to protect the shared data. */
sem_t semaphore;

/**
 * @brief The thread function that increments the shared variable.
 *
 * Locks the semaphore, increments the global `shared_data` variable 1,000,000
 * times, and unlocks the semaphore for each iteration.
 *
 * @param params Pointer to a dynamically allocated integer specifying the thread number.
 * @return NULL.
 */
void *task(void *params)
{
    printf("From Task %d\n", *(int *)params);
    
    for (int  i = 0; i < 1000000; i++)
    {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
    free(params);
    return NULL;
}

/**
 * @brief Main function to initialize the semaphore, create threads, and wait for them.
 *
 * @return 0 on successful execution, -1 on failure.
 */
int main()
{
    pthread_t handles[THREAD_COUNT];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        int *thread_number = malloc(sizeof(int));
        *thread_number = i + 1;
        if (pthread_create(&handles[i], NULL, &task, thread_number) != SUCCESS)
        {
            printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }
    
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (pthread_join(handles[i], NULL) != SUCCESS)
        {
            printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }

    sem_destroy(&semaphore);
    printf("Shared Data = %d\n", shared_data);
    return 0;
}

/*
Expected Output:
From Task 1
From Task 2
Shared Data = 2000000
*/
