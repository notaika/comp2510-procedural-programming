#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createMessage();
int main(void)
{
    createMessage();
    return 0;
}

void createMessage() {
    char *msg = malloc(50 * sizeof(char));
    // make it a const?
    // char * const msg = malloc(50 * sizeof(char));

    if (msg == NULL)
    {
        return;
    }

    // msg = "Welcome to Dynamic Memory!"; <- string literals are stored in... ? use strcopy then
    strcpy(msg, "Welcome to Dynamic Memory!");

    // EVEN BETTER TO USE `strncopy` -> up to 49 because last is null terminator ('\0')
    // strncpy(msg, "Welcome to Dynamic Memory!", 49); // <- can even make the count part better by making it length of string

    printf("%s\n", msg);

    free(msg);
}
