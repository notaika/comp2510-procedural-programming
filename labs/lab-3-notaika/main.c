#include <stdio.h>
#include "guardian.h"

void fail_sync(int vitality)
{
    vitality += 20;
}

int main(void)
{
    int vitality = 50;

    fail_sync(vitality);
    printf("Fail Sync Energy: ");
    report_status(vitality);

    sync_energy(&vitality);
    printf("Sync Energy Address: %p\n", &vitality);
    printf("Sync Energy: ");
    report_status(vitality);

    return 0;
}

