/**
 * @file count_all_chars_in_string.c
 * @brief Demonstrates counting the occurrences of each character in a string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>

/**
 * @brief Counts and prints the occurrences of each character in a string.
 *
 * @param str Pointer to the string to be processed. The string is modified in place.
 */
void count_all_chars(char *str)
{
	int count = 0;
	int len = strlen(str);
	
	for(int i = 0; i < len; i++)
	{
		count = 1;
		for(int j = i + 1; j < len; j++)
		{
			if(str[i] == '\0')
			{
                continue;
			}
			if(str[i] == str[j])
			{
				count++;
				str[j] = '\0';
			}
		}
		if(str[i] != '\0')
		{
			printf("%c---->%d\n", str[i], count);
		}
	}
}

/**
 * @brief Entry point of the program.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    char str1[] = "AABBCCDDEESEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZZ";    
    count_all_chars(str1);
    return 0;
}

/*
Expected Output:
A---->2
B---->2
C---->2
D---->2
E---->4
S---->3
F---->2
G---->2
H---->2
I---->2
J---->2
K---->2
L---->2
M---->2
N---->2
O---->2
P---->2
Q---->2
R---->2
T---->2
U---->2
V---->2
W---->2
X---->2
Y---->2
Z---->3
*/