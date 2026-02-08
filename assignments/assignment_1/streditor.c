#include <stdio.h>
#include "streditor.h"

int str_len(const char *str)
{
    const char *ptr = str;

    while (*ptr != '\0')
    {
        ptr++;
    }

    return (int) (ptr - str);
}

void str_reverse(const char *str)
{
    int length = str_len(str);

    if (length == 0)
    {
        return;
    }

    const char *cursor = str + length - 1;

    while (cursor >= str)
    {
        printf("%c", *cursor);
        cursor--;
    }

    printf("\n");
}

int is_alphanumeric(const char *str)
{
    int length = str_len(str);

    if (length == 0)
    {
        return 1;
    }

    const char *cursor = str;

    while (*cursor != '\0')
    {
        const char ch = *cursor;

        if (!((ch >= '0' && ch <= '9') ||
              (ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z')))
        {
            return 0;
        }

        cursor++;
    }
    return 1;
}
