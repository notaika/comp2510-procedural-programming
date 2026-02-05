#include <stdio.h>

// How do we work arrays with pointers?
int main(void)
{
    int a[5] = {1, 2, 3};

    // Why is it 20 bytes?
    // integer is 4 bytes => 5 * 4 = 20 bytes
    printf("Size (memory) of array a: %zu\n", sizeof(a)); // 20

    // mem size of array / mem size of one element = length of array
    printf("Size (length) of array a: %zu\n", sizeof(a) / sizeof(int));
    printf("Size (length) of array a: %zu\n", sizeof(a) / sizeof(a[0]));
    // int *ptr = &a[0];

    // *ptr = 4;

    printf("Test");

    printf("\n\n");

    char str[5] = {'a', 'd', 'b'};
    char *ptr_c = &str[0];

    int b[5] = {10, 20, 30, 40, 50};
    int *ptr_b = &b[0];

    // Q: What happens when we do this?
    // ptr_c++; // A: we move to the next location in memory (1 byte)
    // ptr_b++; // A: we move to the next location in memory (4 bytes)

    // printf("%c\n", *ptr_c); // d
    // printf("%d\n", *ptr_b); // 20

    // ptr_c += 2; // ptr_c = ptr_c + 2 * sizeof(char) => ptr_c = ptr_c + 2 * 1
    // ptr_b += 2; // ptr_b = ptr_b + 2 * sizeof(int) => ptr_b = ptr_b + 2 * 4

    // printf("%c\n", *ptr_c); // b
    // printf("%d\n", *ptr_b); // 30

    // ++ (pre/post-fix) operators have higher precedence than * (dereference) operator

    // printf("*ptr_b++: %d\n", *ptr_b++); // 10
    // printf("*(ptr_b)++: %d\n", *(ptr_b)++); // 30
    // printf("*++ptr_b: %d\n", *++ptr_b); // 20

    return 0;
}
