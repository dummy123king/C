/**
 * @file reverse_array.c
 * @brief Demonstrates reversing the elements of an integer array.
 */

#include <stdio.h>

/**
 * @brief Prints the elements of an integer array.
 *
 * Time Complexity: O(N), where N is the length of the array.
 * Space Complexity: O(1).
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
 * @brief Reverses the elements of an integer array in-place.
 *
 * Time Complexity: O(N), where N is the length of the array.
 * Space Complexity: O(1).
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 */
void reverse_array(int *arr, int len)
{
    for(int i = 0, j = len - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, len);
    reverse_array(arr, len);
    print_array(arr, len);
    return 0;
}

/*
Expected Output:
1, 2, 3, 4, 5, 6, 7, 8, 9, 
9, 8, 7, 6, 5, 4, 3, 2, 1, 
*/
