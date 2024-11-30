#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// User defined SIZEOF
#define SIZEOF(X) ({ __typeof__(X) Y; ((char *)(&Y + 1) - (char *)&Y); })

void user_defined_sizeof(void)
{
	typedef struct
	{
		int a;
	} data;
	data object = {0};
	int a = 0;
	printf("sizeof struct = %ld\n", SIZEOF(object));
}

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

void convert_little_endian_to_big_endian()
{
	uint32_t u32Result = 0;
	uint32_t u32Value = 0x12345678;

	printf("original data = 0x%x\n", u32Value);
	u32Result |= (u32Value & 0x000000FF) << 24;
	u32Result |= (u32Value & 0x0000FF00) << 8;
	u32Result |= (u32Value & 0x00FF0000) >> 8;
	u32Result |= (u32Value & 0xFF000000) >> 24;
	printf("modified = 0x%x\n", u32Result);

	printf("\n----------------------------------------------\n");

	uint32_t data = 0x12345678;
	printf("modified = 0x%x\n", data);
	data = (data & 0xff000000) >> 24 | (data & 0x00ff0000) >> 8 | (data & 0x0000ff00) << 8 | (data & 0x000000ff) << 24;
	printf("modified = 0x%x\n", data);
}

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
	} annonymous;

	printf("------------------------------------------------------->>> = %lu\n", sizeof(annonymous));

	annonymous object_1;
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

void structure_padding()
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

typedef struct name
{
	int data[3];
	char name[100];
	int marks;
} Data;

void passData(Data *obj)
{
	printf("FILE: %s, FUNC: %s, LINE: %d\n", __FILE__, __func__, __LINE__);
	printf("data  :%d\n", obj->data[0]);
	printf("data  :%d\n", obj->data[1]);
	printf("data  :%d\n", obj->data[2]);
	printf("Name  :%s\n", obj->name);
	printf("Marks  :%d\n", obj->marks);
}

int main()
{
	annonymous_use_struct_union();

	// structure_padding();

	// 	void (*fptr)(Data *) = passData;

	// 	Data obj;
	// 	obj.data[0]	= 5;
	// 	obj.data[1]	= 55;
	// 	obj.data[2]	= 56;
	// 	obj.marks = 88;
	// 	strcpy(obj.name, "Shaheena");
	// (*fptr)(&obj);
	// fptr(&obj);
	// flexible_arry();

	// passData(&obj);
	return 0;
}
