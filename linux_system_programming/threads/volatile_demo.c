/**
 * @file volatile_demo.c
 * @brief Demonstrates the use of the volatile keyword in multithreading.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

/** @brief Shared variable to communicate between threads. */
int volatile shared_data = 0;

/**
 * @brief Thread function that waits for the shared variable to change.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
void *task_1(void *params)
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
    return NULL;
}

/**
 * @brief Thread function that modifies the shared variable after a delay.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
void *task_2(void *params)
{
    printf("Thread - 2 \n");
    sleep(5);
    shared_data = 5;
    printf("Thread - 2 exited\n");
    return NULL;
 }

/**
 * @brief Main function to initialize threads and demonstrate volatile usage.
 *
 * @return 0 on successful execution, -1 on failure.
 */
int main()
{
    pthread_t handle_1, handle_2;

    if (pthread_create(&handle_1, NULL, &task_1, NULL) != 0)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_create(&handle_2, NULL, &task_2, NULL) != 0)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_join(handle_1, NULL) != 0)
    {
        printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_join(handle_2, NULL) != 0)
    {
        printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    return 0;
}

/*
Expected Output:
Thread - 1 
Thread - 2 
Thread - 2 exited
Thread - 1 exited
*/