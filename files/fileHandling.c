#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *fp = fopen("text.log", "r"); // Open the file "text.log" for reading
    if (fp == NULL)                    // Check if the file pointer is NULL (i.e., if fopen failed)
    {
        perror("Error"); // Print an error message along with the description of the error
    }

    fprintf(fp, "Hello\n"); // Write "Hello" to the file
    return 0;
}
