/**
 * @file sum_of_digits_in_a_number.c
 * @brief Demonstrates calculating the sum of digits of an integer.
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Calculates the sum of the digits of a given integer.
 *
 * @param num The integer whose digits are to be summed.
 * @return The sum of the digits.
 */
int sum_of_digits(int num)
{
	int sum_of_digits = 0;

	for (;num;)
	{
		sum_of_digits = sum_of_digits + (num % 10);
		num = num /10;
	}

	return sum_of_digits;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int num = 1234;
	printf("Sum of digits %d is %d\n", num, sum_of_digits(num));
	return 0;
}

/*
Expected Output:
Sum of digits 1234 is 10
*/
