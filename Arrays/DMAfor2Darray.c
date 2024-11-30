/*
 *This program allocates the memory for 2-D array and frees the allocated memory
*          
*        Output
* -------------------------------------------------------------------------------
*  1,   2,   3,   4,   5, 
*  6,   7,   8,   9,  10, 
* 11,  12,  13,  14,  15, 
* 16,  17,  18,  19,  20, 
* 21,  22,  23,  24,  25,
*
*
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%3d, ", *( *(arr + i) + j));
            // printf("%3d, ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


//Entry
int main(int argc, char **argv)
{
    int **arr;
    int rows = 5;
    int cols = 5;
    int value = 1;

    arr = malloc(sizeof(int *) * rows); // allocate the memory for array of pointers

    //Allocate the memory for onedimensional array
    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = malloc(sizeof(int) * cols);
    }

    // Add data to memory
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *( *(arr + i) + j) = value++;    
        }
    }
    
    printArray(arr, rows, cols);

    //Free the allocated memory of one dimensional array
    for (int i = 0; i < rows; i++)
    {
        free(*( arr + i ));
    }

    //Free the allocated memory of array of pointers
    free(arr);    

    return 0;
}
