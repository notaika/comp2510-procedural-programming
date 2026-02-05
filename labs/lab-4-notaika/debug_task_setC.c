/*
* Lab 5 Debug Task - Set C (in-lab)
 *
 * Compile: gcc -Wall -Wextra debug_task_setC.c -o debug_task_setC
 */

#include <stdio.h>
#include <stdlib.h>

// Task 1: Fill an integer sequence.
// Expected: write i*i to arr[0..n-1] and return 1 on success.
int fill_square_sequence(int *arr, int n) {
    if (!arr || n <= 0) {
        return 0;
    }

    int *p = arr; // holds array address to access

    for (int i = 0; i < n; i++) {
        // *(++p) <- moves pointer first then writes value (skips 0)
        *p = i * i; // assign value at mem address
        p++; // move to next position in arr
    }

    return 1;
}

// Task 2: Compute the average of an int array.
// Expected: average of arr[0..n-1] with no out-of-bounds reads.
double average(const int *arr, int n) {
    int sum = 0;

    const int *p = arr; // holds array address to access

    const int *end = arr + n; // points to one past the last element

    for (; p < end; p++) { // <- fix, changed p <= end to p < end to avoid out-of-bounds access
        printf("value at index %ld: %d\n",(p - arr), *p);
        sum += *p;

    }
    return (double) sum / n; // <- fix should be n not n - 1
}

// Task 3: Count how many values are above a threshold.
// Expected: count of elements in arr[0..n-1] that are > threshold.
int count_above(const int *arr, int n, int threshold) {
    int count = 0;

    for (const int *p = arr; p < arr + n; p++) {
        if (*p > threshold)  // <- fixed *(p + 1) to *p; cause skipped index 0 and also to stop over flowing
        {
            printf("VALUE FOUND AT %ld: %d\n",(p - arr), *p);
            count++;
        }
    }
    return count;
}

int main(void) {
    int n = 8;
    int seq[8];

    if (!fill_square_sequence(seq, n))
    {
        printf("Sequence setup failed\n");
        return 1;
    }

    printf("Average: %.2f\n", average(seq, n));
    printf("Above 10: %d\n", count_above(seq, n, 10));

    return 0;
}
