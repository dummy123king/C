#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
typedef struct DoublyLinkedListNode
{
    struct DoublyLinkedListNode *prev; // Pointer to the previous node
    int data; // Data stored in the node
    struct DoublyLinkedListNode *next; // Pointer to the next node
} Node;

// Declare global pointers for the head and tail of the linked list
Node *head = NULL;
Node *tail = NULL;

// Function to print the doubly linked list from head to tail
void printList(void)
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d<->", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

// Function to print the doubly linked list from tail to head (in reverse)
void printListReverse()
{
    Node *temp = tail;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d <->", temp->data); // Print the data of the current node
        temp = temp->prev; // Move to the previous node
    }
}

// Function to add a new node with data at the beginning of the linked list
void addAtFirst(int data)
{
    Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node

    if (newNode == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        // If the list is empty, make the new node the head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // If the list is not empty, insert the new node at the beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to add a new node with data at the end of the linked list
void addAtLast(int data)
{
    Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        // If the list is empty, make the new node the head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // If the list is not empty, insert the new node at the end
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to add a new node with data in the middle of the linked list
void addAtMiddle(int data)
{
    Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        // If the list is empty, make the new node the head and tail
        head = tail = newNode;
        return;
    }

    if (head->next == NULL)
    {
        // If there's only one node in the list, insert the new node after it
        newNode->prev = head;
        head->next = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // If there are multiple nodes in the list, insert the new node in the middle
        Node *mid = head, *fast = head->next;

        // Find the middle node using slow and fast pointers
        while (fast && fast->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }
        // Insert the new node after the middle node
        newNode->prev = mid;
        newNode->next = mid->next;

        if (mid->next != NULL) {
            mid->next->prev = newNode;
        }
       
        mid->next = newNode;
       
        if (newNode->next == NULL )
        {
            tail = newNode;
        }
    }
}

// Function to delete the first node from the linked list
void deleteAtFirst(void)
{
    Node* temp = head; 

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (temp->next == NULL)
    {
        // If there's only one node in the list, delete it and update head and tail
        free(temp);
        head = NULL;
        tail = NULL;
        return;
    }
    
    // If there are multiple nodes in the list, delete the first node and update head
    head = head->next;
    head->prev = NULL;
    free(temp);
}

// Function to delete the last node from the linked list
void deleteAtLast(void)
{
    Node *temp = tail;
    if (temp == NULL && head == NULL)
    {
        printf("List is empty");
        return;   
    }
    if (temp->prev == NULL)
    {
        // If there's only one node in the list, delete it and update head and tail
        free(temp);
        tail = NULL;
        head = NULL;
        return;
    }
    // If there are multiple nodes in the list, delete the last node and update tail
    tail->prev->next = NULL;
    tail = tail->prev;
    free(temp);    
}

// Function to delete the middle node from the linked list
void deleteAtMiddle(void)
{
    Node *slow = head, *fast = head;
    
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    

    if (head->next == NULL)
    {
        // If there's only one node in the list, delete it and update head and tail
        free(head);
        head = tail = NULL;
        return;
    }
    

    // Use slow and fast pointers to find the middle node
    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node and update pointers
    slow->prev->next = slow->next;

    if(slow->next != NULL)
    {
        slow->next->prev = slow->prev;
    }


    if (slow->next == NULL)
    {
        tail = slow->prev;
    }
    
    free(slow);
}

// Function to reverse the linked list
void reverseList(void)
{
    Node *temp = NULL, *curr = head;

    while (curr != NULL)
    {
        // Swap prev and next pointers of the current node
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; 
    }

    if (temp != NULL)
    {
        // If temp is not NULL, it means the list was not empty, so update head and tail
        head = temp->prev;
        tail = temp;
    }    
}

// Main function
int main()
{
    // Add some nodes to the linked list
    addAtLast(5);
    addAtLast(1);
    addAtLast(6);
    addAtLast(55);
    addAtLast(77);
    addAtLast(88);
    addAtLast(99);

    // Print the original list
    printf("Original list:\n");
    printList();

    // Reverse the list and print it
    printf("\nList after reversing:\n");
    reverseList();
    printList();

    return 0;
}
