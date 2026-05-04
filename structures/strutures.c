/**
 * @file strutures.c
 * @brief Demonstrates various C structure, union, and endianness concepts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief User-defined macro to calculate the size of a variable.
 */
#define SIZEOF(X) ({ __typeof__(X) Y; ((char *)(&Y + 1) - (char *)&Y); })

/**
 * @brief Demonstrates a user-defined sizeof macro on a struct.
 */
void user_defined_sizeof(void)
{
	typedef struct
	{
		int a;
	} data_t;
	data_t object = {0};
	int a = 0;
	printf("sizeof struct = %ld\n", SIZEOF(object));
}

/**
 * @brief Checks and prints the endianness of the system.
 */
void check_endianess(void)
{
	typedef union
	{
		uint32_t data;
		uint8_t last_byte;
	} test_endian_t;

	test_endian_t obj;
	obj.data = 1;
	if (obj.last_byte == 1)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
}

/**
 * @brief Demonstrates the use of anonymous structures and unions within a struct.
 */
void annonymous_use_struct_union(void)
{
	typedef struct
	{
		int data;
		union
		{
			int a;
			int b;
		};
		struct
		{
			int c;
			int d;
		};
	} annonymous_t;

	printf("------------------------------------------------------->>> = %lu\n", sizeof(annonymous_t));

	annonymous_t object_1;
	object_1.data = 5;
	object_1.a = 6;
	object_1.b = 4;
	object_1.c = 5;
	object_1.d = 1;
	printf("object_1.a    = %d\n", object_1.a);
	printf("object_1.b    = %d\n", object_1.b);
	printf("object_1.c    = %d\n", object_1.c);
	printf("object_1.d    = %d\n", object_1.d);
	printf("object_1.data = %d\n", object_1.data);
}

/**
 * @brief Demonstrates structure padding and its effect on size.
 */
void structure_padding(void)
{
	typedef struct
	{
		char char_data;
		double double_data;
		char char_data_1;
		int int_data;
		int add;
		int bitfield : 1;
	} padding_t;

	printf("%ld\n", sizeof(padding_t));
}

/**
 * @brief Demonstrates the use of a flexible array member.
 */
void flexible_arry(void)
{
	typedef struct
	{
		int data;
		int *arr;
	} flexible_array_t;

	flexible_array_t *object;
	printf("----->>>%lu\n", sizeof(object));
	object = malloc(sizeof(flexible_array_t));

	object->arr = malloc(5 * sizeof(int));

	object->arr[0] = 1;
	printf("%d\n", object->arr[0]);
	printf("----->>>%lu\n", sizeof(object));
}

/**
 * @brief Structure containing an array, string, and integer.
 */
typedef struct name
{
	int data[3];
	char name[100];
	int marks;
} data_t;

/**
 * @brief Prints the contents of a data structure.
 *
 * @param obj Pointer to the data structure.
 */
void pass_data(data_t *obj)
{
	printf("FILE: %s, FUNC: %s, LINE: %d\n", __FILE__, __func__, __LINE__);
	printf("data  :%d\n", obj->data[0]);
	printf("data  :%d\n", obj->data[1]);
	printf("data  :%d\n", obj->data[2]);
	printf("Name  :%s\n", obj->name);
	printf("Marks  :%d\n", obj->marks);
}

/**
 * @brief Entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	annonymous_use_struct_union();

	return 0;
}

/*
Expected Output:
------------------------------------------------------->>> = 16
object_1.a    = 4
object_1.b    = 4
object_1.c    = 5
object_1.d    = 1
object_1.data = 5
*/
