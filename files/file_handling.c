/**
 * @file file_handling.c
 * @brief Demonstrates basic file opening and error handling.
 */

#include <stdio.h>
#include <errno.h>

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
    FILE *fp = fopen("text.log", "r");
    if (fp == NULL)
    {
        perror("Error");
    }

    fprintf(fp, "Hello\n");
    return 0;
}

/*
Expected Output (if text.log does not exist):
Error: No such file or directory
Segmentation fault (core dumped)
*/
