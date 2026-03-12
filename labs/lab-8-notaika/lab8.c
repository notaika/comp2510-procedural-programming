/*
 * Lab 8 Programming Task: Linked List Sensor Tracker
 *
 * Compile:
 *   gcc -Wall -Wextra lab8.c -o lab8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typedef struct representing a singly linked list node for sensor data
typedef struct SensorNode {
    int device_id;
    double temperature;
    char *location;
    struct SensorNode *next; // Pointer to the next node in the list
} SensorNode_t;

// Dynamic node creation (similar to last week's work)
SensorNode_t* create_node(int id, double temp, const char *loc) {
    // Allocate the struct itself
    SensorNode_t *node = malloc(sizeof(SensorNode_t));
    if (node == NULL) {
        fprintf(stderr, "malloc failed for node\\n");
        return NULL;
    }

    // Allocate memory for the location string
    node->location = malloc(strlen(loc) + 1);
    if (node->location == NULL) {
        fprintf(stderr, "malloc failed for location string\\n");
        free(node);
        return NULL;
    }

    // Copy string and initialize all fields
    strcpy(node->location, loc);
    node->device_id = id;
    node->temperature = temp;
    node->next = NULL;

    return node;
}

// Task A: Append a node to the end of the linked list.
void append_node(SensorNode_t **head, SensorNode_t *new_node) {
    // TODO: 1. If the list is empty (*head is NULL), set *head = new_node
    if (*head == nullptr) // <- safety check... list empty?
    {
        *head = new_node; // make new_node the head
        return;
    }

    SensorNode_t *curr_node = *head;

    // TODO: 2. Otherwise, traverse to the last node
    while (curr_node->next != nullptr)
    {
        curr_node = curr_node->next;
    }

    // TODO: 3. Set the last node's next pointer to new_node
    curr_node->next = new_node; // prep for next linked node
}

// Task B: Debugging! Fix the 3 logic bugs in this function.
int remove_sensor_by_id(SensorNode_t **head, int id) {
    // 1. safety check??
    if (*head == NULL)
    {
        return 0;
    }

    SensorNode_t *current = *head;
    SensorNode_t *previous = NULL; // cursor behind

    // 2. need to access the pointer to the next node
    while (current != NULL) {
        // if true, target found
        if (current->device_id == id) {
            // true? delete first node
            if (previous == NULL) {
                *head = current->next; // change to point to the NEXT node
            }
            else {
                // else, set prev node's "next node" ptr to node we want to delete
                previous->next = current->next;
            }

            free(current->location);
            free(current);
            return 1; // Successfully removed
        }

        previous = current;
        current = current->next;
    }

    return 0; // ID not found
}

// Task C: Traverse and print the linked list.
void print_list(const SensorNode_t *head) {
    // TODO: Traverse list and print: "[ID] Location: Temperature\\n"
    // Example: [101] Server Room A: 22.50
    // If empty, print "List is empty.\\n"

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    const SensorNode_t *curr_node = head;
    while (curr_node != NULL)
    {
        printf("[%d] %s: %.2f\n", curr_node->device_id, curr_node->location, curr_node->temperature);
        curr_node = curr_node->next;
    }
}

// Task D: Free all allocated memory.
void free_list(SensorNode_t *head) {
    // TODO: Traverse the list safely
    SensorNode_t *curr = head;

    while (curr->next != nullptr)
    {
        SensorNode_t *temp = curr;
        curr = curr->next;

        free(temp->location);
        free(temp);
    }
    // TODO: Free the location string, THEN free the node
    // Hint: Save node->next in a temporary variable before freeing the node!
}

int main(void) {
    SensorNode_t *head = NULL;

    // Create and append dynamic sensor data
    SensorNode_t *n1 = create_node(101, 22.5, "Server Room A");
    if (n1) append_node(&head, n1);

    SensorNode_t *n2 = create_node(205, -4.2, "External Roof Array");
    if (n2) append_node(&head, n2);

    SensorNode_t *n3 = create_node(310, 18.9, "Warehouse South");
    if (n3) append_node(&head, n3);

    printf("--- Initial Sensor List ---\n");
    print_list(head);

    // Test Task A (Debugging)
    printf("\nRemoving sensor 205... %s\n", remove_sensor_by_id(&head, 205) ? "Success" : "Failed");

    printf("\n--- Updated Sensor List ---\n");
    print_list(head);

    // Task D: Clean up memory
    free_list(head);
    head = NULL;

    return 0;
}