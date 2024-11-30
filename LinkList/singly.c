#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for a single linked list node
typedef struct SingleLinkList
{
  int data;
  struct SingleLinkList *next;
} Node;

// Declare a global pointer for the head of the linked list
Node *head = NULL;

// Function to print the linked list
void printLinkList(void)
{
  Node *temp = head;

  if (temp == NULL) // Check if the list is empty
  {
    printf("List is empty\n");
    return;
  }
  while (temp != NULL) // Traverse the list and print each element
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n\n");
}

// Function to add a node with data at the beginning of the list
void addAtFirst(int data)
{
  Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node

  if (newNode == NULL) // Check if memory allocation was successful
  {
    printf("No memory to allocate \n");
    return;
  }
  newNode->data = data; // Assign data to the new node
  newNode->next = NULL;

  if (head == NULL) // If the list is empty, make the new node the head
  {
    head = newNode;
  }
  else // If the list is not empty, add the new node at the beginning
  {
    newNode->next = head;
    head = newNode;
  }
}

// Function to add a node with data at the end of the list
void addAtLast(int data)
{
  Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node

  if (newNode == NULL) // Check if memory allocation was successful
  {
    printf("No memory to allocate \n");
    return;
  }
  newNode->data = data; // Assign data to the new node
  newNode->next = NULL;

  if (head == NULL) // If the list is empty, make the new node the head
  {
    head = newNode;
  }
  else // If the list is not empty, add the new node at the end
  {
    Node *temp = head;
    while (temp->next != NULL) // Traverse the list to find the last node
    {
      temp = temp->next;
    }
    temp->next = newNode; // Add the new node after the last node
  }
}

// Function to delete the first node from the list
void deleteAtFirst(void)
{
  if (head == NULL) // If the list is empty, print a message and return
  {
    printf("List is empty\n");
    return;
  }
  else // If the list is not empty, delete the first node
  {
    Node *temp = head;

    if (temp->next == NULL) // If there's only one node in the list, delete it and update head
    {
      free(temp);
      temp = NULL;
      head = NULL;
    }
    else // If there are multiple nodes in the list, delete the first node and update head
    {
      head = head->next;
      free(temp);
      temp = NULL;
    }
  }
}

// Function to delete the last node from the list
void deleteAtLast(void)
{
  Node *temp = head, *prev;

  if (head == NULL) // If the list is empty, print a message and return
  {
    printf("List is empty\n");
    return;
  }
  else // If the list is not empty, delete the last node
  {
    if (temp->next == NULL) // If there's only one node in the list, delete it and update head
    {
      free(temp);
      temp = NULL;
      head = NULL;
    }
    else // If there are multiple nodes in the list, traverse to the second last node and delete the last node
    {
      while (temp && temp->next) // Traverse the list to find the second last node
      {
        prev = temp;
        temp = temp->next;
      }
      prev->next = NULL; // Update the next pointer of the second last node
      free(temp); // Free memory allocated for the last node
      temp = NULL;
    }
  }
}

// Function to add a node with data in the middle of the list
void addAtMiddle(int data)
{
  Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node

  if (newNode == NULL) // Check if memory allocation was successful
  {
    printf("No memory to allocate \n");
    return;
  }
  newNode->data = data; // Assign data to the new node
  newNode->next = NULL;

  if (head == NULL) // If the list is empty, make the new node the head
  {
    head = newNode;
  }
  else // If the list is not empty, add the new node in the middle
  {
    Node *midPtr = head, *lastPtr = head->next;

    while (lastPtr && lastPtr->next) // Traverse the list to find the middle node
    {
      lastPtr = lastPtr->next->next;
      midPtr = midPtr->next;
    }
    newNode->next = midPtr->next; // Insert the new node after the middle node
    midPtr->next = newNode;
  }
}

// Function to delete the middle node from the list
void deleteAtMiddle_1(void)
{
  if (head == NULL) // If the list is empty, print a message and return
  {
    printf("List is empty\n");
    return;
  }
  if (head->next == NULL) // If there's only one node in the list, delete it and update head
  {
    free(head);
    head = NULL;
    return;
  }
  else // If there are multiple nodes in the list, delete the middle node
  {
    Node *lastPtr = head->next, *midPtr = head, *prev = NULL;

    while (lastPtr != NULL) // Traverse the list to find the middle node
    {
      prev = midPtr;
      midPtr = midPtr->next;

      lastPtr = lastPtr->next;
      if (lastPtr != NULL)
      {
        lastPtr = lastPtr->next;
      }
    }
    prev->next = midPtr->next; // Update the next pointer of the node before the middle node
    free(midPtr); // Free memory allocated for the middle node
  }
}

// Function to reverse the linked list iteratively
void reverseList(void)
{
  if (head == NULL || head->next == NULL) // If the list is empty or has only one node, no need to reverse
  {
    return;
  }
  else // If the list has more than one node, reverse it
  {
    Node *prevNode = NULL, *currNode = head, *nextNode = NULL;
    while (currNode != NULL) // Traverse the list and reverse the pointers
    {
      nextNode = currNode->next;
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
    }
    head = prevNode; // Update the head to point to the last node (previously the first node)
  }
}

// Function to reverse the linked list recursively
void reverseListRecursively(Node *ptr)
{
  if (ptr->next == NULL) // If the current node is the last node, make it the head
  {
    head = ptr;
    return;
  }
  reverseListRecursively(ptr->next); // Recursively call the function with the next node
  Node *temp = ptr->next;
  temp->next = ptr;
  ptr->next = NULL;
}

// Function to check if the linked list contains a loop
bool findLoopInList()
{
  // Creating a loop in the list for testing purposes
  addAtFirst(4);
  addAtFirst(5);
  addAtFirst(7);
  addAtFirst(8);
  addAtFirst(9);
  addAtFirst(55);
  addAtFirst(88);
  addAtFirst(35);
  addAtFirst(66);
  printLinkList();
  // head->next->next->next = head->next->next; // Uncomment to introduce loop in the list

  Node *slow = head, *fast = head;

  // Using Floyd's cycle detection algorithm to find a loop in the list
  while (slow && fast && fast->next)
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

// Main function
int main()
{
  // Adding elements to the linked list
  addAtFirst(1);
  addAtFirst(5);
  addAtFirst(4);
  addAtFirst(5);
  addAtFirst(2);
  addAtFirst(33);
  printLinkList();

  return 0;
}
