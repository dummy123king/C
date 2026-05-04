/**
 * @file bubble_sort.c
 * @brief Demonstrates the bubble sort algorithm on an integer array.
 */

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
 * @brief Sorts an integer array using the bubble sort algorithm.
 *
 * @param arr Pointer to the integer array to be sorted.
 * @param len Length of the array.
 */
void bubble_sort(int *arr, int len)
{
    bool is_swapped;

    for (int i = 0; i < len - 1; i++)
    {
        is_swapped = false;
        for (int j = 0; j < len - 1 -i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                is_swapped = true;
            }
        }
        if (is_swapped != true)
        {
            break;
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
    bubble_sort(arr, len);
    print_array(arr, len);
    
    return 0;
}

/*
Expected Output:
[3, 3, 12, 5, 7, 0, 2, ]
[0, 2, 3, 3, 5, 7, 12, ]
*/