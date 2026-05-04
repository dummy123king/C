/**
 * @file insertion_sort.c
 * @brief Demonstrates the insertion sort algorithm on an integer array.
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
 * @brief Sorts an integer array using the insertion sort algorithm.
 *
 * @param arr Pointer to the integer array to be sorted.
 * @param len Length of the array.
 */
void insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((key < arr[j]) && j >= 0 )
        {
            arr[j + 1 ] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertion_sort(arr, len);
    print_array(arr, len);
    
    return 0;
}

/*
Expected Output:
[3, 3, 12, 5, 7, 0, 2, ]
[0, 2, 3, 3, 5, 7, 12, ]
*/