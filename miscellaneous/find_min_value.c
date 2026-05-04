/**
 * @file find_min_value.c
 * @brief Demonstrates finding the minimum value in an integer array.
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
 * @brief Finds the minimum value in an integer array.
 *
 * @param ptr Pointer to the integer array.
 * @param len Length of the array.
 * @return The minimum value in the array.
 */
int find_min_value(int *ptr, int len)
{
    int min_value = ptr[0];
    for (int i = 1; i < len; i++)
    {
        if (ptr[i] < min_value)
        {
            min_value = ptr[i];
        }
    }
    return min_value;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    int min_value = 0;
    int arr[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, -11};
    
    int len =  sizeof(arr)/sizeof(arr[0]);

    print_array(arr, len);
    min_value = find_min_value(arr, len);
    printf("Min value is : %d\n", min_value);
    
    return 0;
}
/*
Expected Output:
1, 2, 5, 6, 7, 8, 9, 0, 88, -11, 
Min value is : -11
*/
