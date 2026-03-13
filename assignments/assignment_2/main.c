#include <stdlib.h>

#include "snacks.h"

int main(void)
{
    char input_file[] = "snacks.txt";
    char output_file[] = "budget.txt";

    Snack *snackies;
    float max_price;

    int num_stored = load_snacks(input_file, &snackies, &max_price);
    if (num_stored == -1)
    {
        return 1;
    }

    int num_written = save_budget_snacks(output_file, snackies, num_stored, max_price);
    if (num_written == -1)
    {
        return 1;
    }

    free(snackies);
    return 0;
}