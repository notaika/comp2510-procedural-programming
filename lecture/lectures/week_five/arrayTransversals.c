#include <stdio.h>

#define SIZE 5
int array_transversal(int *arr, int size);

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};

    array_transversal(a, SIZE);
    return 0;
}

// What is the benefit of using a pointer in a for-loop?
int array_transversal(int *arr, int size)
{
    printf("Using pointer: ");
    for (int *ptr = arr; ptr < arr + size; ptr++)
    {
        printf("%d, ", *ptr);
    }

    printf("\nUsing i: ");
    for (int i = 0; i < size;  i++)
    {
        printf("%d, ", i);
    }

    return 0;
}
