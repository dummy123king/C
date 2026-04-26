<<<<<<< HEAD
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a single linked list node
typedef struct single_link_list
{
	int data;
	struct single_link_list *next;
} Node;

// Declare a global pointer for the head of the linked list
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
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *root = NULL;

node_t *get_node(int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Unable to allocate memory\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;    
}

void print_list(void)
{
    node_t *temp = root;

    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void add_at_beginning(int data)
{
    node_t *new_node = get_node(data);

    if (new_node == NULL) {
        return;
    }

    if (root == NULL) {
        root = new_node;
        return;
    }

    new_node->next = root;
    root = new_node;
}

void delete_at_beginning(void)
{
    if (root == NULL) {
        printf("Nothing to delete\n");
        return;
    }

    if (root->next == NULL) {
        free(root);
        root = NULL;
        return;
    }

    node_t *to_delete = root;
    root = root->next;
    free(to_delete);    
}

void add_at_end(int data)
{
    node_t *new_node = get_node(data);
    if (new_node == NULL) {
        return;
    }

    if (root == NULL) {
        root = new_node;
        return;
    }

    node_t *temp = root;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void delete_at_end(void)
{
    if (root == NULL) {
        printf("Nothing to delete\n");
        return;
    }

    if (root->next == NULL) {
        free(root);
        root = NULL;
        return;
    }

    node_t *to_delete = root, *prev = NULL;
    while (to_delete != NULL && to_delete->next != NULL) {
        prev = to_delete;
        to_delete = to_delete->next;
    }

    free(to_delete);
    prev->next = NULL;    
}

void add_before_middle(int data)
{
    node_t *new_node = get_node(data);
    if (new_node == NULL) {
        return;
    }

    if (root == NULL) {
        root = new_node;
        return;
    }

    if (root->next == NULL) {
        new_node->next = root;
        root = new_node;
        return;
    }

    node_t *prev = NULL, *mid = root, *fast = root;
    while (fast != NULL && fast->next != NULL) {
        prev = mid;
        mid = mid->next;
        fast = fast->next->next;
    }

    new_node->next = mid;
    prev->next = new_node;
}

void delete_before_middle(void)
{
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    if (root->next == NULL) {
        free(root);
        root = NULL;
        return;
    }

    if (root->next->next == NULL) {
        node_t *to_delete = root;
        root = root->next;
        free(to_delete);
        return;
    }

    node_t *prev_to_prev = NULL, *to_delete = NULL, *mid = root, *fast = root;
    while (fast != NULL && fast->next != NULL) {
        prev_to_prev = to_delete;
        to_delete = mid;
        mid = mid->next;
        fast = fast->next->next;
    }

    if (prev_to_prev == NULL) {
        root = to_delete->next;
        free(to_delete);
    }
    else {
        prev_to_prev->next = mid;
        free(to_delete);
    }
}

void add_after_middle(int data)
{
    node_t *new_node = get_node(data);

    if (new_node == NULL) {
        return;
    }

    if (root == NULL) {
        root = new_node;
        return;
    }

    if (root->next == NULL) {
        root->next = new_node;
        return;
    }

    node_t *mid = root, *fast = root;
    while (fast && fast->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    new_node->next = mid->next;
    mid->next = new_node;
}

void delete_after_middle(void)
{
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    if (root->next == NULL) {
        return;
    }

    if (root->next->next == NULL) {
        node_t *to_delete = root->next;
        root->next = NULL;
        free(to_delete);
        return;
    }

    node_t *mid = root, *fast = root, *to_delete = NULL;
    while (fast != NULL && fast->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

    to_delete = mid->next;
    mid->next = mid->next->next;
    free(to_delete);    
}

void delete_whole_list(void)
{
    if (root == NULL) {
        printf("Nothing to delete list is empty\n");
        return;
    }

    while (root != NULL)
    {
        node_t *to_delete = root;
        root = root->next;
        free(to_delete);
    }
}

void reverse_list(void)
{
    if (root == NULL) {
        printf("Nothing to reverse list is empty\n");
        return;
    }

    if (root->next == NULL) {
        printf("Nothing to reverse, Only one node exist in the list.\n");
        return;
    }
    
    node_t *prev = NULL, *curr = root, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    root = prev;
}

void reverse_list_recursively(node_t *node)
{
    if (node->next == NULL) {
        root = node;
        return;
    }

    reverse_list_recursively(node->next);
    node->next->next = node;
    node->next = NULL;
}

bool find_loop(void)
{
    add_at_beginning(4);
    add_at_beginning(5);
    add_at_beginning(7);
    add_at_beginning(8);
    add_at_beginning(9);
    add_at_beginning(55);
    add_at_beginning(88);
    add_at_beginning(35);
    add_at_beginning(66);
    print_list();

    // Uncomment to introduce loop in the list
    // root->next->next->next = root->next->next;
    
    node_t *slow = root, *fast = root;

    // Using Floyd's cycle detection algorithm to find a loop in the list
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            printf("List has a loop\n");
            return true;
        }
    }
    
    printf("No loop in the list\n");
    return false;
}


// Main function
int main()
{
    find_loop();
    // print_list();
    return 0;
}


>>>>>>> c2ff6e504b436f49b8785176bb5f827d8641b398
