#include <stdio.h>

#include <stdio.h>

// Function to print the elements of a 2D array
void printArray(int ptr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5d, ", ptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    // Define a 2D array and initialize it with values
    int array[3][3] = {0};
    int value = 5;

    // Fill the array with increasing values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = value++;
        }
    }

    // Calculate the number of rows and columns in the array
    int rows = sizeof(array) / sizeof(array[0]);
    int cols = sizeof(array[0]) / sizeof(array[0][0]);

    // Print the array elements
    printf("\t2D-Array\n\n");
    printArray(array, rows, cols);

    return 0;
}

/*

        2D-Array

    5,     6,     7, 
    8,     9,    10, 
   11,    12,    13, 


*/