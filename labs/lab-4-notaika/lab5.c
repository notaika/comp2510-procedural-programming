#include <stdio.h>
// **Task A: Debug a few problematic pointer operations**
// A file containing few problematic functions will be given to you. Find and fix the bugs.

// Task B: Find the first occurrence of target in str.
// Return the index, or -1 if not found.
int find_char(const char *str, char target) {
    const char *ptr = str; // creates a second pointer that points to the exact same start location as str

    while (*ptr != '\0')
    {
        if (*ptr == target)
        {
            return (int) (ptr - str);
        }

        ptr++;
    }
    return -1;
}

// Task C: Find the first occurrence of substr in str.
// Return the index of the match, or -1 if not found.
// Edge case: if substr is empty (""), return 0.
int find_substring(const char *str, const char *substr) {
    // handle empty substring case
    if (*substr == '\0')
    {
        return 0;
    }

    const char *ptr_str = str;

    while (*ptr_str != '\0')
    {
        const char *ptr_cursor = ptr_str; // cursor for string
        const char *ptr_subcur = substr; // cursor for substring

        /*
        * if and while the characters match, and you haven't reached end of word
        * and haven't reached end of substring... move the cursors
        */
        while (*ptr_cursor == *ptr_subcur &&
            *ptr_cursor != '\0' &&
            *ptr_subcur != '\0')
        {
            ptr_cursor++;
            ptr_subcur++;
        }

        // if we reach the end of substring, return index
        if (*ptr_subcur == '\0')
        {
            return (int) (ptr_str - str);
        }

        ptr_str++;
    }

    return -1;
}

int main(void) {
    printf("find_char(\"hello\", 'l') = %d (expect 2)\n", find_char("hello", 'l'));
    printf("find_char(\"hello\", 'z') = %d (expect -1)\n", find_char("hello", 'z'));

    printf("find_substring(\"banana\", \"na\") = %d (expect 2)\n", find_substring("banana", "na"));
    printf("find_substring(\"banana\", \"xy\") = %d (expect -1)\n", find_substring("banana", "xy"));
    printf("find_substring(\"banana\", \"\") = %d (expect 0)\n", find_substring("banana", ""));

    return 0;
}