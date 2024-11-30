#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a queue node
typedef struct queue
{
    int data;           // Data stored in the node
    struct queue *next; // Pointer to the next node
} Queue;

// Declare global pointers for the head and tail of the queue
Queue *head = NULL;
Queue *tail = NULL;

// Function to check if the queue is empty
bool isEmpty(void)
{
    if (head == NULL) // If head is NULL, the queue is empty
    {
        return true;
    }
    return false;
}

// Function to print the elements of the queue
bool printQueue(void)
{
    if (isEmpty() == true) // If the queue is empty, print a message and return false
    {
        printf("List is empty\n");
        return false;
    }
    Queue *temp = head;

    while (temp != NULL) // Traverse the queue and print each element
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return true;
}

// Function to add an element to the end of the queue (enqueue)
bool enqueue(int data)
{
    Queue *newNode = malloc(sizeof(Queue)); // Allocate memory for the new node
    if (newNode == NULL)                    // Check if memory allocation was successful
    {
        printf("List is full/Unable to allocate memory\n");
        return false;
    }
    newNode->data = data; // Assign data to the new node
    newNode->next = NULL;

    if (head == NULL) // If the queue is empty, make the new node both head and tail
    {
        head = newNode;
        tail = newNode;
    }
    else // If the queue is not empty, add the new node to the end and update tail
    {
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

// Function to remove an element from the front of the queue (dequeue)
bool dequeue(int *data)
{
    if (isEmpty() == true) // If the queue is empty, return false
    {
        return false;
    }
    else // If the queue is not empty, remove the first element and update head
    {
        Queue *temp = head;
        *data = temp->data; // Store the data of the first element
        head = head->next;  // Move head to the next node
        free(temp);         // Free memory allocated for the first node
    }
    return true;
}

// Function to delete the entire queue and free memory
bool deleteQueue(void)
{
    if (isEmpty() == true) // If the queue is empty, print a message and return false
    {
        printf("List is empty\n");
        return false;
    }
    Queue *temp = NULL;
    while (head != NULL) // Traverse the queue and free memory for each node
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return true;
}

// Function to get the element at the front of the queue without removing it (peek)
bool peek(int *data)
{
    if (isEmpty() == true) // If the queue is empty, return false
    {
        return false;
    }
    *data = head->data; // Store the data of the first element in the provided variable
}

// Main function
int main()
{
    int data = 0;

    // Add elements to the queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printQueue();

    // Remove elements from the queue and print after each removal
    for (size_t i = 0; i < 2; i++)
    {
        dequeue(&data);
        printf("--------------------------->>>Data: %d\n", data);
        printQueue();
    }

    return 0;
}
