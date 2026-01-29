#include <stdio.h>

/**
 *
 */
void dataTypeSizes()
{
    printf("Sizes of different data types (in bytes)\n");

    printf("char: %zu bytes | %zu-bits\n", sizeof(char), sizeof(char) * 8); // 1 byte = 8-bits
    printf("bool: %zu bytes | %zu-bits\n", sizeof(bool), sizeof(bool) * 8); // 1 byte = 8-bits
    printf("void: %zu bytes | %zu-bits\n", sizeof(void), sizeof(void) * 8);
    printf("short: %zu bytes | %zu-bits\n", sizeof(short), sizeof(short) * 8); // 2 bytes = 16-bits
    printf("int: %zu bytes | %zu-bits\n", sizeof(int), sizeof(int) * 8);   // 4 bytes = 32-bits
    printf("float: %zu bytes | %zu-bits\n", sizeof(float), sizeof(float) * 8);   // 4 bytes = 32-bits
    printf("long: %zu bytes | %zu-bits\n", sizeof(long), sizeof(long) * 8); // 8 bytes = 64-bits
}

/**
 * Bitwise AND (&) - used to force-quit parts of a number while keeping others (masking).
 *
 */
void bitwiseAnd()
{
    int a = 1;
    int b = 2;

    printf("Here is your result: %d\n", a & b);
}

/**
 * Anything that is not a '0' in C is '1' (true).
 * Because of that... C if-statements don't only take boolean expressions.
 *
 * @return 0 = success
 */
int ifStatements(int toCheck)
{


    if (toCheck) {  // Java only accepts boolean expressions
        printf("a is non-zero\n");
    } else {
        printf("a is zero\n");
    }
    return 0;
}


int main(void)
{
    int a = 3;
    int b = 0;

    printf("\n== Data Type Sizes ==\n");
    // dataTypeSizes();

    printf("\n== Bitwise AND (&) ==\n");
    bitwiseAnd();

    printf("\n== Zero/Non-zero ==\n");
    ifStatements(a);
    ifStatements(b); // only 0 and 0.0

    return 0;
}
