#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MONTHS 12

int main(void) {


    int sum = 0;
    // int array[3]; //
    // int array[5] = {9, 1, 44};
    int intArr[10] = {10, 20, 30, 40, 50};
    char charArr[5] = {'a', 'b', 'c', 'd', 'e'};

    for (int i = 1; i <= 10; i++)
    {
        sum += i;
        // printf("sum: %d\n", sum);
        // printf("array: %d\n", array[i]);

        // printf("int array address: %d\n", &intArr[i]);
        // printf("char array address: %i\n", &charArr[i]);
    }
    // 1. Seed using current time
    // we don't have real random numbers in C
    // all the random numbers we get are pseudorandom numbers
    // means we have a long list of numbers in our OS and picks from it
    // pseudorandom = already generated
    // all comes from the same location (that's why we can back track a previously generated random number)
    // for real randomness = needs a component in the hardware
    // NEVER RE-SEED YOUR PSEUDONUMBERS
    srand(time(NULL));

    // 2. Generate numbers
    int r = rand(); // 0 to RAND_MAX

    // 3. Limit range (e.g. 0 to 9)
    // always [min, max)
    int small = rand() % 10;
    // printf("random num: %d\n", small);

    int data[SIZE] = {10, 20, 30, 40, 50};

    // Print all elements
    for (int i = 0; i < SIZE; i++)
    {
        // printf("data[%d] = %d\n", i, data[i]);
    }


    // int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    int index;

    for (index = 0; index < MONTHS; index++)
    {
        // printf("Month %d has %2d days. \n", index + 1, days[index]);
    }

    // char text[20] = "Programming";
    char text[] = "Programming";

    int length = 0;

    while (text[length] != '\0')
    {
        length++;
    }

    // printf("String length: %d\n", length); // 11
    // printf("Last char: %c", text[11]);

    char name[20];

    // printf("Enter name: ");
    // scanf("%s", name);
    // scanf("19%s", name);

    // printf("Name entered: %s\n", name);

    // finding the size of an array (length of array)
    int b[] = {2, 4, 6, 7, 10};

    size_t bLen = sizeof(b) / sizeof(b[0]);

    // printf("b[] length: %zu\n", bLen);

    int c[3] = {};

    size_t cLen = sizeof(c) / sizeof(c[0]); // 3

    for (int i = 0; i < cLen; i++)
    {
        // printf("%d ", c[i]);
    }

    // printf("c[] length: %zu\n", cLen);

    // generating random numbers












    return 0;
}