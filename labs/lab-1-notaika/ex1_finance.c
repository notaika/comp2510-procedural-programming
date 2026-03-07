#include <stdio.h>

int main() {
    int salary = 50000;
    int bonus_percentage = 10;
    
    // Calculate the bonus
    // Then add it to the salary
    float bonus_multiplier = (float) bonus_percentage / 100;
    
    int final_salary = salary + (salary * bonus_multiplier);

    printf("Calculating Year-End Salary...\n");
    printf("Base Salary: $%d\n", salary);
    printf("Bonus Multiplier: %f\n", bonus_multiplier);
    
    // Output the total
    printf("Final Salary with Bonus: $%d\n", final_salary);

    return 0;
}
