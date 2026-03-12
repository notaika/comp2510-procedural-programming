#ifndef ASSIGNMENT_2_SNACKS_H
#define ASSIGNMENT_2_SNACKS_H

typedef struct {
    char name[50];
    char location[50];
    float price;
    int calories;
} Snack;

int load_snacks(const char *filename, Snack **snacks, float *max_price);

int save_budget_snacks(const char *filename, const Snack *snacks,
                       int count, float max_price);

#endif //ASSIGNMENT_2_SNACKS_H