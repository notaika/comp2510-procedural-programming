/*
 * Lab 6 Debug Challenge
 *
 * Compile:
 *   gcc -Wall -Wextra -std=c11 debug_task_setC_v2.c -o debug_task_setC_v2
 */

#include <stdio.h>

struct Product {
    int id;
    char name[16];
    double price;
    int quantity;
};

static void print_product(const struct Product *p) {
    printf("ID:%d  Name:%-10s  Price:$%6.2f  Qty:%d\n", p->id, p->name, p->price, p->quantity);
}

// Task 1 (BUG): Apply a discount to a product.
// 'p' is a local copy of data passed in; gets destroyed as we leave the function
// change to *p and also use lambda to access pointer members
void apply_discount(struct Product *p, double discount_percent) {
    double reduction = p->price * (discount_percent / 100.0);
    p->price -= reduction;
}

// Task 2 (BUG): Find index of product with target_id.
// Return index, or -1 if not found.
// adding 1 to struct pointer moves it by struct num of bytes <- skipping array by 32 products, not bytes
int find_product_by_id(const struct Product *items, int count, int target_id) {
    const struct Product *curr = &items[0];
    const struct Product *end = items + count; // just add the count to find the end and move forward to next product

    while (curr < end)
    {
        if (curr->id == target_id)
        {
            return (int) (curr - items);
        }
        curr++;
    }

    // while (curr < items + count * (int)sizeof(struct Product)) {
    //     if (curr->id == target_id) {
    //         return curr - items;
    //     }
    //     curr += (int)sizeof(struct Product);
    // }
    return -1;
}

// Task 3 (BUG): Calculate total inventory value.
// Expected: sum(price * quantity) for all products.
double calculate_inventory_value(const struct Product *items, int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        const struct Product *curr = &items[i];

        total += curr->price * curr->quantity;
        // total += curr->price; <- ignores num items in stock
    }
    return total;
    // -> dereferences and accesses a member in structs
}

int main(void) {
    struct Product inventory[] = {
        {101, "Widget", 20.00, 3},
        {102, "Gadget", 50.00, 1},
        {103, "Tool", 10.00, 6}
    };
    int n = (int) (sizeof(inventory) / sizeof(inventory[0]));

    // Test Task 1
    // can do &inventory[0] too
    apply_discount(inventory, 10.0);
    printf("\nPrice after discount: %.2f (expect 18.00)\n", inventory[0].price);

    // Test Task 2
    printf("find_product_by_id(..., 103) = %d (expect 2)\n", find_product_by_id(inventory, n, 103));

    // Test Task 3
    // After discount: expected value = 18*3 + 50*1 + 10*6 = 164
    printf("Total inventory value: %.2f (expect 164.00)\n", calculate_inventory_value(inventory, n));

    return 0;
}
