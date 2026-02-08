#include <stdio.h>
#include "guardian.h"

void fail_sync(int vitality)
{
    vitality += 20;
    printf("Fail Sync (during): ");
    report_status(vitality);
}

int main(void)
{
    int vitality = 50;

    printf("Fail Sync (before): ");
    report_status(vitality);

    fail_sync(vitality);
    printf("Fail Sync (after): ");
    report_status(vitality);

    sync_energy(&vitality);
    printf("Sync Energy Address: %p\n", &vitality);
    printf("Sync Energy: ");
    report_status(vitality);

    return 0;
}

