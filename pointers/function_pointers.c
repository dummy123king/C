/**
 * @file function_pointers.c
 * @brief Demonstrates the usage of function pointers in C.
 *
 * This file provides examples of defining and using function pointers
 * to perform arithmetic operations dynamically.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Adds two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of a and b.
 */
int add(int a, int b)
{
    return (a + b);
}

/**
 * @brief Subtracts two integers.
 *
 * @param a The first integer (minuend).
 * @param b The second integer (subtrahend).
 * @return The difference of a and b (a - b).
 */
int sub(int a, int b)
{
    return (a - b);
}

/**
 * @brief Multiplies two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The product of a and b.
 */
int mul(int a, int b)
{
    return (a * b);
}

/**
 * @brief Executes an arithmetic operation using a function pointer.
 *
 * This function takes a function pointer as an argument, allowing
 * it to perform different operations (add, subtract, multiply)
 * based on the function passed.
 *
 * @param operation A pointer to a function that takes two integers and returns an integer.
 * @param a The first operand.
 * @param b The second operand.
 * @return The result of the operation.
 */
int function_ptr(int (*operation)(int, int), int a, int b)
{
    return operation(a, b);
}

/**
 * @brief Main function to demonstrate function pointer usage.
 *
 * Initializes two integers and uses the `function_ptr` to call
 * different arithmetic functions (add, multiply, subtract)
 * and print their results.
 *
 * @return 0 if the program executes successfully.
 */
int main(void)
{
    int a = 5, b = 10;
    printf("Add %d and %d is %d\n", a, b, function_ptr(add, a, b));
    printf("mul %d and %d is %d\n", a, b, function_ptr(mul, a, b));
    printf("sub %d and %d is %d\n", a, b, function_ptr(sub, a, b));

    return 0;
}

/*
Expected Output:
Add 5 and 10 is 15
mul 5 and 10 is 50
sub 5 and 10 is -5
*/