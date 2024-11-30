#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceString(char *src, char *subString, char *stringTobeReplaced)
{
    char *pos, *temp;
    int subStringLength = strlen(subString);
    int stringTobeReplacedLenght = strlen(stringTobeReplaced);
    pos = strstr(src, subString);

    while (pos != NULL)
    {
        memmove(pos + stringTobeReplacedLenght, pos + subStringLength, strlen(pos + subStringLength));
        memcpy(pos, stringTobeReplaced, stringTobeReplacedLenght);
        temp = pos;
        pos = strstr(pos + stringTobeReplacedLenght, subString);
    }
    temp[stringTobeReplacedLenght] = '\0';
}

int main(int argc, char **argv)
{
    char str[100] = "I very elegant very beautiful very very";
    char sub[] = "very";
    char newStr[] = "so"; 

    printf("\n%s\n", str);
    replaceString(str, sub, newStr);
    printf("%s\n\n", str);
    return 0;
}