#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>

void countAllChars(char * str)
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


int main(int argc, char **argv)
{
    char str1[] = "AABBCCDDEESEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZZ";    
    countAllChars(str1);
    return 0;
}