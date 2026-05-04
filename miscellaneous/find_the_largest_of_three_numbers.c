/**
 * @file find_the_largest_of_three_numbers.c
 * @brief Demonstrates finding the largest value among three integers.
 */

#include <stdio.h>

/**
 * @brief Finds the largest value among three integers.
 *
 * @param num1 First integer to compare.
 * @param num2 Second integer to compare.
 * @param num3 Third integer to compare.
 * @return Largest value among @p num1, @p num2, and @p num3.
 */
int find_the_largest_of_three_numbers(int num1, int num2, int num3)
{
	int largest_number = num1;

	if (largest_number < num2)
		largest_number = num2;

	if (largest_number < num3)
		largest_number = num3;

	return largest_number;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int num1 = 1;
	int num2 = 3;
	int num3 = 2;
	
	int largest_number = find_the_largest_of_three_numbers(num1, num2, num3);
	printf("Largest number = %d\n", largest_number);

	return 0;
}

/*
Expected Output:
Largest number = 3
*/
