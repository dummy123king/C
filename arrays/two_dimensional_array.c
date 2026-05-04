/**
 * @file two_dimensional_array.c
 * @brief Demonstrates the initialization and printing of a 2D integer array.
 */

#include <stdio.h>

/**
 * @brief Prints the elements of a 2D array.
 *
 * @param ptr Pointer to the 2D integer array.
 * @param rows Number of rows in the array.
 * @param cols Number of columns in the array.
 */
void print_array(int ptr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5d, ", ptr[i][j]);
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
    int array[3][3] = {0};
    int value = 5;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = value++;
        }
    }

    int rows = sizeof(array) / sizeof(array[0]);
    int cols = sizeof(array[0]) / sizeof(array[0][0]);

    printf("\t2D-Array\n\n");
    print_array(array, rows, cols);

    return 0;
}

/*
Expected Output:
        2D-Array

    5,     6,     7, 
    8,     9,    10, 
   11,    12,    13, 

*/