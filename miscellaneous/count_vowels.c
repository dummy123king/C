/**
 * @file count_vowels.c
 * @brief Demonstrates counting the number of vowels in a string.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Counts the number of vowels in a given string.
 *
 * @param ptr Pointer to the null-terminated string to be evaluated.
 * @return The total count of vowels in the string.
 */
int count_vowels(const char *ptr)
{
    int count = 0;
    
    int len = strlen(ptr);

    for (int i = 0; i < len; i++)
    {
        char ch = tolower(ptr[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }

    return count;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    int count = 0;
    char arr[] = "Count vowels in a string";
    printf("String = %s\n", arr);
    count = count_vowels(arr);
    printf("vowels count: %d\n", count);
    
    return 0;
}

/*
Expected Output:
String = Count vowels in a string
vowels count: 7
*/
