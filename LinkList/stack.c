#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a stack node
typedef struct stack
{
    int data;
    struct stack *next;
} Stack;

// Declare a global pointer for the top of the stack
Stack *root = NULL;

// Function to check if the stack is empty
bool isEmpty(void)
{
    if (root == NULL)
    {
        return true;
    }
    return false;
}

// Function to print the elements of the stack
void printStack(void)
{
    Stack *temp = root;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to push an element onto the stack
bool push(int data)
{
    // Allocate memory for a new stack node
    Stack *Node = malloc(sizeof(Stack));
    if (Node == NULL) // Check if memory allocation was successful
    {
        printf("No memory left to allocate\n");
        return false;
    }
    Node->data = data; // Assign data to the new node
    Node->next = NULL;

    if (isEmpty() == true) // If the stack is empty, make the new node the root
    {
        root = Node;
    }
    else // If the stack is not empty, add the new node at the top of the stack
    {
        Node->next = root;
        root = Node;
    }
    return true;
}

// Function to pop an element from the stack
bool pop(int *data)
{
    Stack *temp = root;
    if (!isEmpty()) // Check if the stack is not empty
    {
        *data = temp->data; // Get the data from the top node
        root = root->next; // Update the root to point to the next node
        free(temp); // Free memory allocated for the top node
        return data;
    }
    else // If the stack is empty, return false
    {
        return false;
    }
}

// Function to peek at the top element of the stack
bool peek(int *data)
{
    if (root == NULL) // If the stack is empty, print a message and return false
    {
        printf("Stack is empty\n");
        return false;
    }
    else // If the stack is not empty, get the data from the top node
    {
        *data = root->data;
    }
    return true;
}

// Main function
int main()
{
    int data = 0;

    if (isEmpty() == true)
        printf("Stack is empty...\n");
    else
        printf("Stack is not empty...\n");

    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    printStack();
    
    pop(&data);
    printf("Popped element: %d\n", data);
    printStack();
    
    peek(&data);
    printf("Peeked element: %d\n", data);
    
    if (isEmpty() == true)
        printf("Stack is empty...\n");
    else
        printf("Stack is not empty...\n");

    return 0;
}
