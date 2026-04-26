#include <stdio.h>
#include <stdbool.h>

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

int main(void)
{
	int num = 121;
	printf("Number of digits in %d is %d\n", num, count_digits(num));
	return 0;
}
