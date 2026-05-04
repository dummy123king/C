/**
 * @file palindrome_number.c
 * @brief Demonstrates checking whether an integer is a palindrome.
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Reverses the digits of an integer.
 *
 * @param num The integer whose digits are to be reversed.
 * @return The integer formed by reversing the digits of @p num.
 */
int reverse_number(int num)
{
	int reversed_num = 0;
	for (;num;)
	{
		reversed_num = (reversed_num * 10) + (num % 10);
		num = num /10;
	}

	return reversed_num;
}

/**
 * @brief Checks if a given integer is a palindrome.
 *
 * @param num The integer to be checked.
 * @return true if the integer is a palindrome, false otherwise.
 */
bool is_palindrom(int num)
{
	if (num == reverse_number(num))
		return true;
	else
		return false;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int num = 121;
	if(is_palindrom(num))
		printf("%d is palindrome\n", num);
	else
		printf("%d is not palindrome\n", num);
	
	return 0;
}

/*
Expected Output:
121 is palindrome
*/
