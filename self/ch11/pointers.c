#include <stdio.h>

#define SIZE 10

int addNumsToArr(int arr[]);
int findLargestInArray(int arr[]);
int findSmallestInArray(int arr[]);

int main(void)
{
    int numbers[SIZE] = {0};

    addNumsToArr(numbers);
    int largestFound = findLargestInArray(numbers);
    int smallestFound = findSmallestInArray(numbers);

    printf("Largest number found: %d\n", largestFound);
    printf("Smallest number found: %d\n", smallestFound);

    return 0;
}

int addNumsToArr(int arr[])
{
    printf("Enter %d numbers: ", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",&arr[i]);
    }
    return 0;
}

int findLargestInArray(int arr[])
{
    int largest = arr[0];

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}

int findSmallestInArray(int arr[])
{
    int smallest = arr[0];

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest;
}
