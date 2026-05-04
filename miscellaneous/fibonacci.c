/**
 * @file fibonacci.c
 * @brief Demonstrates Fibonacci sequence generation using iteration and recursion.
 */

#include <stdio.h>

/**
 * @brief Prints the Fibonacci sequence up to a given number of terms using iteration.
 *
 * @param number The number of terms to print.
 */
void fibonacci_with_iteration(int number)
{
    int n1 = 0, n2 = 1, fib = 0;

    printf("0, ");

    if (number == 1)
    {
        printf("\n\n");
        return;
    }

    printf("%d, %d, ", n1, n2);

    for (int i = 2; i < number; i++)
    {
        fib = n1 + n2;
        n1 = n2;
        n2 = fib;
        printf("%d, ", fib);
    }

    printf("\n\n");
}

/**
 * @brief Calculates the nth Fibonacci number using recursion.
 *
 * @param number The index of the Fibonacci number to calculate (0-based).
 * @return The nth Fibonacci number, or -1 if the input is negative.
 */
int fibonacci_with_recursion(int number)
{
    if (number < 0)
        return -1;

    if (number == 0)
        return 0;

    if (number == 1)
        return 1;

    return (fibonacci_with_recursion(number - 1) + fibonacci_with_recursion(number - 2));
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    fibonacci_with_iteration(1);

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d, ", fibonacci_with_recursion(i));
    }
    printf("\n\n");
    
    return 0;
}

/*
Expected Output:
0, 

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 

*/
