#include <stdio.h>

#define SIZE 5
#define CAPACITY ((int) (sizeof(a) / sizeof(a[0])))

int copyArray(void);
int repeatedDigits(void);
int useOfSizeOf(void);
int reverseArrVariable(void);

int main(void)
{
    // copyArray();
    useOfSizeOf();
    reverseArrVariable();

    return 0;
}

int copyArray(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int numbersCopy[SIZE] = {0};

    printf("BEFORE COPYING\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("numbers index %d: %d\n", i, numbers[i]);
        printf("numbersCopy index %d: %d\n", i, numbersCopy[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        numbersCopy[i] = numbers[i];
        printf("numbers index %d: %d\n", i, numbers[i]);
        printf("numbersCopy index %d: %d\n", i, numbersCopy[i]);
    }

    printf("\nAFTER COPYING\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("numbers index %d: %d\n", i, numbers[i]);
        printf("numbersCopy index %d: %d\n", i, numbersCopy[i]);
    }
}

/**
 * Scans a number from the user and detects if any digit appears more than once.
 *  Algorithm:
 *  1. Create a boolean lookup table (flags) for digits 0-9.
 *  2. Loop through the number's digits from right to left using (n % 10).
 *  3. If a digit's flag is already true, we found a repeat -> Break loop.
 *  4. Otherwise, mark the flag as true and slice the number (n /= 10).
 *
 * Note: Logic relies on 'n' remaining > 0 if the loop broke early due to a repeat.
 *
 * @return 0 on success;
 */
int repeatedDigits(void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n; // long to allow user to enter numbers up to 2,147,483,647

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        if (digit_seen[digit])
        {
            break;
        }

        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0)
    {
        printf("Repeated digit\n");
    }
    else
    {
        printf("No repeated digit\n");
    }

    return 0;
}

int useOfSizeOf(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (int i = 0; i < CAPACITY; i++)
    {
        printf("a index %d: %d\n", i, a[i]);
    }

    return 0;
}

/**
 * Example of a variable length array (VLA).
 *
 * @return 0 on success
 */
int reverseArrVariable(void)
{
    int i, n;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d numbers: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("In reverse order: ");

    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
