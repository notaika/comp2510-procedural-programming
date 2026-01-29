#include <stdio.h>

int cumulativeSum(int numArr[], size_t arrSize)
{
    // don't declare
    int sumOfArray = 0;
    printf("Array size: %zu\n", arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        printf("Loop %d: index = %d | value = %d\n", i, i, numArr[i]);
        sumOfArray += numArr[i];
    }

    printf("The sum of the array is: %d", sumOfArray);
    return 0;
}

int main(void)
{
    int numArr[] = {1, 2, 3, 4, 5};

    // get the array length
    // get it in main since arrSize is a whole block of memory
    // C know it takes up 20 bytes (5 integers and 4 bytes)
    size_t arrSize = sizeof(numArr) / sizeof(numArr[0]);
    cumulativeSum(numArr, arrSize);

    return 0;
}


