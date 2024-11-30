#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main()
{
    sem_t *semaphore;
    int value;

    semaphore = sem_open("semaphore", O_RDWR);
    if (semaphore == SEM_FAILED)
    {
        printf("Unbale to create semaphore exiting the program\n");
        exit(EXIT_FAILURE);
    }

    if (sem_getvalue(semaphore, &value) == -1)
    {
        printf("Unbale to Get semaphore value exiting the program\n");
        exit(EXIT_FAILURE);
    }
 
    printf("before critical section %d\n", value);

        if(sem_wait(semaphore) == -1)
    {
        printf("Unbale to wait exiting the program\n");
        exit(EXIT_FAILURE);
    }
   
    if (sem_getvalue(semaphore, &value) == -1)
    {
        printf("Unbale to Get semaphore value exiting the program\n");
        exit(EXIT_FAILURE);
    }
    
    printf("In critical section %d\n", value);
    sleep(5);

    if(sem_post(semaphore) == -1)
    {
        printf("Unbale to release the Semaphore exiting the program\n");
        exit(EXIT_FAILURE);        
    }

    if (sem_getvalue(semaphore, &value) == -1)
    {
        printf("Unbale to Get semaphore value exiting the program\n");
        exit(EXIT_FAILURE);
    }
    
    printf("After critical section %d\n", value);



    return 0;
}