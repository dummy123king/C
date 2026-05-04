/**
 * @file find_max_value.c
 * @brief Demonstrates finding the maximum value in an integer array.
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
 * @brief Finds the maximum value in an integer array.
 *
 * @param ptr Pointer to the integer array.
 * @param len Length of the array.
 * @return The maximum value in the array.
 */
int find_max_value(int *ptr, int len)
{
    int max_value = ptr[0];
    for (int i = 1; i < len; i++)
    {
        if (ptr[i] > max_value)
        {
            max_value = ptr[i];
        }
    }
    return max_value;
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
    int max_value = 0;
    int arr[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, -11};
    
    int len =  sizeof(arr)/sizeof(arr[0]);

    print_array(arr, len);
    max_value = find_max_value(arr, len);
    printf("Max value is : %d\n", max_value);
    
    return 0;
}
/*
Expected Output:
1, 2, 5, 6, 7, 8, 9, 0, 88, -11, 
Max value is : 88
*/
