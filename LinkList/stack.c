/**
 * @file stack.c
 * @brief Implements a stack using a singly linked list.
 *
 * This file demonstrates basic stack operations such as push, pop, peek,
 * printing, and clearing the stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Represents one node in the stack.
 */
typedef struct stack {
	/** Value stored in the stack node. */
	int data;
	/** Pointer to the next node below this node. */
	struct stack *next;
} stack_t;

stack_t *root = NULL;

/**
 * @brief Checks whether the stack is empty.
 *
 * @return true if the stack has no nodes, false otherwise.
 */
bool is_empty(void)
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

/**
 * @brief Prints all elements in the stack from top to bottom.
 */
void print_stack(void)
{
	stack_t *temp = root;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

/**
 * @brief Pushes a new value onto the top of the stack.
 *
 * @param data Value to store in the new stack node.
 * @return true if the value was pushed successfully, false if memory allocation
 *         failed.
 */
bool push(int data)
{
	stack_t *node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("No memory left to allocate\n");
		return false;
	}

	node->data = data;
	node->next = root;
	root = node;

	return true;
}

/**
 * @brief Removes the top value from the stack.
 *
 * @param data Pointer where the popped value will be stored.
 * @return true if a value was popped successfully, false if the stack is empty
 *         or data is NULL.
 */
bool pop(int *data)
{
	if (data == NULL || is_empty())
		return false;

	stack_t *temp = root;
	*data = temp->data;
	root = root->next;
	free(temp);
    
	return true;
}

/**
 * @brief Reads the top value from the stack without removing it.
 *
 * @param data Pointer where the top value will be stored.
 * @return true if a value was read successfully, false if the stack is empty
 *         or data is NULL.
 */
bool peek(int *data)
{
	if (data == NULL || is_empty())
		return false;

	*data = root->data;

	return true;
}

/**
 * @brief Frees all nodes in the stack and resets it to empty.
 */
void clear_stack(void)
{
	stack_t *temp = root;

	while (temp != NULL)
	{
		stack_t *next = temp->next;
		free(temp);
		temp = next;
	}

	root = NULL;
}


/**
 * @brief Demonstrates basic stack operations.
 *
 * @return 0 when the program finishes successfully.
 */
int main(void)
{
	int data = 0;

	if (is_empty() == true)
		printf("Stack is empty...\n");
	else
		printf("Stack is not empty...\n");

	push(5);
	push(4);
	push(3);
	push(2);
	push(1);
	print_stack();

	if (pop(&data))
	{
		printf("Popped element: %d\n", data);
	}

	print_stack();

	if (peek(&data))
	{
		printf("Peeked element: %d\n", data);
	}

	if (is_empty() == true)
		printf("Stack is empty...\n");
	else
		printf("Stack is not empty...\n");

	clear_stack();

	return 0;
}
