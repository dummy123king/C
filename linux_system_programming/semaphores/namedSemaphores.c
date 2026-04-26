#include <stdio.h>
#include <sys/fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int value;
    sem_t *semaphore;
    semaphore = sem_open("semaphore", O_CREAT|O_RDWR, 0777, 4);

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
    sleep(10);

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
    
    if(sem_unlink("semaphore") == -1)
    {
        printf("Unbale to Unlink/Delete semaphore exiting the program\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}