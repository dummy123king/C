#include <stdio.h>

// Function to print the elements of a 3D array
void printArray(int ptr[][3][3], int depth, int rows, int cols)
{
    for (int i = 0; i < depth; i++)
    {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                printf("%5d, ", ptr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

//Entry
int main(int argc, char **argv)
{
    // Define and initialize a 3D array
    int array[3][3][3] = {0};
    int value = 1;

    // Fill the array with increasing values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                array[i][j][k] = value++;
            }            
        }
    }

    // Calculate the number of layers, rows, and columns in the array
    int depth = sizeof(array) / sizeof(array[0]);
    int rows = sizeof(array[0]) / sizeof(array[0][0]);
    int cols = sizeof(array[0][0]) / sizeof(array[0][0][0]);
    
    // Print the array elements
    printf("\t3D-Array\n\n");
    printArray(array, depth, rows, cols);

    return 0;
}

/*
    3D-Array

Layer 1:
    1,     2,     3, 
    4,     5,     6, 
    7,     8,     9, 

Layer 2:
   10,    11,    12, 
   13,    14,    15, 
   16,    17,    18, 

Layer 3:
   19,    20,    21, 
   22,    23,    24, 
   25,    26,    27, 
*/