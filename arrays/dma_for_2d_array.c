/**
 * @file dma_for_2d_array.c
 * @brief Demonstrates dynamic memory allocation and deallocation for a 2D array.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of a dynamically allocated 2D array.
 *
 * @param arr Pointer to the array of pointers representing the 2D array.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void print_array(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%3d, ", *( *(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Entry point of the program.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    int **arr;
    int rows = 5;
    int cols = 5;
    int value = 1;

    arr = malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = malloc(sizeof(int) * cols);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *( *(arr + i) + j) = value++;    
        }
    }
    
    print_array(arr, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        free(*( arr + i ));
    }

    free(arr);    

    return 0;
}

/*
Expected Output:
  1,   2,   3,   4,   5, 
  6,   7,   8,   9,  10, 
 11,  12,  13,  14,  15, 
 16,  17,  18,  19,  20, 
 21,  22,  23,  24,  25,
*/
