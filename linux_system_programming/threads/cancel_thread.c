/**
 * @file cancel_thread.c
 * @brief Demonstrates thread cancellation in Linux using pthreads.
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Thread function that runs infinitely until canceled.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
static void *task_1(void *params)
{
    for(;;)
    {
        printf("Thread in execution\n");
        sleep(3);
    }
    printf("Thread Execution Done\n");
    return NULL;
}

/**
 * @brief Main function to demonstrate thread cancellation.
 *
 * Creates a thread, executes main thread logic for a while, and then cancels
 * the created thread.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    pthread_t thread_handle;

    if (pthread_create(&thread_handle, NULL, task_1, NULL) != 0)
    {
        perror("Thread Creation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("Main Thread is executing...\n");
        sleep(2);
    }
    
    if (pthread_cancel(thread_handle) != 0) {
        perror("Thread cancel failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main thread execution done\n");

    pthread_exit(0);  
}

/*
Expected Output:
Main Thread is executing...
Thread in execution
Main Thread is executing...
Thread in execution
Main Thread is executing...
Main Thread is executing...
Thread in execution
Main Thread is executing...
Thread in execution
Main Thread is executing...
Main Thread is executing...
Thread in execution
Main Thread is executing...
Thread in execution
Main Thread is executing...
Main Thread is executing...
Thread in execution
Main thread execution done
*/