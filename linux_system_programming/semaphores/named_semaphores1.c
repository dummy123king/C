/**
 * @file named_semaphores1.c
 * @brief Opens and interacts with an existing named semaphore in Linux.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

/**
 * @brief Main function to access an existing named semaphore.
 *
 * Opens the named semaphore "semaphore", waits on it, enters a critical
 * section, and then posts to it.
 *
 * @return 0 on successful execution.
 */
int main()
{
    sem_t *semaphore;
    int value;

    semaphore = sem_open("semaphore", O_RDWR);
    if (semaphore == SEM_FAILED)
    {
        printf("Unable to open semaphore exiting the program\n");
        exit(EXIT_FAILURE);
    }

    if (sem_getvalue(semaphore, &value) == -1)
    {
        printf("Unable to get semaphore value exiting the program\n");
        exit(EXIT_FAILURE);
    }
 
    printf("before critical section %d\n", value);

    if(sem_wait(semaphore) == -1)
    {
        printf("Unable to wait exiting the program\n");
        exit(EXIT_FAILURE);
    }
   
    if (sem_getvalue(semaphore, &value) == -1)
    {
        printf("Unable to get semaphore value exiting the program\n");
        exit(EXIT_FAILURE);
    }
    
    printf("In critical section %d\n", value);
    sleep(5);

    if(sem_post(semaphore) == -1)
    {
        printf("Unable to release the semaphore exiting the program\n");
        exit(EXIT_FAILURE);        
    }

    if (sem_getvalue(semaphore, &value) == -1)
    {
        printf("Unable to get semaphore value exiting the program\n");
        exit(EXIT_FAILURE);
    }
    
    printf("After critical section %d\n", value);

    return 0;
}

/*
Expected Output:
before critical section 4
In critical section 3
After critical section 4
*/