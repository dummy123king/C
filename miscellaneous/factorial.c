/**
 * @file factorial.c
 * @brief Demonstrates factorial calculation using iteration and recursion.
 */

#include <stdio.h>

/**
 * @brief Calculates the factorial of a number using iteration.
 *
 * @param number Number whose factorial is to be calculated.
 * @return Factorial value of @p number.
 */
unsigned long long int factorial_with_iteration(int number)
{
    unsigned long long int result = 1;

    for (int i = 1; i <= number; i++)
        result = result * i;

    return result;
}

/**
 * @brief Calculates the factorial of a number using recursion.
 *
 * @param number Number whose factorial is to be calculated.
 * @return Factorial value of @p number.
 */
unsigned long long int factorial_with_recursion(int number)
{
    // Base case: if number is 0 or 1, return 1
    if (number == 0 || number == 1)
        return 1;

    // Recursive call to calculate factorial
    return (number * factorial_with_recursion(number - 1));
}

int main(void)
{
    int data = 21;

    if (data < 0 || data > 20)
    {
        printf("Invalid input: enter a number from 0 to 20\n");
        return 1;
    }

    printf("Factorial with Iteration: %llu\n", factorial_with_iteration(data));
    printf("Factorial with Recursion: %llu\n", factorial_with_recursion(data));

    return 0;
}
