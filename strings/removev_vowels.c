/**
 * @file removev_vowels.c
 * @brief Demonstrates the removal of vowels from a given string.
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Removes all vowels from a given string in place.
 *
 * @param str Pointer to the string to be modified.
 */
void remove_vowels(char *str)
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

/**
 * @brief Entry point of the program.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    char str[] = "Helloo World HELLOO WORLD";
    printf("Original Str: %s\n\n", str);
    remove_vowels(str);
    printf("Modified Str: %s\n\n", str);
    return 0;
}

/*
Expected Output:
Original Str: Helloo World HELLOO WORLD

Modified Str: Hll Wrld HLL WRLD

*/