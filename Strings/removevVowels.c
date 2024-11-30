#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>

void removeVowels(char *str)
{
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'  ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ))
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main(int argc, char **argv)
{
    char str[] = "Helloo World HELLOO WORLD";
    printf("Original Str: %s\n\n", str);
    removeVowels(str);
    printf("Modified Str: %s\n\n", str);
    return 0;
}