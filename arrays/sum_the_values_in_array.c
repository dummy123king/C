/**
 * @file sum_the_values_in_array.c
 * @brief Demonstrates calculating the sum of elements in an integer array.
 */

#include <stdio.h>

/**
 * @brief Prints the elements of an integer array.
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 */
void print_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Calculates the sum of all elements in an integer array.
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 * @return The sum of the array elements.
 */
int sum_of_array(int *arr, int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    return sum;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    int arr[] = {1, 2, 3, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    print_array(arr, len);
    sum = sum_of_array(arr, len);
    printf("Sum of array: %d\n", sum);

    return 0;
}

/*
Expected Output:
1, 2, 3, 4, 
Sum of array: 10
*/
