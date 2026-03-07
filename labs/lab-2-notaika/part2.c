#include <stdio.h>

int main() {
    char path[100];
    int x = 0, y = 0;
    int stamina = 100;

    // length of input string
    int i = 0;
    
    printf("Enter path: ");
    scanf("%99s", path);

    // TODO: Write your while loop here.
    // Use a 'moved' flag to handle printing coordinates!
    // Remember: 'W'=Up, 'S'=Down, 'D'=Right, 'A'=Left, 'P'=Potion, 'T'=Trap

    while (path[i] != '\0' && stamina > 0)
    {
        int moved = 0;

        switch (path[i])
        {
            case 'W':
                y++;
                moved = 1;
                break;
            case 'S':
                y--;
                moved = 1;
                break;
            case 'D':
                x++;
                moved = 1;
                break;
            case 'A':
                x--;
                moved = 1;
                break;
            case 'P':
                stamina += 5;
                printf("> Drank potion.\n");
                break;
            case 'T':
                printf("> TRAP HIT!\n");
                printf("Final Position: (%d, %d), Stamina: %d\n", x, y, stamina);
                return 0;
            default:
                break;
        }

        if (moved)
        {
            stamina -= 1;
            printf("> Hero moved to (%d, %d)\n", x, y);
        }

        i++;
    }

    printf("Final Position: (%d, %d), Stamina: %d\n", x, y, stamina);
    return 0;
}