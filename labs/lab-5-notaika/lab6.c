#include <stdio.h>

#define INVENTORY_SIZE 4

// Define the Product structure
struct Product
{
    int id;
    char name[50];
    double price;
    int quantity;
};

// Task B: Order two products in-place by total inventory value.
// Total value is (price * quantity).
// If they're out of order, swap the structs.
// Return 1 if a swap happened, otherwise 0.
int order_by_total_value(struct Product* a, struct Product* b)
{
    const double a_value = a->price * a->quantity;
    const double b_value = b->price * b->quantity;

    if (a_value > b_value)
    {
        const struct Product temp = *a;
        *a = *b;
        *b = temp;

        return 1;
    }
    return 0;
}

// Task C: Find the most expensive product.
// Return a pointer to the product in the array, or NULL if count is 0.
// If there's a tie, return the first one.
const struct Product* find_most_expensive(const struct Product* products, int count)
{
    // if array is empty, return null
    if (count <= 0)
    {
        return NULL;
    }

    // start at index 1
    const struct Product *most_expensive = products;

    const struct Product *cursor = products;
    const struct Product *end = products + count;

    while (cursor < end)
    {
        if (cursor->price > most_expensive->price)
        {
            most_expensive = cursor;
        }
        cursor++;
    }

    return most_expensive;
}

int main(void)
{
    // Test data
    struct Product inventory[INVENTORY_SIZE] = {
        {101, "Widget", 19.99, 3},
        {102, "Gadget", 45.50, 1},
        {103, "Tool", 12.00, 6},
        {104, "Gizmo", 45.50, 2}
    };

    // Task B Tests
    // Use copies so we don't affect Task C's array.
    struct Product a = inventory[3]; // Gizmo: 45.50 * 2 = 91.00
    struct Product b = inventory[1]; // Gadget: 45.50 * 1 = 45.50

    printf("Before order: a=%s ($%.2f x %d)  b=%s ($%.2f x %d)\n",
           a.name, a.price, a.quantity, b.name, b.price, b.quantity);

    printf("order_by_total_value(&a, &b) = %d (expect 1)\n", order_by_total_value(&a, &b));

    printf("After order:  a=%s ($%.2f x %d)  b=%s ($%.2f x %d)\n",
           a.name, a.price, a.quantity, b.name, b.price, b.quantity);


    // Task C
    const struct Product* p = find_most_expensive(inventory, INVENTORY_SIZE);
    printf("find_most_expensive(inventory, %d) -> id %d (expect 102)\n", INVENTORY_SIZE, p ? p->id : -1);
    return 0;
}