#include <stdio.h>
#include <stdbool.h>

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


bool is_palindrom(int num)
{
	if (num == reverse_number(num))
		return true;
	else
		return false;
}


int main(void)
{
	int num = 121;
	if(is_palindrom(num))
		printf("%d is palindrome\n", num);
	else
		printf("%d is not palindrome\n", num);
	
	return 0;
}
