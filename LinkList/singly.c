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


