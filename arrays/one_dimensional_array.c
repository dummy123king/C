/**
 * @file one_dimensional_array.c
 * @brief Demonstrates the initialization and printing of a 1D integer array.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of an integer array.
 *
 * @param ptr Pointer to the integer array.
 * @param len Length of the array.
 */
void print_array(int *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", ptr[i]);
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
    int int_array[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, 11};
    int size = sizeof(int_array)/sizeof(int_array[0]);
    print_array(int_array, size);
    return 0;
}

/*
Expected Output:
1, 2, 5, 6, 7, 8, 9, 0, 88, 11, 
*/