/**
 * @file swap_two_numbers.c
 * @brief Demonstrates swapping two integers with and without using a temporary variable.
 */

#include <stdio.h>

/**
 * @brief Swaps two integer values without using a temporary variable.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap_two_numbers_without_temp_variable(int *a, int *b)
{
	if (a == b)
		return;

	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 * @brief Swaps two integer values using a temporary variable.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap_two_numbers_with_temp_variable(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int a = 10;
	int b = 20;

	printf("Before swap:\na = %d\nb = %d\n", a, b);

	// swap_two_numbers_without_temp_variable(&a, &b);
	swap_two_numbers_with_temp_variable(&a, &b);

	printf("\nAfter swap:\na = %d\nb = %d\n", a, b);

	return 0;
}

/*
Expected Output:
Before swap:
a = 10
b = 20

After swap:
a = 20
b = 10
*/
