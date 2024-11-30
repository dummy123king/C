#include <stdio.h>
#include <stdlib.h>


void printArray(int *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", ptr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int intArray[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, 11};
    int size = sizeof(intArray)/sizeof(intArray[0]);
    printArray(intArray, size);
    return 0;
}


/*
1, 2, 5, 6, 7, 8, 9, 0, 88, 11
*/