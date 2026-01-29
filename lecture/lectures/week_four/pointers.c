#include <stdio.h>
//
// Created by aika. on 2026-01-29.
//

void reset(int *x, int *y)
{
    *x = 0;
    *y = 0;

    printf("%d, %d", *x, *y);
}

int main(void)
{
    int x = 100, y = 200;
    reset(&x, &y);
    int *z;

    return 0;
}