#include <stdio.h>

#define CAPACITY 5
#define SIZE 6
/**
 * Week 2 - Arrays: Coding Examples
 * Arrays in C are <b>fixed blocks of concrete.</b>
 * - always use #define (e.g. #define CAPACITY 100, #define SIZE 10)
 * - out of bounds: undefined behaviour
 * - array size should be always of type size_t
 *      - for safety (arrays cannot go negative)
 *      - saves memory
 * - counters in loops should usually have type of size_t, but NOT in REVERSE LOOPS
 */

/**
 * Calculate the sum of all the elements in an array.
 *
 * @param numArr
 * @param arrSize
 * @return
 */
int cumulativeSum(int numArr[], size_t arrSize)
{
    // don't declare
    int sumOfArray = 0;
    printf("Array size: %zu\n", arrSize);

    for (size_t i = 0; i < arrSize; i++)
    {
        printf("Loop %zu: index = %zu | value = %d\n", i, i, numArr[i]);
        sumOfArray += numArr[i];
    }

    printf("The sum of the array is: %d\n", sumOfArray);
    return 0;
}

/**
 * Finds and returns the minimum element in a given array.
 *
 * @param numArr
 * @param arrSize
 * @return
 */
int findMinimum(int numArr[], size_t arrSize)
{
    int min = numArr[0];
    for (size_t i = 0; i < arrSize; i++)
    {
        if (numArr[i] < min)
        {
            min = numArr[i];
        }
    }

    printf("The minimum value in array: %d\n", min);
    return 0;
}

/**
 * Returns the number of values greater than five.
 *
 * @param numArr
 * @param arrSize
 * @return
 */
int greaterThanFive(int numArr[], size_t arrSize)
{
    int count = 0;
    for (size_t i = 0; i < arrSize; i++)
    {
        if (numArr[i] > 5)
        {
            count++;
        }
    }

    printf("The number of elements > 5: %d\n", count);
    return 0;
}

/**
 * Reverses and array and prints the values.
 *
 * @param numArr
 * @param arrSize
 * @return
 */
int reverseArray(int numArr[], size_t arrSize)
{
    int temp;

    for (size_t i = 0; i < arrSize / 2; i++)
    {
        temp = numArr[i];
        numArr[i] = numArr[arrSize - 1 - i];
        numArr[arrSize - 1 - i] = temp;
    }

    printf("Reversed Array: [");
    for (size_t i = 0; i < arrSize; i++)
    {
        if (i < arrSize - 1)
        {
            printf("%d, ", numArr[i]);
        } else
        {
            printf("%d", numArr[i]);
        }
    }
    printf("]\n");

    return 0;
}

/**
 * Prints array in reversed order. Doesn't reverse the array.
 *
 * @param numArr
 * @param capacity
 * @return
 */
int reverseArrayNoMods(int numArr[], int capacity)
{
    for (int i = capacity - 1; i >= 0; i--)
    {
        printf("%d ", numArr[i]);
    }

    return 0;
}

/**
 * Copies an array.
 */
void copyArray(int sourceArr[], size_t capacity)
{
    int copiedNumArr[capacity];

    for (size_t i = 0; i < capacity; i++)
    {
        copiedNumArr[i] = sourceArr[i];

        printf("Copied array: index = %zu | value = %d\n", i, copiedNumArr[i]);
    }
}

/*
 * Activity: Array Transformations
 * 1. Replace each element with running sum (sum from 0 to i)
 * 2. Shift all elements left by 1 (first element goes to the end)
 * 3. Reverse the array
 */
void arrayTransformations()
{
    // 1. Replace each element with running sum
    printf("A.) Running Sum\n");

    int runningSumArray[SIZE] = {2, 5, 1, 8, 3, 9};

    for (size_t i = 0; i < SIZE - 1; i++)
    {
        runningSumArray[i + 1] += runningSumArray[i];
        printf("index = %zu | value = %d\n", i, runningSumArray[i]);
    }
    printf("index = %d | value = %d\n", SIZE - 1, runningSumArray[SIZE - 1]);

    printf("\n");

    // 2. Shift elements by 1
    printf("B.) Shift elements left by 1\n");

    int shiftElementsArray[SIZE] = {2, 5, 1, 8, 3, 9};

    // Store variable at index 0.
    int shiftTemp = shiftElementsArray[0];

    for (size_t i = 0; i < SIZE; i++)
    {
        shiftElementsArray[i] = shiftElementsArray[i + 1];

        printf("index = %zu | value = %d\n", i, shiftElementsArray[i]);
    }

    shiftElementsArray[SIZE - 1] = shiftTemp;

    printf("\n");

    // 3. Reverse the array
    printf("C.) Reverse the array\n");

    int reversedArray[SIZE] = {2, 5, 1, 8, 3, 9};

    int reversedTemp;

    for (size_t i = 0; i < SIZE / 2; i++)
    {
        reversedTemp = reversedArray[i];
        reversedArray[i] = reversedArray[SIZE - 1 - i];
        reversedArray[SIZE - 1 - i] = reversedTemp;

        printf("index = %zu | value = %d\n", i, reversedArray[i]);
    }
    printf("index = %d | value = %d\n", 3, reversedArray[3]);
    printf("index = %d | value = %d\n", 4, reversedArray[4]);
    printf("index = %d | value = %d\n", 5, reversedArray[5]);
}

int main(void)
    {
    int numArr[CAPACITY] = {1, 2, 3, 4, 5};


    /*
     * get the size in main since arrSize is a whole block of memory
     * You cannot pass a raw array into a function (search up later why)
     */

    // get the array length
    size_t arrSize = sizeof(numArr) / sizeof(numArr[0]);
    printf("== Cumulative Sum ==\n");
    cumulativeSum(numArr, arrSize);
    printf("\n== Find Minimum Value ==\n");
    findMinimum(numArr, arrSize);
    printf("\n== Count > 5? ==\n");
    greaterThanFive(numArr, arrSize);
    printf("\n== Reverse Array ==\n");
    reverseArray(numArr, arrSize);

    printf("\n== Print Array in Reverse==\n");
    reverseArrayNoMods(numArr, CAPACITY);

    printf("\n== Copy Array ==\n");
    copyArray(numArr, CAPACITY);

    printf("\n== Activity: Array Transformations ==\n");
    arrayTransformations();

    return 0;
}


