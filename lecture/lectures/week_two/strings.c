#include <stdio.h>
#include <string.h>

/**
 * Calculates the input string's given length using a loop and the sentinel.
 *
 * @param str the string whose length will be counter
 */
void calculateStrLenLoop(char str[])
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    printf("String length: %d", length);
}

/**
 * Calculates the input string's given length using the header <string.h>
 *
 * @param str the string whose length will be counter
 */
void calculateStrLenHeader(char str[])
{
    size_t length = strlen(str);

    printf("String length: %zu\n", length);
}

int main(void)
{
    char stringExample[] = "crashout";

    printf("\n== Calculate String Length (M1) ==\n");
    calculateStrLenLoop(stringExample);

    printf("\n== Calculate String Length (M2) ==\n");
    calculateStrLenHeader(stringExample);

    return 0;
}
