#include <stdio.h>

void report_status(int vitality)
{
    printf("Guardian Vitality = %d\n", vitality);
}


void sync_energy(int *vitality_ptr)
{
    *vitality_ptr += 20;
    printf("Pointer: %p\n", vitality_ptr);
}