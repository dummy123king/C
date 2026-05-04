/**
 * @file doubly.c
 * @brief Implements a doubly linked list.
 *
 * This file demonstrates basic doubly linked list operations such as inserting
 * nodes, deleting nodes, printing in both directions, and reversing the list.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Represents a node in the doubly linked list.
 */
typedef struct doubly
{
	/** Pointer to the previous node. */
	struct doubly *prev;

	/** Value stored in the node. */
	int data;

	/** Pointer to the next node. */
	struct doubly *next;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;

/**
 * @brief Prints all nodes in the list from head to tail.
 */
void print_list(void)
{
	node_t *temp = head;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}

	printf("NULL<->");
	while (temp != NULL)
	{
		printf("%d<->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

/**
 * @brief Prints all nodes in the list from tail to head.
 */
void print_list_reverse(void)
{
	node_t *temp = tail;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("NULL<->");
	while (temp != NULL)
	{
		printf("%d <->", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

/**
 * @brief Inserts a new node at the beginning of the list.
 *
 * @param data Value to store in the new node.
 */
void add_at_first(int data)
{
	node_t *new_node = malloc(sizeof(node_t));

	if (new_node == NULL)
	{
		printf("Unable to allocate memory\n");
		return;
	}

	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL && tail == NULL)
	{
		head = new_node;
		tail = new_node;
		return;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

/**
 * @brief Inserts a new node at the end of the list.
 *
 * @param data Value to store in the new node.
 */
void add_at_end(int data)
{
	node_t *new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		printf("Unable to allocate memory\n");
		return;
	}

	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL && tail == NULL)
	{
		head = new_node;
		tail = new_node;
		return;
	}
	else
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}
}

/**
 * @brief Inserts a new node near the middle of the list.
 *
 * For lists with multiple nodes, the new node is inserted after the middle node
 * found using slow and fast pointers.
 *
 * @param data Value to store in the new node.
 */
void add_at_middle(int data)
{
	node_t *new_node = malloc(sizeof(node_t));

	if (new_node == NULL)
	{
		printf("Unable to allocate memory");
		return;
	}

	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL && tail == NULL)
	{
		head = tail = new_node;
		return;
	}

	if (head->next == NULL)
	{
		new_node->prev = head;
		head->next = new_node;
		tail = new_node;
		return;
	}
	else
	{
		node_t *mid = head, *fast = head->next;

		while (fast && fast->next)
		{
			mid = mid->next;
			fast = fast->next->next;
		}

		new_node->prev = mid;
		new_node->next = mid->next;

		if (mid->next != NULL)
		{
			mid->next->prev = new_node;
		}

		mid->next = new_node;

		if (new_node->next == NULL)
		{
			tail = new_node;
		}
	}
}

/**
 * @brief Deletes the first node from the list.
 */
void delete_at_first(void)
{
	node_t *temp = head;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if (temp->next == NULL)
	{
		free(temp);
		head = NULL;
		tail = NULL;
		return;
	}

	head = head->next;
	head->prev = NULL;
	free(temp);
}

/**
 * @brief Deletes the last node from the list.
 */
void delete_at_end(void)
{
	node_t *temp = tail;
	if (temp == NULL && head == NULL)
	{
		printf("List is empty");
		return;
	}
	if (temp->prev == NULL)
	{
		free(temp);
		tail = NULL;
		head = NULL;
		return;
	}
	tail->prev->next = NULL;
	tail = tail->prev;
	free(temp);
}

/**
 * @brief Deletes the middle node from the list.
 *
 * For lists with an even number of nodes, the second middle node is deleted.
 */
void delete_at_middle(void)
{
	node_t *slow = head, *fast = head;

	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	if (head->next == NULL)
	{
		free(head);
		head = tail = NULL;
		return;
	}

	while (fast && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->prev->next = slow->next;

	if (slow->next != NULL)
	{
		slow->next->prev = slow->prev;
	}

	if (slow->next == NULL)
	{
		tail = slow->prev;
	}

	free(slow);
}

/**
 * @brief Reverses the list by swapping each node's previous and next pointers.
 */
void reverse_list(void)
{
	node_t *temp = NULL, *curr = head;

	while (curr != NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	if (temp != NULL)
	{
		head = temp->prev;
		tail = temp;
	}
}

/**
 * @brief Demonstrates basic doubly linked list operations.
 *
 * @return 0 when the program finishes successfully.
 */
int main(void)
{
	add_at_end(5);
	add_at_end(1);
	add_at_end(6);
	add_at_end(55);
	add_at_end(77);
	add_at_end(88);
	add_at_end(99);

	printf("Original list:\n");
	print_list();

	printf("\nList after reversing:\n");
	reverse_list();
	print_list();

	return 0;
}

/*
Expected Output:
Original list:
NULL<->5<->1<->6<->55<->77<->88<->99<->NULL

List after reversing:
NULL<->99<->88<->77<->55<->6<->1<->5<->NULL
*/
