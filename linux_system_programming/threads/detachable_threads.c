/**
 * @file detachable_threads.c
 * @brief Demonstrates creating and detaching a thread in Linux using pthreads.
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief A simple thread function that prints messages and sleeps.
 *
 * @param params Unused parameter.
 * @return NULL.
 */
static void *task_1(void *params)
{
    printf("Thread in execution\n");
    sleep(3);
    printf("Thread Execution Done\n");
    return NULL;
}

/**
 * @brief Main function to demonstrate thread detachment.
 *
 * Creates a thread, detaches it so that its resources are automatically
 * released upon termination, and then the main thread exits.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return This function does not return, it exits via pthread_exit.
 */
int main(int argc, char **argv)
{
    pthread_t thread_handle;

    if (pthread_create(&thread_handle, NULL, task_1, NULL) != 0)
    {
        perror("Thread Creation failed\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_detach(thread_handle) != 0) {
        perror("Thread detachment failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main thread execution done\n");

    pthread_exit(0);
}

/*
Expected Output:
Main thread execution done
Thread in execution
Thread Execution Done
*/