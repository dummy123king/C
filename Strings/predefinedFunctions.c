#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t my_strlen(const char *str)
{
    uint32_t length = 0;

    while (*str++ != '\0')
        length++;
    return length;
}

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

// pass n = 0
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

char *my_strstr(const char *str, const char *substr)
{
    for (int i = 0; str[i]; i++)
    {
        int j = 0;

        if (str[i] == substr[j])
        {
            for (j = 1; substr[j]; j++)
            {
                if (str[j + i] == substr[j])
                {
                    if (substr[j + 1] == '\0')
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

char *my_strcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++) != '\0');

    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t count)
{
    int i = 0, len = 0;

    while (count-- && src[i] != '\0')
        dest[len++] = src[i++];

    dest[len] = '\0';

    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    uint32_t len = my_strlen(dest) - 1;

    char *temp = dest;
    int i = 0;
    
    while (src[i])
        temp[len++] = src[i++];
    return temp;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    char *temp = dest + my_strlen(dest) - 1;

    while (n-- && *src)
        *temp++ = *src++;

    *temp = '\0';
  
    return dest;
}

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
        // Copy from the end of the strings
        char *temp1 = dest + n - 1;
        const char *temp2 = src + n - 1;
        while (n--)
        {
            *temp1-- = *temp2--;
        }
    }
    return dest;
}

int main()
{
    char src[] = "123456789";
   
    
    return 0;
}