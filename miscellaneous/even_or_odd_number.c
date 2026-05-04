/**
 * @file even_or_odd_number.c
 * @brief Demonstrates checking whether an integer is even or odd.
 */

#include <stdio.h>

/**
 * @brief Checks whether an integer is even or odd using the modulo operator.
 *
 * @param data Integer to be checked.
 */
void even_or_odd(int data)
{
	if (data % 2 == 0)
		printf("%d is even number\n", data);
	else
		printf("%d is odd number\n", data);
}

/**
 * @brief Checks whether an integer is even or odd using a bitwise operator.
 *
 * @param data Integer to be checked.
 */
void even_or_odd_using_bitwise_operator(int data)
{
	if (data & 1)
		printf("%d is odd number\n", data);
	else
		printf("%d is even number\n", data);
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int data = 3;
	even_or_odd(data);
	even_or_odd_using_bitwise_operator(data);
	return 0;
}

/*
Expected Output:
3 is odd number
3 is odd number
*/
