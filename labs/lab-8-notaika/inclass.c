#include <stdio.h>
#include <stdlib.h>

/**
 * Define a node for a linked list.
 */
typedef struct node
{
    int val; // data
    struct node *next; // the map (pointer that stores mem address of next node in chain)
} node_t;

/**
 *
 * @param val
 * @return
 */
node_t *create_node(int val)
{
    // 1. Memory Allocation - malloc finds space and returns address of the first byte
    // store that address in a pointer variable called new_node
    node_t *new_node = malloc(sizeof(node_t));

    // 2. Safety check! (out of RAM? return null)
    // prevents segmentation fault
    if (new_node == NULL) return nullptr;

    // 3. Initialization
    // Go to address stored in new node; find field named val
    new_node->val = val;    // Assign the value

    // set next to nullptr bc there isn't anything connected to it yet
    new_node->next = nullptr;  // Initialize the pointer to NULL

    return new_node;
}

void push(struct node **head, int val, int *size) {
    struct node *new_node = create_node(val);
    new_node->next = *head;
    
    // We update head, but it doesn't affect main!
    *head = new_node;
    *size += 1;
}

int main() {
    node_t *head = NULL;
    head = create_node(20);

    // 6
    // int size = 1;
    //
    // printf("Before: %d\n", head->val);
    // push(&head, 10, &size);
    // printf("After: %d\n", head->val);

    // 7
    // node_t *curr = head;   // List: 10 -> 20 -> 30 -> NULL
    //
    // while (curr->next != NULL) {
    //     curr = curr->next;
    // }
    // // curr is now NULL
    //
    // curr = create_node(99);
    // // Is 99 part of the list now?
    //
    // printf("After: %d\n", curr->val);
    // return 0;

    head->val = 10;
    head->next = malloc(sizeof(struct node));
    head->next->val = 20;
    head->next->next = NULL;
    // List: 10 -> 20 -> NULL

    // Goal: Remove the first node (10)
    node_t *temp = head;
    head = head->next;
    free(temp);
}