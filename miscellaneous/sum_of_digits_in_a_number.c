#include <stdio.h>
#include <stdbool.h>

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

int main(void)
{
	int num = 1234;
	printf("Sum of digits %d is %d\n", num, sum_of_digits(num));
	return 0;
}
