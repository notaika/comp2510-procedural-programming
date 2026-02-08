#include <stdio.h>
#include "streditor.h"

#define MAX_CAPACITY 201

int main(void)
{
    // changed this from int to char to avoid infinite bug loop if user entered characters first
    char operation[2];
    char input[MAX_CAPACITY];

    bool terminate = false;

    printf("Welcome to String Editor\n"
               "Operation Codes\n"
               "1 - print length of string\n"
               "2 - print string in reverse\n"
               "3 - check if string only contains alphanumeric characters\n"
               "==========================\n");

    while (!terminate)
    {

        printf("Enter an operation code [0 - 3] and a string: ");
        scanf("%s %s", operation, input);

        switch (operation[0])
        {
            case '0':
                printf("\nGoodbye!");
                terminate = true;
                break;
            case '1':
                printf("%d\n", str_len(input));
                break;
            case '2':
                str_reverse(input);
                break;
            case '3':
                if (is_alphanumeric(input))
                {
                    printf("Y\n");
                }
                else
                {
                    printf("N\n");
                }
                break;
            default:
                printf("ERROR: Not a valid operation code.\n");
                break;
        }
    }
    return 0;
}