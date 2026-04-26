/**
 * @file reverse_a_number.c
 * @brief Demonstrates reversing the digits of an integer.
 */

#include <stdio.h>

/**
 * @brief Reverses the digits of an integer.
 *
 * @param data Integer whose digits are to be reversed.
 * @return Integer formed by reversing the digits of @p data.
 */
int reverse_number(int data)
{
	int reversed_number = 0;
	for( ; data; )
	{
		reversed_number = (data % 10) + (reversed_number * 10);
		data = data / 10;
	}
	return reversed_number;
}

int main(void)
{
	int data = 123;
	printf("before reverse = %d\n", data);
	printf("after reverse  = %d\n", reverse_number(data));

	return 0;
}
