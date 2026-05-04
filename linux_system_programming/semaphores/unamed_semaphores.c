/**
 * @file unamed_semaphores.c
 * @brief Demonstrates the use of unnamed semaphores for thread synchronization in Linux.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>

/** @brief Shared resource accessed by multiple threads. */
static volatile int shared_data = 0;

/** @brief Unnamed semaphore for synchronizing access to shared_data. */
sem_t semaphore;

/**
 * @brief First thread function to increment shared data.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
void *task1(void *params)
{
    printf("Thread 1\n");
    for (size_t i = 0; i < 100000; i++)
    {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
    return NULL;
}

/**
 * @brief Second thread function to increment shared data.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
void *task2(void *params)
{
    printf("Thread 2\n");
    for (size_t i = 0; i < 100000; i++)
    {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
    return NULL;
}

/**
 * @brief Main function to demonstrate unnamed semaphores.
 *
 * Initializes the semaphore, creates two threads that access the shared
 * data concurrently, and then prints the final value of the shared data.
 *
 * @return 0 on successful execution.
 */
int main()
{
    int value;
    pthread_t handle1, handle2;

    if (sem_init(&semaphore, 0, 1) == -1)
    {
        printf("Unable to create semaphore\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&handle1, NULL, task1, NULL) != 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&handle2, NULL, task2, NULL) != 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(handle1, NULL) != 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(handle2, NULL) != 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    printf("shared Data = %d\n", shared_data);

    if (sem_destroy(&semaphore) != 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*
Expected Output:
Thread 1
Thread 2
shared Data = 200000
*/