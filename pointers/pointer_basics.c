/**
 * @file pointer_basics.c
 * @brief Demonstrates various pointer operations and array passing in C.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of a 1D array using pointer arithmetic and indexing.
 *
 * @param ptr Pointer to the first element of the array.
 * @param size Number of elements in the array.
 */
void passing_one_d_array(int *ptr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", *(ptr + i));
	}
	printf("\n");
	for(int i = 0; i < size; i++)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
}

/**
 * @brief Prints the elements of a 2D array using pointer arithmetic.
 *
 * @param ptr Pointer to the first 1D array of size 3.
 * @param size Number of rows.
 * @param size2 Number of columns.
 */
void passing_two_d_array(int (*ptr)[3], int size, int size2)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			printf("%d ", *(*(ptr + i) + j));	
		}
		printf("\n");
	}
}

/**
 * @brief Prints the elements of a 3D array using array indexing and pointer arithmetic.
 *
 * @param ptr Pointer to the first 2D array of size 3x3.
 * @param size1 Size of the first dimension.
 * @param size2 Size of the second dimension.
 * @param size3 Size of the third dimension.
 */
void passing_three_d_array(int (*ptr)[3][3], int size1, int size2, int size3)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			for (int k = 0; k < size3; k++)
			{
				printf("%d ", ptr[i][j][k]);
			}
		}
		printf("\n");
	}
	printf("\n\n\n");

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			for (int k = 0; k < size3; k++)
			{
				printf("%d ", *(*(*(ptr+ i)+j)+k));
			}
		}
		printf("\n");
	}
}

/**
 * @brief Adds two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of a and b.
 */
int function_ptr(int a, int b)
{
	return a + b;
}

/**
 * @brief Compares two integers for qsort.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return Negative if a < b, 0 if a == b, positive if a > b.
 */
int compare(const void *a, const void *b)
{
	int val_a = *((int *)a);
	int val_b = *((int *)b);

	return val_a - val_b;
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	int one_d[] = {1, 2, 6, 8, 10, 12, 15};
	int two_d[2][3] = { {11, 12, 16}, 
						{18, 10, 88}
					  };
	int three_d[3][3][3] = { {{110, 111, 112}, {220, 221, 222}, {330, 331, 332}},
			 		         {{121, 122, 123}, {155, 166, 177}, {181, 100, 199}},
							 {{998, 999, 559}, {150, 185, 199}, {553, 554, 555}},
						   };
	
	passing_one_d_array(one_d, sizeof(one_d)/sizeof(one_d[0]));
	passing_two_d_array(two_d, 2, 3);
	passing_three_d_array(three_d, 3, 3, 3);

	int (*func_ptr)(int, int) = function_ptr;

	printf("fp = %d\n", (*func_ptr)(1, 3));
	printf("fp = %d\n", func_ptr(1, 3));

	int arr[] = {2, 5, 6, 4, 1, 0};
	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), compare);	
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/*
Expected Output:
1 2 6 8 10 12 15 
1 2 6 8 10 12 15 
11 12 16 
18 10 88 
110 111 112 220 221 222 330 331 332 
121 122 123 155 166 177 181 100 199 
998 999 559 150 185 199 553 554 555 



110 111 112 220 221 222 330 331 332 
121 122 123 155 166 177 181 100 199 
998 999 559 150 185 199 553 554 555 
fp = 4
fp = 4
0 1 2 4 5 6 
*/
