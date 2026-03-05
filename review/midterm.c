#include <stdio.h>

#define SIZE 6
#define CLASS_SIZE 3
#define NUM_GRADES 3

struct Student {
    int id;
    int grades[NUM_GRADES];
};

void reverseArray(int arr[], int size);
int totalScore(const struct Student *s);
int findTopStudent(const struct Student classList[], int size);

int main(void) {
    int numbers[SIZE] = {5, 10, 15, 20, 25, 30};

    printf("Question 1:\n");
    printf("Before: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", numbers[i]);
    printf("\n");

    reverseArray(numbers, SIZE);

    printf("After: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", numbers[i]);
    printf("\n");

    printf("\nQuestion 2:\n");
    struct Student classList[CLASS_SIZE] = {
        {101, {80, 90, 70}},
        {102, {88, 92, 85}},
        {103, {100, 60, 75}}
    };

    int topIndex = findTopStudent(classList, CLASS_SIZE);

    printf("Top student id: %d\n", classList[topIndex].id);
    printf("Top total: %d\n", totalScore(&classList[topIndex]));

    return 0;
}

void reverseArray(int arr[], int size)
{
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
int totalScore(const struct Student *s)
{
    int sum = 0;

    for (int i = 0; i < NUM_GRADES; i++)
    {
        sum += s->grades[i];
    }

    return sum;
}
int findTopStudent(const struct Student classList[], int size)
{
    int top_index = 0;
    int highest_score = totalScore(&classList[0]);

    for (int i = 0; i < size; i++)
    {
        int current_score = totalScore(&classList[i]);

        if (current_score > highest_score)
        {
            highest_score = current_score;
            top_index = i;
        }
    }

    return top_index;
}
