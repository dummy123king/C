/**
 * @file predefined_functions.c
 * @brief Custom implementation of standard C string and memory functions.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Calculates the length of a string.
 *
 * @param str Pointer to the string.
 * @return The number of characters in the string before the null terminator.
 */
uint32_t my_strlen(const char *str)
{
    uint32_t length = 0;

    while (*str++ != '\0')
        length++;
    return length;
}

/**
 * @brief Reverses a string in place using a two-pointer approach.
 *
 * @param str Pointer to the string to be reversed.
 */
void reverse_str_1(char *str)
{
    int len = my_strlen(str);
    for (int i = 0, j = len - 1; j > i; i++, j--)
    {
        char temp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = temp;
    }
}

/**
 * @brief Reverses a string in place using recursion.
 *
 * @param ptr Pointer to the string to be reversed.
 * @param n The current index in the string (should initially be passed as 0).
 */
void reverse_str_2(char *ptr, int n)
{
    static int count = 0;

    if (*(ptr + n) == '\0')
        return;
    
    reverse_str_2(ptr, n + 1);

    if (count <= n)
    {
        char temp = *(ptr + n);
        *(ptr + n) = *(ptr + count);
        *(ptr + count++) = temp;
    }
}

/**
 * @brief Reverses a string using an auxiliary buffer.
 *
 * @param ptr Pointer to the string to be reversed.
 */
void reverse_str_3(char *ptr)
{
    int len = my_strlen(ptr), j = 0;
    char buff[len];

    for (int i = len - 1; i >= 0; i--, j++)
        buff[j] = ptr[i];

    buff[j] = '\0';
    
    for (int i = 0; buff[i]; i++)
        ptr[i] = buff[i];
}

/**
 * @brief Finds the first occurrence of a substring in a string.
 *
 * @param str Pointer to the string to be searched.
 * @param sub_str Pointer to the substring to search for.
 * @return A pointer to the first occurrence in str, or NULL if not found.
 */
char *my_strstr(const char *str, const char *sub_str)
{
    for (int i = 0; str[i]; i++)
    {
        int j = 0;

        if (str[i] == sub_str[j])
        {
            for (j = 1; sub_str[j]; j++)
            {
                if (str[j + i] == sub_str[j])
                {
                    if (sub_str[j + 1] == '\0')
                    {
                        return (char *)(str + i);
                    }
                }
                else
                    break;
            }
        }
    }
    return NULL;
}

/**
 * @brief Copies a string to a destination buffer.
 *
 * @param dest Pointer to the destination array.
 * @param src Pointer to the string to be copied.
 * @return A pointer to the destination string.
 */
char *my_strcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++) != '\0');

    return dest;
}

/**
 * @brief Copies up to count characters from a string to a destination buffer.
 *
 * @param dest Pointer to the destination array.
 * @param src Pointer to the string to be copied.
 * @param count Maximum number of characters to copy.
 * @return A pointer to the destination string.
 */
char *my_strncpy(char *dest, const char *src, size_t count)
{
    int i = 0, len = 0;

    while (count-- && src[i] != '\0')
        dest[len++] = src[i++];

    dest[len] = '\0';

    return dest;
}

/**
 * @brief Appends a string to another string.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string to be appended.
 * @return A pointer to the resulting destination string.
 */
char *my_strcat(char *dest, const char *src)
{
    uint32_t len = my_strlen(dest) - 1;

    char *temp = dest;
    int i = 0;
    
    while (src[i])
        temp[len++] = src[i++];
    return temp;
}

/**
 * @brief Appends up to n characters from a string to another string.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string to be appended.
 * @param n Maximum number of characters to append.
 * @return A pointer to the resulting destination string.
 */
char *my_strncat(char *dest, const char *src, size_t n)
{
    char *temp = dest + my_strlen(dest) - 1;

    while (n-- && *src)
        *temp++ = *src++;

    *temp = '\0';
  
    return dest;
}

/**
 * @brief Compares two strings.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if str1 is found,
 *         respectively, to be less than, to match, or be greater than str2.
 */
int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return (*str1 - *str2);

        str1++;
        str2++;
    }
    return 0;
}

/**
 * @brief Compares up to n characters of two strings.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @param n Maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if str1 is found,
 *         respectively, to be less than, to match, or be greater than str2.
 */
int my_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n--)
    {
        if (*str1 != '\0' && *str2 != '\0')
        {
            if (*str1 != *str2)
                return (*str1 - *str2);
            str1++;
            str2++;
        }
    }
    return 0;
}

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * @param str Pointer to the string to be searched.
 * @param ch The character to be searched for.
 * @return A pointer to the first occurrence of the character, or NULL if not found.
 */
char *my_strchr(const char *str, int ch)
{
    while (*str != '\0')
    {
        if (*str == ch)
            return (char *)str;
        str++;
    }
    return NULL;
}

/**
 * @brief Finds the last occurrence of a character in a string.
 *
 * @param str Pointer to the string to be searched.
 * @param ch The character to be searched for.
 * @return A pointer to the last occurrence of the character, or NULL if not found.
 */
char *my_strrchr(const char *str, int ch)
{
    char *temp = NULL;
    while (*str)
    {
        if (*str == ch)
            temp = (char *)str;
        str++;
    }
    return temp;
}

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * @param dest Pointer to the destination array.
 * @param src Pointer to the source data.
 * @param n Number of bytes to copy.
 * @return A pointer to dest.
 */
void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *temp1 = (char *)dest;
    char *temp2 = (char *)src;
    int len = my_strlen(temp1);
    for (size_t i = 0; i < n; i++)
    {
        *(temp1 + len++) = *(temp2 + i);
    }
    return (char *)dest;
}

/**
 * @brief Moves n bytes from memory area src to memory area dest, handling overlapping regions.
 *
 * @param dest Pointer to the destination array.
 * @param src Pointer to the source data.
 * @param n Number of bytes to move.
 * @return A pointer to dest.
 */
void *my_memmove(void *dest, const void *src, size_t n)
{
    char *temp1 = dest;
    const char *temp2 = src;

    if (temp1 < temp2)
    {
        while (n--)
        {
            *temp1++ = *temp2++;
        }
    }
    else
    {
        char *temp1 = dest + n - 1;
        const char *temp2 = src + n - 1;
        while (n--)
        {
            *temp1-- = *temp2--;
        }
    }
    return dest;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    char src[] = "123456789";
    printf("Length of src: %u\n", my_strlen(src));
    
    return 0;
}

/*
Expected Output:
Length of src: 9
*/