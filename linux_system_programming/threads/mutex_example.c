/**
 * @file mutex_example.c
 * @brief Demonstrates using a mutex to protect shared data from race conditions.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/** @brief The number of threads to create. */
#define THREAD_COUNT 2
/** @brief Success return code. */
#define SUCCESS 0
/** @brief Failure return code. */
#define FAILURE -1

/** @brief The shared integer variable that threads will increment. */
static volatile int shared_data = 0;
/** @brief Mutex to protect access to shared_data. */
pthread_mutex_t mutex;

/**
 * @brief The thread function that increments a shared variable.
 *
 * This function locks a mutex, increments the global `shared_data`, and then
 * unlocks the mutex. It repeats this for the number of iterations specified
 * by the input parameter.
 *
 * @param params A pointer to an integer specifying the number of iterations.
 * @return NULL.
 */
void *increment_task(void *params)
{
    int iteration_count = *(int *)params;
    printf("iteration count = %d\n", iteration_count);
    for (int i = 0; i < iteration_count; i++)
    {
        pthread_mutex_lock(&mutex);
        shared_data++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

/**
 * @brief Main function to demonstrate mutex usage.
 *
 * Initializes a mutex, creates multiple threads that increment a shared
 * variable, waits for them to complete, and then prints the final value.
 *
 * @return 0 on success, -1 on failure.
 */
int main()
{
    pthread_t thread_handles[THREAD_COUNT];
    pthread_mutex_init(&mutex, NULL);
    int iteration_count = 1000000;
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (pthread_create(&thread_handles[i], NULL, &increment_task, &iteration_count) != SUCCESS)
        {
            printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (pthread_join(thread_handles[i], NULL) != SUCCESS)
        {
            printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
            return FAILURE;
        }
    }
    pthread_mutex_destroy(&mutex);

    printf("==========================>>shared data %d\n", shared_data);
    return 0;
}

/*
Expected Output:
iteration count = 1000000
iteration count = 1000000
==========================>>shared data 2000000
*/