/**
 * @file three_dimensional_array.c
 * @brief Demonstrates the initialization and printing of a 3D integer array.
 */

#include <stdio.h>

/**
 * @brief Prints the elements of a 3D array.
 *
 * @param ptr Pointer to the 3D integer array.
 * @param depth Number of layers (depth) in the array.
 * @param rows Number of rows in each layer.
 * @param cols Number of columns in each layer.
 */
void print_array(int ptr[][3][3], int depth, int rows, int cols)
{
    for (int i = 0; i < depth; i++)
    {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                printf("%5d, ", ptr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
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
    int array[3][3][3] = {0};
    int value = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                array[i][j][k] = value++;
            }            
        }
    }

    int depth = sizeof(array) / sizeof(array[0]);
    int rows = sizeof(array[0]) / sizeof(array[0][0]);
    int cols = sizeof(array[0][0]) / sizeof(array[0][0][0]);
    
    printf("\t3D-Array\n\n");
    print_array(array, depth, rows, cols);

    return 0;
}

/*
Expected Output:
    3D-Array

Layer 1:
    1,     2,     3, 
    4,     5,     6, 
    7,     8,     9, 

Layer 2:
   10,    11,    12, 
   13,    14,    15, 
   16,    17,    18, 

Layer 3:
   19,    20,    21, 
   22,    23,    24, 
   25,    26,    27, 
*/