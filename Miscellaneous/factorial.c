#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial using iteration
int factorialWithIteration(int number)
{
    int result = 1;

    // Iterate from 1 to the given number
    for (int i = 1; i <= number; i++)
    {
        // Multiply each number with the result
        result = result * i;
    }
    return result;
}

// Function to calculate factorial using recursion
int factorialWithRecursion(int number)
{
    // Base case: if number is 0, return 1
    if (number == 0)
    {
        return 1;
    }
    // Recursive call to calculate factorial
    return (number * factorialWithRecursion(number - 1));
}

int main(int argc, char **argv)
{
    // Calculate factorial using iteration and print result
    printf("Factorial with Iteration: %d\n", factorialWithIteration(5));
    
    // Calculate factorial using recursion and print result
    printf("Factorial with Recursion: %d\n", factorialWithRecursion(5));

    return 0;
}
