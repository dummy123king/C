#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>

static volatile int shared_data = 0;
sem_t semaphore;

void *task1(void *params)
{
    printf("Thread 1\n");
    for (size_t i = 0; i < 100000; i++)
    {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
}

void *task2(void *params)
{
    printf("Thread 2\n");
    for (size_t i = 0; i < 100000; i++)
    {
        sem_wait(&semaphore);
        shared_data++;
        sem_post(&semaphore);
    }
}

int main()
{
    int value;
    pthread_t handle1, handle2;

    if (sem_init(&semaphore, 0, 1) == -1)
    {
        printf("Unbale to create semaphore\n");
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