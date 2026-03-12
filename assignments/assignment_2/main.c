#include <stdio.h>
#include <stdlib.h>

#include "snacks.h"

int main(void)
{
    char input_file[] = "./files/snacks.txt";
    char output_file[] = "./files/budget.txt";

    Snack *snackies;
    float max_price;

    int num_stored = load_snacks(input_file, &snackies, &max_price);
    if (num_stored == -1)
    {
        return 1;
    }

    // printf("%s", snackies->location);
    printf("Number of snacks stored: %d\n", num_stored);

    // test see array
    for (int i = 0; i < num_stored; i++)
    {;
        printf("Snack Details: %s | %s | %.2f | %d\n", snackies[i].name, snackies[i].location, snackies[i].price, snackies[i].calories);
    }

    int num_written = save_budget_snacks(output_file, snackies, num_stored, max_price);
    if (num_written == -1)
    {
        return 1;
    }

    free(snackies);

    printf("%d\n", num_written);
    return 0;
}