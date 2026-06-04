/**
 * @file count_occurrences_digit.c
 * @brief Demonstrates counting the occurrences of a specific digit in an array.
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Counts the occurrences of a specific digit in an integer array.
 *
 * @param arr Pointer to the integer array.
 * @param len Length of the array.
 * @param num The digit to count occurrences of.
 * @return The number of times the digit appears in the array.
 */
int count_occurances_digit(int *arr, int len, int num) 
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (num == arr[i])
        {
            count++;
        }
    }
    
    return count;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void) {

    int arr[] = {0, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[1]);
    int count = 0;
    int digit = 5;

    count = count_occurances_digit(arr, len, 5);
    printf("%d is repeated %d times\n", digit, count);

    return 0;
}

/*
Expected Output:
5 is repeated 3 times
*/
