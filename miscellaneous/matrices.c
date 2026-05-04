/**
 * @file matrices.c
 * @brief Demonstrates matrix operations such as multiplication and transpose.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Performs matrix multiplication on two predefined matrices and prints the result.
 */
void matrix_multiplication(void)
{
    printf("Matrix multiplication\n");

    int matrix1_rows = 4;
    int matrix1_cols = 4;
    int matrix2_rows = 4;
    int matrix2_cols = 4;

    int matrix1[matrix1_rows][matrix1_cols];
    int matrix2[matrix2_rows][matrix2_cols];
    int resultant_matrix[matrix1_cols][matrix2_rows];

    if (matrix1_cols != matrix2_rows)
    {
        printf("\nMatrix multiplication not possible\nMatrix_1 Columns should be equal to Matrix_2 rows\n");
    }

    int value = 1;
    for (int i = 0; i < matrix1_rows; i++)
    {
        for (int j = 0; j < matrix1_cols; j++)
        {
            matrix1[i][j] = value++;
        }
    }
    
    value = 1;
    for (int i = 0; i < matrix2_rows; i++)
    {
        for (int j = 0; j < matrix2_cols; j++)
        {
            matrix2[i][j] = value++;
        }
    }

    printf("Matrix_1\n");
    for (int i = 0; i < matrix1_rows; i++)
    {
        for (int j = 0; j < matrix1_cols; j++)
        {
            printf("%8d", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix_2\n");
    for (int i = 0; i < matrix2_rows; i++)
    {
        for (int j = 0; j < matrix2_cols; j++)
        {
            printf("%8d", matrix2[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < matrix1_rows; i++)
    {
        for (int j = 0; j < matrix2_cols; j++)
        {
            sum = 0;
            for(int k = 0; k < matrix1_cols; k++)
            {
                sum = sum + matrix1[i][k] * matrix2[k][j];
                resultant_matrix[i][j] = sum;
            }
        }
    }

    printf("Resultant Matrix\n");
    for (int i = 0; i < matrix1_cols; i++)
    {
        for (int j = 0; j < matrix2_rows; j++)
        {
            printf("%8d", resultant_matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Calculates and prints the transpose of a predefined matrix.
 */
void transpose_of_matrix(void)
{
    printf("Transpose of Matrix\n");

    int rows = 3;
    int cols = 3;

    int matrix[rows][cols];
    int resultant_matrix[rows][cols];

    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = value++;
        }
    }

    printf("Original Matrix\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int  i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            resultant_matrix[i][j] = matrix[j][i];
        }
    }
    printf("After Transpose\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%8d", resultant_matrix[i][j]);
        }
        printf("\n");
    }
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
    matrix_multiplication();
    transpose_of_matrix();
    return 0;
}


/*
Expected Output:
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