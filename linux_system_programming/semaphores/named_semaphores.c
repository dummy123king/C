/**
 * @file named_semaphores.c
 * @brief Demonstrates the creation and use of named semaphores in Linux.
 */

#include <stdio.h>
#include <sys/fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Main function to demonstrate named semaphores.
 *
 * Creates a named semaphore, waits on it, and then posts to it.
 *
 * @return 0 on successful execution.
 */
int main()
{
    int value;
    sem_t *semaphore;
    semaphore = sem_open("semaphore", O_CREAT|O_RDWR, 0777, 4);

    if (semaphore == SEM_FAILED)
    {
        printf("Unable to create semaphore exiting the program\n");
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
    sleep(10);

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
    
    if(sem_unlink("semaphore") == -1)
    {
        printf("Unable to unlink/delete semaphore exiting the program\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*
Expected Output:
before critical section 4
In critical section 3
After critical section 4
*/