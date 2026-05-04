/**
 * @file cond_var.c
 * @brief Demonstrates thread synchronization using condition variables and mutexes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

/** @brief Shared data variable accessed by multiple threads. */
static volatile uint32_t shared_data = 0;

/** @brief Flag to indicate whether new data is available. */
static volatile uint8_t is_data_filled = 0;

/** @brief Mutex to protect shared data and the condition variable flag. */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/** @brief Condition variable to signal data availability. */
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

/**
 * @brief Producer thread function that periodically generates data.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
static void *task_1(void *params)
{
    for (;;)
    {
        pthread_mutex_lock(&mutex);
        shared_data += 1;
        is_data_filled = 1;
        pthread_cond_signal(&cond_var);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }    
}

/**
 * @brief Consumer thread function that waits for and reads generated data.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
static void *task_2(void *params)
{
    int read_data = 0;
    for (;;)
    {
        pthread_mutex_lock(&mutex);
        if (is_data_filled == 0)
            pthread_cond_wait(&cond_var, &mutex);
        
        read_data = shared_data;
        printf("read data = %d\n", read_data);
        is_data_filled = 0;
        pthread_mutex_unlock(&mutex);
    }    
}

/**
 * @brief Main function to demonstrate condition variables.
 *
 * Creates two threads, one producer and one consumer, and waits for them.
 *
 * @return 0 on successful execution.
 */
int main()
{
    pthread_t tid_1, tid_2;

    if (pthread_create(&tid_1, NULL, task_1, NULL) == -1)
    {
        printf("Unable to create thread - 1\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&tid_2, NULL, task_2, NULL) == -1)
    {
        printf("Unable to create thread - 2\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_join(tid_1, NULL) == -1)
    {
        printf("Unable to Join thread - 1\n");
        exit(EXIT_FAILURE);
    }

   if(pthread_join(tid_2, NULL) == -1)
    {
        printf("Unable to Join thread - 2\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*
Expected Output (runs infinitely):
read data = 1
read data = 2
read data = 3
read data = 4
...
*/