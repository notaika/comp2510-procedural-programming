#include <stdio.h>

// What happens if you forget the & operator when reading a number using scanf()?
// Is there a potential scenario where it actually works?
int main(void)
{
    printf("=== DATA TYPE SIZES===\n");
    printf("char size: %zu byte(s)\n", sizeof(char));
    printf("long long size: %zu byte(s)\n", sizeof(long long));
    printf("int size: %zu byte(s)\n", sizeof(int));

    printf("\n=== POINTER SIZES===\n");
    // sizes depend on the processor (32-bit vs. 64-bit)
    // data type doesn't matter for pointer size; it's a pointer? <- search up later

    printf("int* size: %zu byte(s)\n", sizeof(int*));
    printf("long long* size: %zu byte(s)\n", sizeof(long long*));
    printf("char* size: %zu byte(s)\n", sizeof(char*));

    printf("\n===\n");

    printf("Is there a potential scenario where it actually works?\nInput: ");
    // int a = 10;
    // int *ptr_a = &a;
    // printf("a: ", a);

    // Depends what is inside of 'a' but also...
    // 1. Use a data type that is 8-bytes long (long long is 8-bytes)
    // 2. Put address of a (&a) inside of 'a'

    long long a;
    a = (long long) &a;
    scanf("%lli", a); // input: 12
    printf("\na: %lli\n", a); // output: 12

    return 0;
}
