#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

node_t *create_node(int val)
{
    node_t *new_node = malloc(sizeof(struct node));
    new_node -> val;

    return new_node;
}

int main(void)
{
    int arr[5] = {10, 30, 40, 50};   // 4 used elements
    int size = 4;
    // Goal: Insert 20 at index 1 (between 10 and 30)

    // node_t *a = malloc(sizeof(struct node));
    // node_t *b = malloc(sizeof(struct node));
    //
    // a->val = 10;
    // b->val = 20;
    // a->next = b;
    //
    // printf("Beginning of loop: %d\n", b->val);

    // free(a);
    // What happened to b?

    // 5

    node_t *head = create_node(arr[0]);

    // point to head
    node_t *curr = head;
    for (int i = 0; i < size; i++)
    {
        printf("Beginning of loop: %d\n", curr->val);

        curr->next = create_node(arr[i]);
        curr = curr->next;

        printf("End of loop: %d\n", curr->val);
    }

    return 0;
}
