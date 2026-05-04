/**
 * @file find_min_value.c
 * @brief This program finds the minimum value in an array of integers.
 *
 * It includes a function to print the array and a function to find the minimum value.
 * The main function demonstrates the usage of these functions.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of an integer array.
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
 * @brief Finds the minimum value in an integer array.
 * @param ptr Pointer to the integer array.
 * @param len Length of the array.
 * @return The minimum value in the array.
 */
int find_min_alue(int *ptr, int len)
{
    int minValue = ptr[0];
    for (int i = 1; i < len; i++)
    {
        if (ptr[i] < minValue)
        {
            minValue = ptr[i];
        }
    }
    return minValue;
}

/**
 * @brief Main function to demonstrate finding the minimum value in an array.
 * @return 0 on successful execution.
 */
int main(void)
{
    int minValue = 0;
    int arr[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, -11};
    
    int len =  sizeof(arr)/sizeof(arr[0]);

    printArray(arr, len);
    minValue = findMinValue(arr, len);
    printf("Min value is : %d\n", minValue);
    
    return 0;
}
/*
Expected Output:
1, 2, 5, 6, 7, 8, 9, 0, 88, -11, 
Min value is : -11
*/
