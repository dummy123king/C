/**
 * @file selection_sort.c
 * @brief Demonstrates the selection sort algorithm on an integer array.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Prints the elements of an integer array.
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 */
void print_array(int *arr, int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

/**
 * @brief Sorts an integer array using the selection sort algorithm.
 *
 * @param arr Pointer to the integer array to be sorted.
 * @param len Length of the array.
 */
void selection_sort(int *arr, int len)
{
    int min_index;

    for (int i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    int arr[] = {3, 3, 12, 5, 7, 0, 2};

    int len = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, len);
    selection_sort(arr, len);
    print_array(arr, len);
    
    return 0;
}

/*
Expected Output:
[3, 3, 12, 5, 7, 0, 2, ]
[0, 2, 3, 3, 5, 7, 12, ]
*/