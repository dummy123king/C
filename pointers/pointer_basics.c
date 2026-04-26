#include <stdio.h>
#include <stdlib.h>


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
}

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

int functionptr(int a, int b)
{
	return a + b;
}

int compare(const void* a, const void * b)
{
	int A = *((int *)a);
	int B = *((int *)b);

	return A - B;
}


int main()
{

	//-----------------*****--One dimensional ARRAY-------------------------------------
	/*int one_d[] = {1, 2, 6, 8, 10, 12, 15};

	for (int i = 0; i < sizeof(one_d)/sizeof(one_d[0]); i++)
	{
		printf("arr[%d] = %d ", i, one_d[i]);
	}
	printf("\n\n\n");

	for (int i = 0; i < sizeof(one_d)/sizeof(one_d[0]); i++)
	{
		printf("*(arr + %d) = %d ", i, *(one_d + i));
	}
	printf("\n\n\n");*/

	//----------------------------Two dimensional array -------------------------------------
	/*int two_d[2][3] = { {11, 12, 16}, 
						{18, 10, 88}
					  };
	
	for (int i = 0; i < sizeof(two_d)/sizeof(two_d[0]); i++)
	{
		int sub_array_length = sizeof(two_d[i])/sizeof(two_d[i][0]);

		for (int j = 0; j < sub_array_length; j++)
		{
			printf("%d ", two_d[i][j]);
		}
	}
	printf("\n\n\n");

	for (int i = 0; i < sizeof(two_d)/sizeof(two_d[0]); i++)
	{
		int sub_array_length = sizeof(two_d[i])/sizeof(two_d[i][0]);

		for (int j = 0; j < sub_array_length; j++)
		{
			printf("%d ", *(*(two_d + i)+ j));
		}
	}

	printf("\n\n\n");*/

//----------------------------three dimensional array -------------------------------------
	/*int three_d[3][3][3] = { {{110, 111, 112}, {220, 221, 222}, {330, 331, 332}},
			 		         {{121, 122, 123}, {155, 166, 177}, {181, 100, 199}},
							 {{998, 999, 559}, {150, 185, 199}, {553, 554, 555}},
						   };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("{ ");
			for (int k = 0; k < 3; k++)
			{
				printf("%d ", three_d[i][j][k]);
			}
			printf(" }");
		}
		printf("\n\n");
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("{ ");
			for (int k = 0; k < 3; k++)
			{
				printf("%d, ", *(*(*(three_d + i) + j)+ k));
			}
			printf(" }");
		}
		printf("\n\n");
	}*/

	int one_d[] = {1, 2, 6, 8, 10, 12, 15};

	int two_d[2][3] = { {11, 12, 16}, 
						{18, 10, 88}
					  };
	int three_d[3][3][3] = { {{110, 111, 112}, {220, 221, 222}, {330, 331, 332}},
			 		         {{121, 122, 123}, {155, 166, 177}, {181, 100, 199}},
							 {{998, 999, 559}, {150, 185, 199}, {553, 554, 555}},
						   };
	
	//passing_one_d_array(one_d, sizeof(one_d)/sizeof(one_d[0]));
	//passing_two_d_array(two_d, 2, 3);
	//passing_three_d_array(&three_d, 3, 3, 3);


	//int (*fp)(int, int) = functionptr;

	//printf("fp = %d\n", (*fp)(1, 3));
	//printf("fp = %d\n", fp(1, 3));

	int arr[] = {2, 5, 6, 4, 1, 0};
	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), compare);	
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	

	return 0;

}
