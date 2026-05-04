/**
 * @file counte_repeated_digits.c
 * @brief Demonstrates finding the most repeated digit in a number.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds and prints the most repeated digit in a given number.
 *
 * @param n The number to be evaluated.
 * @return The maximum count of the repeated digit, or -1 if no digit is repeated.
 */
int most_repeated_digit(long unsigned int n) 
{
    int digit_count[10] = {0};
    int max_count = 0;
    int repeated_digit = -1;
    
    while (n > 0) {
        int digit = n % 10;
        digit_count[digit]++;
        n /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > max_count) {
            max_count = digit_count[i];
            repeated_digit = i;
        }
    }

    if (max_count <= 1) {
        return -1;
    }
    
    printf("%d is repeated %d times\n", repeated_digit, max_count);
    
    return max_count;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void) {
    long unsigned int n = 555544444;
    most_repeated_digit(n);
    return 0;
}

/*
Expected Output:
4 is repeated 5 times
*/