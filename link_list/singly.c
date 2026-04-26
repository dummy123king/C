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
} Node;

/**
 * Global pointer to the first node of the linked list.
 */
Node *head = NULL;

/**
 * Creates a new linked list node with the given data.
 *
 * @param data The integer value to be stored in the new node.
 *
 * @return A pointer to the newly created node, or NULL if memory allocation fails.
 */
static Node *create_node(int data)
{
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for a new node\n");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/**
 * Prints all nodes in the linked list.
 *
 * @param None.
 *
 * @return None. Prints the linked list elements or a message if the list is empty.
 */
void print_list(void)
{
	Node *temp = head;

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
	Node *newNode = create_node(data);

	if (newNode == NULL)
	{
		return;
	}
	newNode->next = head;
	head = newNode;
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
	Node *newNode = create_node(data);

	if (newNode == NULL)
	{
		return;
	}

	if (head == NULL)
	{
		head = newNode;
		return;
	}

	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

/**
 * Deletes the first node from the linked list.
 *
 * @param None.
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

	Node *temp = head;
	head = head->next;
	free(temp);
}

/**
 * Deletes the last node from the linked list.
 *
 * @param None.
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

	Node *temp = head;
	Node *prev = NULL;

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
	Node *newNode = create_node(data);

	if (newNode == NULL)
	{
		return;
	}

	if (head == NULL)
	{
		head = newNode;
		return;
	}

	Node *midPtr = head;
	Node *fastPtr = head->next;

	while (fastPtr != NULL && fastPtr->next != NULL)
	{
		midPtr = midPtr->next;
		fastPtr = fastPtr->next->next;
	}

	newNode->next = midPtr->next;
	midPtr->next = newNode;
}

/**
 * Deletes the middle node from the linked list.
 *
 * @param None.
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

	Node *slow = head;
	Node *fast = head;
	Node *prev = NULL;

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
 * @param None.
 *
 * @return None. Updates the head pointer to the first node of the reversed list.
 */
void reverse_list(void)
{
	Node *prevNode = NULL;
	Node *currNode = head;
	Node *nextNode = NULL;

	while (currNode != NULL)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	head = prevNode;
}

/**
 * Reverses the linked list recursively.
 *
 * @param ptr A pointer to the current node in the linked list.
 *
 * @return None. Updates the head pointer to the first node of the reversed list.
 */
void reverse_list_recursively(Node *ptr)
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
 * @param None.
 *
 * @return true if the linked list contains a loop, otherwise false.
 */
bool find_loop_in_list(void)
{
	Node *slow = head;
	Node *fast = head;

	// Using Floyd's cycle detection algorithm to find a loop in the list
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
 * @param None.
 *
 * @return None. Frees all nodes and sets the head pointer to NULL.
 */
void freeList(void)
{
	Node *temp = head;

	while (temp != NULL)
	{
		Node *next = temp->next;
		free(temp);
		temp = next;
	}
	head = NULL;
}

/**
 * Demonstrates linked list operations.
 *
 * @param None.
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
	freeList();

	return 0;
}
