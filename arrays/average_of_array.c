/**
 * @file average_of_array.c
 * @brief Demonstrates calculating the average of elements in an integer array.
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
 * @brief Calculates the average of all elements in an integer array.
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 * @return The average of the array elements as a double.
 */
double average_of_array(int *arr, int len)
{
    double sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    return (sum / len);
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
    double average = 0;
    print_array(arr, len);
    average = average_of_array(arr, len);
    printf("Average of array: %f\n", average);

    return 0;
}

/*
Expected Output:
1, 2, 3, 4, 
Average of array: 2.500000
*/
