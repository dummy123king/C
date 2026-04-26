#include <stdio.h>

// Function to calculate Fibonacci series using iteration
void fibonacciWithIteration(int number)
{
    int n1 = 0, n2 = 1, fib = 0;

    // Print the first two Fibonacci numbers (0 and 1)
    printf("%d, %d, ", n1, n2);

    // Iterate to calculate and print subsequent Fibonacci numbers
    for (int i = 2; i < number; i++)
    {
        fib = n1 + n2;  // Calculate the next Fibonacci number
        n1 = n2;        // Update n1 to the previous value of n2
        n2 = fib;       // Update n2 to the newly calculated Fibonacci number
        printf("%d, ", fib);  // Print the Fibonacci number
    }
    printf("\n\n"); // Print a newline for better formatting
}

// Function to calculate Fibonacci series using recursion
int fibonacciWithRecursion(int number)
{
    // Base cases: return 0 for 0th Fibonacci number, and 1 for 1st Fibonacci number
    if (number == 0)
    {
        return 0;
    }
    if (number == 1)
    {
        return 1;
    }

    // Recursive call to calculate the nth Fibonacci number
    return (fibonacciWithRecursion(number - 1) + fibonacciWithRecursion(number - 2));
}

int main(int argc, char **argv)
{
    // Calculate and print Fibonacci series using iteration for the first 10 numbers
    fibonacciWithIteration(10);

    // Calculate and print Fibonacci series using recursion for the first 10 numbers
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d, ", fibonacciWithRecursion(i));
    }
    printf("\n\n"); // Print a newline for better formatting
    
    return 0;
}
