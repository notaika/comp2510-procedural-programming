#include <stdio.h>

/**
 * Switch statements in C:
 * - must evaluate to an integer compatible type only:
 *      - int, char, short, long or enum
 * - cases must be CONSTANT and known at compile-time
 */

void gradeChecker()
{
    char gradeToCheck;

    printf("Enter your letter grade (A, B, C, or F?): ");
    scanf("%c", &gradeToCheck);

    switch (gradeToCheck)
    {
        case 'A':
            printf("86%% - 100%%\n");
            break;
        case 'B':
            printf("73%% - 85%%\n");
            break;
        case 'C':
            printf("64%% - 72%%\n");
            break;
        default:
            printf("< 50%%\n");
    }
}




int main(void)
{
    gradeChecker();

    return 0;
}
