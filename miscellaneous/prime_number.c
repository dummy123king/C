/**
 * @file prime_number.c
 * @brief Checks whether a number is prime.
 *
 * This file demonstrates a simple prime-number check using trial division up
 * to the square root of the number.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Checks whether the given number is prime.
 *
 * @param num Number to check.
 * @return true if @p num is prime, false otherwise.
 */
bool is_prime_number(int num)
{
	bool is_prime = true;

	if (num == 0 || num == 1)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(num); ++i)
		{
			if (num % i == 0)
			{
				is_prime = false;
				break;
			}
		}
	}

	return is_prime;
}

/**
 * @brief Demonstrates the prime-number check.
 *
 * @return 0 when the program finishes successfully.
 */
int main(void)
{
	int num = 3;

	if (is_prime_number(num))
		printf("%d is a prime number.\n", num);
	else
		printf("%d is not a prime number.\n", num);

	return 0;
}
