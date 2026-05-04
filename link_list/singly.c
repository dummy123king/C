/**
 * @file singly.c
 * @brief Demonstrates operations on a singly linked list.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Defines a single linked list node.
 *
 * @param data The integer value stored in the node.
 * @param next A pointer to the next node in the linked list.
 */
typedef struct single_link_list
{
	int data;
	struct single_link_list *next;
} node_t;

/**
 * Global pointer to the first node of the linked list.
 */
node_t *head = NULL;

/**
 * Creates a new linked list node with the given data.
 *
 * @param data The integer value to be stored in the new node.
 *
 * @return A pointer to the newly created node, or NULL if memory allocation fails.
 */
static node_t *create_node(int data)
{
	node_t *new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for a new node\n");
		return NULL;
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/**
 * Prints all nodes in the linked list.
 *
 * @return None. Prints the linked list elements or a message if the list is empty.
 */
void print_list(void)
{
	node_t *temp = head;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

/**
 * Adds a new node with the given data at the beginning of the linked list.
 *
 * @param data The integer value to be stored in the new node.
 *
 * @return None. Updates the head pointer to point to the new node.
 */
void add_at_first(int data)
{
	node_t *new_node = create_node(data);

	if (new_node == NULL)
	{
		return;
	}
	new_node->next = head;
	head = new_node;
}

/**
 * Adds a new node with the given data at the end of the linked list.
 *
 * @param data The integer value to be stored in the new node.
 *
 * @return None. Appends the new node to the linked list.
 */
void add_at_last(int data)
{
	node_t *new_node = create_node(data);

	if (new_node == NULL)
	{
		return;
	}

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	node_t *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

/**
 * Deletes the first node from the linked list.
 *
 * @return None. Removes the first node or prints a message if the list is empty.
 */
void delete_at_first(void)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	node_t *temp = head;
	head = head->next;
	free(temp);
}

/**
 * Deletes the last node from the linked list.
 *
 * @return None. Removes the last node or prints a message if the list is empty.
 */
void delete_at_last(void)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	node_t *temp = head;
	node_t *prev = NULL;

	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	if (prev == NULL)
	{
		head = NULL;
	}
	else
	{
		prev->next = NULL;
	}

	free(temp);
}

/**
 * Adds a new node with the given data in the middle of the linked list.
 *
 * @param data The integer value to be stored in the new node.
 *
 * @return None. Inserts the new node in the middle of the linked list.
 */
void add_at_middle(int data)
{
	node_t *new_node = create_node(data);

	if (new_node == NULL)
	{
		return;
	}

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	node_t *mid_ptr = head;
	node_t *fast_ptr = head->next;

	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
		mid_ptr = mid_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	new_node->next = mid_ptr->next;
	mid_ptr->next = new_node;
}

/**
 * Deletes the middle node from the linked list.
 *
 * @return None. Removes the middle node or prints a message if the list is empty.
 */
void delete_at_middle_1(void)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}

	node_t *slow = head;
	node_t *fast = head;
	node_t *prev = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	prev->next = slow->next;
	free(slow);
}

/**
 * Reverses the linked list iteratively.
 *
 * @return None. Updates the head pointer to the first node of the reversed list.
 */
void reverse_list(void)
{
	node_t *prev_node = NULL;
	node_t *curr_node = head;
	node_t *next_node = NULL;

	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		curr_node->next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}
	head = prev_node;
}

/**
 * Reverses the linked list recursively.
 *
 * @param ptr A pointer to the current node in the linked list.
 *
 * @return None. Updates the head pointer to the first node of the reversed list.
 */
void reverse_list_recursively(node_t *ptr)
{
	if (ptr == NULL)
	{
		head = NULL;
		return;
	}

	if (ptr->next == NULL)
	{
		head = ptr;
		return;
	}

	reverse_list_recursively(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
}

/**
 * Checks whether the linked list contains a loop.
 *
 * @return true if the linked list contains a loop, otherwise false.
 */
bool find_loop_in_list(void)
{
	node_t *slow = head;
	node_t *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			printf("List has a loop\n");
			return true;
		}
	}

	printf("No loop in the list\n");
	return false;
}

/**
 * Deletes all nodes from the linked list and frees their memory.
 *
 * @return None. Frees all nodes and sets the head pointer to NULL.
 */
void free_list(void)
{
	node_t *temp = head;

	while (temp != NULL)
	{
		node_t *next = temp->next;
		free(temp);
		temp = next;
	}
	head = NULL;
}

/**
 * Demonstrates linked list operations.
 *
 * @return 0 after completing all linked list operations.
 */
int main(void)
{
	add_at_first(1);
	add_at_first(5);
	add_at_first(4);
	add_at_first(5);
	add_at_first(2);
	add_at_first(33);
	print_list();

	add_at_last(99);
	add_at_middle(77);
	print_list();

	delete_at_first();
	delete_at_last();
	delete_at_middle_1();
	print_list();

	reverse_list();
	print_list();

	reverse_list_recursively(head);
	print_list();

	(void)find_loop_in_list();
	free_list();

	return 0;
}

/*
Expected Output:
33->2->5->4->5->1->NULL
33->2->5->4->77->5->1->99->NULL
2->5->4->5->1->NULL
1->5->4->5->2->NULL
2->5->4->5->1->NULL
No loop in the list
*/
