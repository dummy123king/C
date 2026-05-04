/**
 * @file replace_string.c
 * @brief Demonstrates string manipulation by replacing all occurrences of a substring.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Replaces all occurrences of a substring with another string in a given string.
 *
 * @param src The original string to be modified. Ensure the buffer is large enough if the new string is longer.
 * @param sub_string The substring to find within the original string.
 * @param string_to_be_replaced The string to replace the matched substring with.
 */
void replace_string(char *src, const char *sub_string, const char *string_to_be_replaced)
{
    char *pos = NULL;
    int sub_string_length = strlen(sub_string);
    int string_tobe_replaced_length = strlen(string_to_be_replaced);

    pos = strstr(src, sub_string);

    while (pos != NULL)
    {
        // Move the remaining string along with its null terminator
        memmove(pos + string_tobe_replaced_length, pos + sub_string_length, strlen(pos + sub_string_length) + 1);
        memcpy(pos, string_to_be_replaced, string_tobe_replaced_length);
        pos = strstr(pos + string_tobe_replaced_length, sub_string);
    }
}

/**
 * @brief Entry point of the program.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(void)
{
    char str[100] = "I very elegant very beautiful very very";
    char sub[] = "very";
    char newStr[] = "so"; 

    printf("\n%s\n", str);
    replace_string(str, sub, newStr);
    printf("%s\n\n", str);
    return 0;
}