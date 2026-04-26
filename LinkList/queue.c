/**
 * @file queue.c
 * @brief Implements a queue using a singly linked list.
 *
 * This file demonstrates basic queue operations such as enqueue, dequeue,
 * peek, printing, and deleting the queue.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Represents one node in the queue.
 */
typedef struct queue
{
	/** Value stored in the queue node. */
	int data;
	/** Pointer to the next node in the queue. */
	struct queue *next;
} queue_t;

queue_t *head = NULL;
queue_t *tail = NULL;

/**
 * @brief Checks whether the queue is empty.
 *
 * @return true if the queue has no nodes, false otherwise.
 */
bool is_empty(void)
{
	return head == NULL;
}

/**
 * @brief Prints all elements in the queue from front to rear.
 *
 * @return true if the queue was printed, false if the queue is empty.
 */
bool print_queue(void)
{
	if (is_empty())
	{
		printf("List is empty\n");
		return false;
	}

	queue_t *temp = head;

	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");

	return true;
}

/**
 * @brief Adds a new value to the rear of the queue.
 *
 * @param data Value to store in the new queue node.
 * @return true if the value was enqueued successfully, false if memory
 *         allocation failed.
 */
bool enqueue(int data)
{
	queue_t *new_node = malloc(sizeof(queue_t));

	if (new_node == NULL)
	{
		printf("Unable to allocate memory\n");
		return false;
	}

	new_node->data = data;
	new_node->next = NULL;

	if (is_empty())
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}

	return true;
}

/**
 * @brief Removes the front value from the queue.
 *
 * @param data Pointer where the dequeued value will be stored.
 * @return true if a value was dequeued successfully, false if the queue is
 *         empty or data is NULL.
 */
bool dequeue(int *data)
{
	if (data == NULL || is_empty())
		return false;

	queue_t *temp = head;
	*data = temp->data;
	head = head->next;
	free(temp);

	if (head == NULL)
		tail = NULL;

	return true;
}

/**
 * @brief Frees all nodes in the queue.
 *
 * @return true if the queue was deleted, false if the queue is already empty.
 */
bool delete_queue(void)
{
	if (is_empty())
		return false;

	queue_t *temp = NULL;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	tail = NULL;

	return true;
}

/**
 * @brief Reads the front value from the queue without removing it.
 *
 * @param data Pointer where the front value will be stored.
 * @return true if a value was read successfully, false if the queue is empty
 *         or data is NULL.
 */
bool peek(int *data)
{
	if (data == NULL || is_empty())
		return false;

	*data = head->data;

	return true;
}

/**
 * @brief Counts the number of nodes currently in the queue.
 *
 * @return Number of elements in the queue.
 */
int size(void)
{
	int count = 0;
	queue_t *temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

/**
 * @brief Demonstrates basic queue operations.
 *
 * @return 0 when the program finishes successfully.
 */
int main(void)
{
	int data = 0;

	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	print_queue();

	for (size_t i = 0; i < 2; i++)
	{
		dequeue(&data);
		printf("--------------------------->>>Data: %d\n", data);
		print_queue();
	}

	delete_queue();
	return 0;
}
