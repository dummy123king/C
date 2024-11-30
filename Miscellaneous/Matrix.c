#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
void MatrixMultiplication()  
{
    printf("Matrix multiplication\n");   // Print message indicating matrix multiplication

    int matrix1R = 4;   // Number of rows in Matrix 1
    int matrix1C = 4;   // Number of columns in Matrix 1
    int matrix2R = 4;   // Number of rows in Matrix 2
    int matrix2C = 4;   // Number of columns in Matrix 2

    int Matrix1[matrix1R][matrix1C];   // Matrix 1
    int Matrix2[matrix2R][matrix2C];   // Matrix 2
    int ResultantMatrix[matrix1C][matrix2R];  // Resultant Matrix

    if (matrix1C != matrix2R)   // Check if multiplication is possible
    {
        printf("\nMatrix multiplication not possible\nMatrix_1 Columns should be equal to Matrix_2 rows\n"); // Print error message
    }

    int value = 1;  // Initialize value for populating matrices
    for (int i = 0; i < matrix1R; i++)   // Loop for Matrix 1
    {
        for (int j = 0; j < matrix1C; j++)
        {
            Matrix1[i][j] = value++;   // Assign value to Matrix 1 element
        }
    }
    
    value = 1;   // Reset value for populating Matrix 2
    for (int i = 0; i < matrix2R; i++)   // Loop for Matrix 2
    {
        for (int j = 0; j < matrix2C; j++)
        {
            Matrix2[i][j] = value++;   // Assign value to Matrix 2 element
        }
    }

    printf("Matrix_1\n");   // Print Matrix 1
    for (int i = 0; i < matrix1R; i++)
    {
        for (int j = 0; j < matrix1C; j++)
        {
            printf("%8d", Matrix1[i][j]);   // Print Matrix 1 element
        }
        printf("\n");
    }

    printf("Matrix_2\n");   // Print Matrix 2
    for (int i = 0; i < matrix2R; i++)
    {
        for (int j = 0; j < matrix2C; j++)
        {
            printf("%8d", Matrix2[i][j]);   // Print Matrix 2 element
        }
        printf("\n");
    }

    int sum = 0;   // Variable to hold sum during multiplication
    for (int i = 0; i < matrix1R; i++)   // Loop for multiplying matrices
    {
        for (int j = 0; j < matrix2C; j++)
        {
            sum = 0;   // Reset sum for each element in resultant matrix
            for(int k = 0; k < matrix1C; k++)
            {
                sum = sum + Matrix1[i][k]*Matrix2[k][j];   // Calculate sum for element in resultant matrix
                ResultantMatrix[i][j] = sum;   // Assign sum to resultant matrix element
            }
        }
    }

    printf("Resultant Matrix\n");   // Print Resultant Matrix
    for (int i = 0; i < matrix1C; i++)
    {
        for (int j = 0; j < matrix2R; j++)
        {
            printf("%8d", ResultantMatrix[i][j]);   // Print Resultant Matrix element
        }
        printf("\n");
    }
}

void transposeOfMatrix()  // Function to find transpose of a matrix
{
    printf("Transpose of Matrix\n");   // Print message indicating matrix transpose

    int rows = 3;   // Number of rows in the matrix
    int cols = 3;   // Number of columns in the matrix

    int matrix[rows][cols];   // Original matrix
    int ResultantMatrix[rows][cols];   // Transposed matrix

    int value = 1;   // Initialize value for populating the matrix
    for (int i = 0; i < rows; i++)   // Loop for populating the matrix
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = value++;   // Assign value to matrix element
        }
    }

    printf("Original Matrix\n");   // Print Original Matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%8d", matrix[i][j]);   // Print matrix element
        }
        printf("\n");
    }
    
    for (int  i = 0; i < rows; i++)   // Loop for finding transpose of the matrix
    {
        for (int j = 0; j < cols; j++)
        {
            ResultantMatrix[i][j] = matrix[j][i];   // Transpose the matrix
        }
    }
    printf("After Transpose\n");   // Print Transposed Matrix
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%8d", ResultantMatrix[i][j]);   // Print Transposed Matrix element
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{ 
    MatrixMultiplication();   // Call function for matrix multiplication
    transposeOfMatrix();      // Call function for matrix transpose
    return 0;   // Return 0 to indicate successful completion
}


/*
Matrix multiplication
Matrix_1
       1       2       3       4
       5       6       7       8
       9      10      11      12
      13      14      15      16
Matrix_2
       1       2       3       4
       5       6       7       8
       9      10      11      12
      13      14      15      16
Resultant Matrix
      90     100     110     120
     202     228     254     280
     314     356     398     440
     426     484     542     600
Transpose of Matrix
Original Matrix
       1       2       3
       4       5       6
       7       8       9
After Transpose
       1       4       7
       2       5       8
       3       6       9
*/