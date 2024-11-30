what are interrupts and execptions?

what will happen when we disable global interrupt handling system?

What is ISR?
	An ISR refers to the Interrupt Service Routines.
   	These are procedures stored at specific memory addresses which are called when a certain type of interrupt occurs.
   	The Cortex-M processors family has the NVIC that manages the execution of the interrupt.

what is interrupt latancy? How can we reduce it?
   	It is an important question that is asked by the interviewer to test the understanding of Interrupt.
   	Basically, interrupt latency is the number of clock cycles that are taken by the processor to respond to an interrupt request. 
   	This number of the clock cycle is count between the assertions of the interrupt request and the first instruction of the interrupt handler.
What is a nested interrupt?
		In a nested interrupt system, an interrupt is allowed to any time and anywhere even an ISR is being executed.
		But, only the highest priority ISR will be executed immediately.
        The second highest priority ISR will be executed after the highest one is completed.
  
What is NVIC in ARM Cortex?
	The Nested Vector Interrupt Controller (NVIC) in the Cortex-M processor family is an example of an interrupt controller with externmely 
    flexible interrupt priority management. It enables programmable priority levels, 
	automatic nested interrupt support, along with support for multiple interrupt masking, whilst still being very easy to use by the programmer.
	The Cortex-M3 and Cortex-M4 processors the NVIC supports up to 240 interrupt inputs, with 8 up to 256 programmable priority levels

what is watchdog timer??
	A watchdog timer is a simple countdown timer which is used to reset a microprocessor after a specific interval of time.
	In a properly operating system, software will periodically "pet" or restart the watchdog timer.
	After being restarted, the watchdog will begin timing another predetermined interval.
	When software or the device is not functioning correctly, software will not restart the watchdog timer before it times out.
	When the watchdog timer times out, it will cause a reset of the microcontroller. If the system software has been designed correctly and there 
	has been no hardware failure, the reset will cause the system to operate properly again. The reset condition must be a "safe" state. 
	For instance, it would not be wise to have the reset state of a magnetic stripe card reader enabling the write head.


what is bark and bite in watchdog timer??

how many types of interrupts are there?
	2 types Edge trigger and level trigger

what are pointers why use them??

what is data abort?

what is volatile?

what is memory leak?

what is dangling pointer??

what is void or generic pointer??

what is wild pointer??

difference between static and extern??

what is cache??

what is cache coherance??

what are the cache write schemes??

what is segmentation fault??

clear nth bit in given number?

set nth bit in given number?

toggle nth bit in given number?

rotate bits (left or right) by n time?

what is stack??

how you will find given string is palindrom or not by using stack?

what is semaphore and mutex??

what is the difference between stack and heap??

what is the difference between thread and process??

What is deadlock?

what is schedular?

what are IPCs and why shuold we use that??
	it shuold be used when two process running independently those two process will have different memory regions in RAM so they cant exchange the data directly so we need IPCs to exchange the data
what you will get with producer and consumer problem??

which IPC is faster? and why??

what is the output of the below programm??
	int *ptr = &a;
	printf("%p\n", ptr);
	printf("%p\n", &a);
	printf("%p\n", &ptr);
	printf("%p\n", &*ptr);

what is what is MESI and MOESI?

what is AXI, APB and AHB??

what are the initial requirements to access an IP(ex:UART)??
	Need to enable the bus power line(APB or AHB)
	need to power  perticular IP connected line
	need to Configure the clock for that IP
	need to send hand shake data
	after that need send instruction set to access registers using instruction bus
	once we send the address we can get the data on the data bus.
	once the data access completed we need to close the communication and turn off everything related to that IP to save power.

what is the wait.run() in CMM script?

you got a situation where data abort came how you will debug??

what is the difference between struct and union??

what is self-referential structure?

why we are using structure padding?

what is #pragma pack(1)??

what are bit fields??

can we apply bit fields to float data type member??

explain the booting sequence of the micro controller??

what will happen when you power on the micro controller??

what is virtual memory??

what is page fault??

what is bit flip??

what is unhandled page fault?

what will happen when we allocate malloc(0)?? how much memory will allocate?

what is function pointer and write syntax for function pointer and where it will be used?

Compilation stages?

how manu storage classes are there??

explain about below declarations
	const int *ptr;
	int *const ptr1;
	const int *const ptr1;

explain recursion in C.
	Recursion is the process when a function calls itself, directly or indirectly. Such a function is called a recursive function. 
	There are two phases involved with a recursive function:
	-> Winding phase - It starts when the recursive function calls itself and ends once the condition is reached.
	-> Unwinding phase - Starts when the condition is reached, i.e., when the winding phase ends,
	and ends when the control returns to the original call;


write syntax for pointer to array and array of pointers?
		array of pointers ===> *ptr[2];
		pointer to array  ===> (*ptr)[3];


#include <stdio.h>
#include <stdlib.h>

int main()
{
        int *ptr = (int*)malloc(-1);  // Attempt to allocate with -1 size (undefined)

        if (ptr == NULL)
        {
                printf("Memory allocation failed!\n");
        }
        else
        {
                printf("Unexpected memory allocation (not recommended)\n");
                // This part is not recommended as the behavior is undefined
        }
        return 0;
}

Output:
	$ ./a.out 
	Unexpected memory allocation (not recommended)



what will happen when we allocate malloc(-1)?? how much memory will allocate?

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int *ptr = (int*)malloc(-1);  // Attempt to allocate with -1 size (undefined)

        if (ptr == NULL)
        {
                printf("Memory allocation failed!\n");
        }
        else
        {
                printf("Unexpected memory allocation (not recommended)\n");
                // This part is not recommended as the behavior is undefined
        }
        return 0;
}


Compilation:
	1.c: In function ‘main’:
	1.c:6:26: warning: argument 1 value ‘18446744073709551615’ exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]
	    6 |         int *ptr = (int*)malloc(-1);  // Attempt to allocate with -1 size (undefined)
	      |                          ^~~~~~~~~~
	In file included from 1.c:2:
	/usr/include/stdlib.h:540:14: note: in a call to allocation function ‘malloc’ declared here
	  540 | extern void *malloc (size_t __size) __THROW __attribute_malloc__
	      |              ^~~~~~
Output:
	:~$ ./a.out 
	Memory allocation failed!


/**********************************************************/

#include <stdio.h>

#define MACRO(X) X + 100

int main() 
{
    int iVariant = 7;
    printf("===> %d\n", 10 * MACRO(++iVariant));
    return 0;
}

/**********************************************************/

#include <stdio.h>

int main()
{
	int const *ptr;
	int *const ptr2;

	int color = 2;
	switch(color)
	{
		case 0: printf("zero\n");
		case 1: printf("one\n");
		case 2: printf("two\n");
		case 3: printf("three\n");
		default: printf("four\n");
	}

	void *ptr1;
	(char *)ptr1++;
}

/**********************************************************/

#include <stdio.h>
#pragma pack(1)
struct MyStruct
{
   unsigned int uiInteger;
   unsigned short int uisShort;
   unsigned char uisShort1;
   unsigned char *pucPointer;
}stMyStruct;
 
union MyUnion
{
   unsigned int uiInteger;
   unsigned short int uisShort;
   unsigned char * pucPointer;
}unMyUnion;

int main()
{
   printf("Structure size = %ld\n, Union size = %ld\n", sizeof(stMyStruct), sizeof(unMyUnion));
   return 0;
}

/**********************************************************/

#include <stdio.h>

typedef struct st {
	int data;
	struct st *next;
}Element;

Element *head = NULL, *top = NULL;
int listSize = 0;

void writeData(int data)
{
	if(head == NULL)
	{
		Element *node = malloc(sizeof(Element));
		node->data = data;
		node->next = NULL;
		head = node;
		top = head;
		listSize++;
	}
	else
	{
		if(listSize != 5)
		{
			Element *node = malloc(sizeof(Element));
			node->data = data;
			node->next = NULL;

			Element *temp = head;

			while(temp->next)
			{
				temp = temp->next; 
			}
			temp->next = node; 
			listSize++;
		}
		else
		{
			if(top->next)
			{
				top->data = data;
				top = top->next;
			}
			else
			{
				top = head;
			}
		}
	}
}

int readData(void)
{
	int data;
	if(listSize == 0)
	{
		return -1;
	}
	if(top->next == NULL)
	{
		data = top->data;
		listSize--;
		return data;
	}
	if(top && top->next)
	{
		data = top->data;
		top = top->next;
		if(top == NULL)
		{
			top = head;
		}
		listSize--;
		return data;
	}
}

int main()
{

	return 0;
}

/**********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

//#pragma GCC optimize("O1")

int volatile shared_data = 0;

void *Task1(void *params)
{
    printf("Thread - 1 \n");
    
    while (1)
    {
        if (shared_data != 0)
        {
            break;
        }
    }
    printf("Thread - 1 exited\n");
}

void *Task2(void *params)
{
    printf("Thread - 2 \n");
    sleep(5);
    shared_data = 5;
    printf("Thread - 2 exited\n");
 }

int main()
{
    pthread_t hadle1, hadle2;

    if (pthread_create(&hadle1, NULL, &Task1, NULL) != 0)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_create(&hadle2, NULL, &Task2, NULL) != 0)
    {
        printf("Thread Creation Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_join(hadle1, NULL) != 0)
    {
        printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if (pthread_join(hadle2, NULL) != 0)
    {
        printf("Thread Join Failed, File: %s Func: %s Line: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    return 0;
}

/**********************************************************************************************************************************/

#include <stdio.h>

typedef struct student
{
	int data;
	struct student *next;
}Node;

Node *head = NULL;

void addAtFirst(int data)
{
	int arr[100];
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Unablet to allocate memeory");
		return;
	}
	else
	{
		(uint64_t)newNode->data = (uint64_t)data;
		newNode->next = NULL;
		if(head == NULL)
			head = newNode;
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

// accesing and writing the memory beyond allocated space to the function
		question: what happens to the execution is it going to return?
		Ans:	  its not going to return from the function why because the stack got currupted by the instructins.


	arr[101] = 0;	
	arr[102] = 0;	
	arr[103] = 0;	
	arr[104] = 0;	
	arr[105] = 0;	
	.
	.
	arr[200] = 0;
}

	from the above programm asked below questions
		what is the behaviour of the below line?
			(uint64_t)newNode->data = (uint64_t)data;
		what is the behaviour of the below line?
			newNode->data = (uint64_t)data;



write strcyp function definition...

char *myStrcpy(char *dest, const char *src)
{
	char *temp = dest;
	while(*src != '\0')
	{
		*temp++ = *src++;
	}
	*temp = '\0';
	return dest;
}

/**************************************************************/

#include <stdio.h>

int secondMax(int *arr, int len)
{
	int max1 = arr[0];
	int max2 = arr[1];
	for(int i = 2; i < len; i++ )
	{
		   
		if(arr[i] > max1 && arr[iZZ] > max2 )
		{
			max2 = max1;
			max1 = arr[i];
		}
	}
	return max2;
}


int main()
{
	int arr[10] = {1, -10, 5, 333, 999, 11, 888, 555, 999, 100};
	int len = sizeof(arr)/sizeof(arr[1]);
	printf("Second max = %d\n", secondMax(arr, len));
	return 0;
}
/***********************************************************************************/


/********************************************************************************************/
#include <stdio.h>
#include <stdint.h>


uint32_t littleToBig(uint32_t data)
{
	data = ((data & 0xff000000) >> 24) | ((data & 0x000000ff) << 24) | ((data & 0x00ff0000) >> 8) | ((data & 0x0000ff00) << 8);
	return data;
}


int main()
{
	uint32_t data = 0x12345678;
	
	
	printf("data =  %X\n", data);
	printf("data =  %X\n", littleToBig(data));
	return 0;
}
/********************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//0x1000 ---> 0th bit 0 remain 1
//0x1001 ---> 1st bit 0  ''

void printBinary(uint8_t data)
{
	for(int i = 7;  i >= 0; i--)
	{
		printf("%d", (data >> i) & 1);
	}
	printf("\n");
}

/* Asked in AMD */
typedef struct {
	int data1;
	int data2;
	char data3;
}Memory;
/***********************************/

int main()
{
	/* Asked in AMD */
	Memory obj;
	memset(&obj, 0x55, sizeof(obj));
	printf("%x\n", obj.data1);
	printf("%x\n", obj.data2);
	printf("%x\n", obj.data3);
	printf("\n\n");
	/*************************/


	int memorySize = 16;
	uint8_t *ptr = malloc(16*sizeof(char));
	int j = 0;
	for(int i = 0; i < 16; i++ )
	{
		*ptr = (0xFF & ~(1 << j));
		j++;
		if( j == 8)
			j = 0;
		printBinary(*ptr);
		ptr++;
	}
	return 0;
}

/********************************************************************************************/

#include <stdio.h>

void printArray(int *arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int *arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = i + 1; j < len - 1; j++)
		{ 
			if(arr[i] > arr[j + 1])
			{
				int temp = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{

	int arr[10] = {3, 1, -1, 2, 5, 99, 11, 88, 0, 55};
	printArray(arr, 10);
	bubbleSort(arr, 10);
	printArray(arr, 10);
	return 0;
}


/****************************************************************/ 

#include <stdio.h>

int main()
{
	//int *(*Ptr)(int, void ((fp1*)(int, int)));
	
	char arr[3][3];
	char arr1[3][3];
	int count = 5;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			arr[i][j] = count++; 
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d, ", arr[i][j]); 
		}
		printf("\n");
	}

	char (*ptr1)[3] = arr;
	char *ptr2 = (char *) &arr[0];
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	//char (*ptr3)[3] = arr[1];
	
	ptr2 = (char *)arr[1];
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

	//printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	//printf("ptr1 = %d, ptr2 = %d\n", *ptr1, *ptr2);
//	ptr1 = (char *)arr + 1;
//     	ptr2++;
//	printf("ptr1++ = %d, ptr2++ = %d\n", *ptr1, *ptr2);
	
	return 0;
}


/****************************************************************/

allocate memory for double pointer...

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **arr;
	*arr = (int*)malloc(5*sizeof(int));

	for(int i = 0; i < 5; i++)
		*arr[i] = (int **) malloc(5*sizeof(int));
	

	return 0;
}

/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strstr(const char *str1, const char * str2)
{
	for(int i = 0; str1[i] != '\0'; i++)
	{
		int j = 0;
		if(str1[i] == str2[j])
		{
			for(j = 1; str2[j] != '\0'; j++)
			{
				if(str2[j] == str1[j + i])
				{
					continue;
				}
				else
					break;
			}
			if(str2[j] == '\0')
				return (char *)(str1 + i);
		}
	}
	return NULL;
}

void strrev(char *str)
{
	int length = strlen(str);
	
	for(int i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}
}

int main()
{

	char str1[] = "I AM SHAIK IMRAN";
	char str2[] = "adssd";

	char *ptr = my_strstr(str1, str2);
	if(ptr != NULL)
		printf("%s\n", ptr);
	else
		printf("string not found\n");
	

	printf("%s\n", str1);
	
	strrev(str1);

	printf("%s\n", str1);
}
/********************************************************************************/

#include <stdio.h>

void fun(char *p)
{
	printf("---------------->%c\n", p[0]);
	p++;
	printf("---------------->%c\n", p[0]);
	p[2] = 'K';
	printf("---------------->%s\n", p);
}

#define foo(a, b)\
	a = a - b;\
	b++;\
	a = a * b;\


int main()
{
	char str[] = "LTTSHYD";
	fun(str);
	printf("%c\n", *(str+2));
	printf("%s\n", str);
	return 0;
}
/*****************************************************************************/

#include<stdio.h>
char *getString()
{
	char str[] = "Will I be printed?";
	return str;
}
int main()
{
	printf("%s", getString());
	getchar();
}

/*****************************************************************************/

#include <stdio.h>

int main() 
{ 
	char *ptr = "HELLO"; 
	ptr[2] = 'M'; 
	printf("%s", ptr);
	return 0; 
}

/********************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool is_powerof_two(int data)
{
	return (!(data & (data -1))?true:false);
}
 //0000 1000
 //0000 0111
 //0000 0000
 //1
int main()
{

	printf("%d\n", is_powerof_two(8));

	return 0;

}

/*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *sp;

Node *get_node(int data)
{
	Node *node = malloc(sizeof(Node));
	if(node == NULL)
	{
		printf("Unable to allocate memory");
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	return node;

}

void print_stack(void)
{
	Node *temp = sp;
	if(temp == NULL)
	{
		printf("stack is empty\n");
	}
	while(temp != NULL)
	{
		printf("%d \n", temp->data);
		temp = temp->next;
	}

}


void push(int data)
{
	Node *temp = get_node(data);

	if(sp == NULL)
	{
		sp = temp;
	}
	else
	{
		temp->next = sp;
		sp = temp;
	}
}


int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	
	print_stack();
	return 0;

}
/*****************************************************************************************/

write your own sizeof operator...
	#define my_sizeof(X) ({ __typeof__(X) Y; ((char *)(&Y + 1) - (char *)&Y);})
/*****************************************************************************************/

/*****************************************************************************************/

	/*How to know the STACK is growing up/down?*/
	int arr[] = {1, 3, 5, 6, 7, 8};

	  printf("arr[0] = %p\narr[1] = %p \n", &arr[0], &arr[1]);
	  if( (&arr[1] - arr[0]) < 0)
		  printf("Down Growing Stack\n");
	  else
		  printf("Up Growing Stack\n");

/*****************************************************************************************/

	some oprayions on pointers

	int data = 5;
	int arr[5] = {1, 5, 6, 7, 8};

	int *p[5] = {&data, arr};	
	int *p1 = p[0];
	int *p2 = p[1];
	printf("%d\n", *p1);
	printf("%d\n", p2[0]);
	printf("%d\n", p2[1]);
	printf("%d\n", p2[2]);
	printf("%d\n", p2[3]);

	int (*ptr)[5] = &arr;
	printf("%d\n", **(ptr));

	int a[2][5] = { {1, 2, 3, 4, 5}, {11, 22, 33, 44, 55}};	
	int *p3 = (int *)a;
	printf("%d\n", *p3);
	printf("%d\n", *(p3 + 1));
	
	int (*p4)[5] = a;
	
	printf("%d\n", **p4);
	printf("%d\n", **(p4 + 1));
/*****************************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool isMultiplesOf2(int data)
{
	return(!(data & (data - 1)));
}

void countALlChars(char * data)
{
	int count[26] = {0};

	for(int i = 0; data[i]; i++)
	{
		count[data[i] - 97]++;  
	}
}

int main()
{
	int data = 8;
	bool status = false;
	status = isMultiplesOf2(data);

	if(statu == true)
		printf();
	else
		return false;
	return 0;
}
