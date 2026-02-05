#include <stdio.h>
// **Task A: Debug a few problematic pointer operations**
// A file containing few problematic functions will be given to you. Find and fix the bugs.

// Task B: Find the first occurrence of target in str.
// Return the index, or -1 if not found.
int find_char(const char *str, char target) {
    // TODO (use pointer arithmetic)
    //  - use pointer to traverse string (it gets value)
    //  - if char matches target, return it (--ptr);
    const char *ptr = str;
    int index = 0;

    while (*ptr != '\0')
    {
        if (*ptr == target)
        {
            return (int) (ptr - str);
        }

        printf("char at index %d: %c\n", index, *ptr);
        ptr++;
        index++;
    }

    return -1;
}

// Task C: Find the first occurrence of substr in str.
// Return the index of the match, or -1 if not found.
// Edge case: if substr is empty (""), return 0.
int find_substring(const char *str, const char *substr) {
    // TODO (use pointer arithmetic)
    //  - handle edge cases

    // handle empty substring case
    if (*substr == '\0')
    {
        return 0;
    }

    const char *ptrMain = str;

    printf("Address of pointer: %p\n", ptrMain);
    printf("Value at pointer: %c\n", *ptrMain);

    ptrMain++;

    printf("Address of pointer: %p\n", ptrMain);
    printf("Value at pointer: %c\n", *ptrMain);

    // Address at ptrMain: 0x10026cb10
    // Address after ptrMain++: 0x10026cb11


    /*
     * char* str; <- means that this is of data type pointer of main string
     * char* substr; <- means that this is of data type pointer of substring we searching in main string for
     */


    return -1;
}

int main(void) {
    // printf("find_char(\"hello\", 'l') = %d (expect 2)\n", find_char("hello", 'l'));
    // printf("find_char(\"hello\", 'z') = %d (expect -1)\n", find_char("hello", 'z'));

    printf("find_substring(\"banana\", \"na\") = %d (expect 2)\n", find_substring("banana", "na"));
    // printf("find_substring(\"banana\", \"xy\") = %d (expect -1)\n", find_substring("banana", "xy"));
    // printf("find_substring(\"banana\", \"\") = %d (expect 0)\n", find_substring("banana", ""));

    return 0;
}