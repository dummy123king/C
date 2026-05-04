/**
 * @file find_second_max.c
 * @brief Demonstrates finding the second maximum value in an integer array.
 */

#include <stdio.h>

/**
 * @brief Finds the second maximum value in an integer array.
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 * @return The second maximum value in the array.
 */
int second_max(int *arr, int len)
{
    int max1 = arr[0];
    int max2 = arr[1];

    if (max2 > max1)
    {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for (int i = 2; i < len; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        
        else if (arr[i] > max2 && arr[i] != max1)
        {
            max2 = arr[i];
        }
    }
    return max2;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main()
{
    int arr[10] = {1, -10, 5, 333, 999, 11, 888, 555, 999, 100};
    int len = sizeof(arr) / sizeof(arr[1]);
    printf("Second max = %d\n", second_max(arr, len));
    return 0;
}

/*
Expected Output:
Second max = 888
*/
