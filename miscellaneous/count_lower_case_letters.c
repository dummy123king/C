/**
 * @file count_lower_case_letters.c
 * @brief Demonstrates counting the number of lowercase letters in a string.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Counts the number of lowercase letters in a given string.
 *
 * @param ptr Pointer to the null-terminated string to be evaluated.
 * @return The total count of lowercase letters in the string.
 */
int count_lower_case_letters(const char *ptr)
{
    int count = 0;
    int len = strlen(ptr);

    for (int i = 0; i < len; i++)
    {
        if (islower(ptr[i]))
        {
            count++;
        }
    }
    return count;
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
    int count = 0;
    char arr[] = "Count Lower Case Letters";
    printf("String = %s\n", arr);

    count = count_lower_case_letters(arr);
    printf("Lower case letter count : %d\n", count);
    
    return 0;
}

/*
Expected Output:
String = Count Lower Case Letters
Lower case letter count : 17
*/
