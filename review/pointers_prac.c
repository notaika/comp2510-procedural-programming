#include <stdio.h>

int find_substring(const char *str, const char *substr);
int find_char(const char *str, char target);

int main(void)
{
    printf("find_char(\"hello\", 'l') = %d (expect 2)\n", find_char("hello", 'l'));
    printf("find_char(\"hello\", 'z') = %d (expect -1)\n", find_char("hello", 'z'));

    printf("find_substring(\"banana\", \"na\") = %d (expect 2)\n", find_substring("banana", "na"));
    printf("find_substring(\"banana\", \"xy\") = %d (expect -1)\n", find_substring("banana", "xy"));
    printf("find_substring(\"banana\", \"\") = %d (expect 0)\n", find_substring("banana", ""));

    return 0;
}

/**
 * Finds the first occurrence of a char in a string.
 *
 * @param str string
 * @param target target char
 * @return
 */
int find_char(const char *str,
              char target)
{
    const char *ptr = str;

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

/**
 * Finds the first occurrence of a substring in a string.
 *
 * @param str string
 * @param target target char
 * @return
 */
int find_substring(const char *str,
                   const char *substr)
{
    if (*substr == '\0')
    {
        return 0;
    }

    // scout - walk down the hallway one door at a time
    // "start the match here"
    const char *str_ptr = str;

    // start here loop
    while (*str_ptr != '\0')
    {
        const char *str_cur = str_ptr; // start at current door
        const char *sub_cur = substr; // starts at the beginning of pattern

        // matches or not the end? keep going
        while ((*str_cur == *sub_cur &&
            *sub_cur != '\0') &&
            *str_cur != '\0')
        {
            str_cur++;
            sub_cur++;
        }

        // we reached the end of sub?
        // found
        if (*sub_cur == '\0')
        {
            // str = the very first door
            // str_ptr address of the door we started with first letter of sub
            return (int) (str_ptr - str);
        }

        str_ptr++;
    }

    return -1;
}
