/**
 * @file palindrome_string.c
 * @brief Demonstrates checking whether a string is a palindrome.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a given string is a palindrome.
 *
 * @param str The null-terminated string to be checked.
 * @return true if the string is a palindrome, false otherwise.
 */
bool is_palindrom(char *str)
{
	int len = strlen(str);
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		if (str[i] != str[j])
			return false;
	}
	return true;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	char str[] = "madam";
	char str2[] = "hello";

	if (is_palindrom(str))
		printf("%s is palindrome\n", str);
	else
		printf("%s is not palindrome\n", str);
		
	if (is_palindrom(str2))
		printf("%s is palindrome\n", str2);
	else
		printf("%s is not palindrome\n", str2);
	

	return 0;
}

/*
Expected Output:
madam is palindrome
hello is not palindrome
*/
