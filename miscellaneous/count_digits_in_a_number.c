/**
 * @file count_digits_in_a_number.c
 * @brief Demonstrates counting the number of digits in an integer.
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Counts the number of digits in a given integer.
 *
 * @param num The integer whose digits are to be counted.
 * @return The number of digits in the integer.
 */
int count_digits(int num)
{
	int no_of_digits = 0;

	for (;num;)
	{
		num = num /10;
		no_of_digits++;
	}

	return no_of_digits;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int num = 121;
	printf("Number of digits in %d is %d\n", num, count_digits(num));
	return 0;
}

/*
Expected Output:
Number of digits in 121 is 3
*/
