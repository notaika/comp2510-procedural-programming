#include <stdio.h>

/**
 * Shows us how the `scanf()` method is used and stored.
 *
 * @return user input
 */
int enterAge()
{
    // prompt
    printf("Please enter your age: ");

    int ageInput;

    // get user input
    scanf("%d", &ageInput);
    printf("User's age is: %d\n", ageInput);

    return 0;
}

/**
 * Use regex to make sure that input doesn't stop at white space(s).
 * [...] - creates a list of allowed characters
 * ^ - means "NOT"
 * \n - means "new line"
 *
 * @return user input
 */
int handleSpaces()
{
    printf("Enter your full name: ");
    char text[20];

    scanf(" %19[^\n]", text);
    printf("User's full name: %s", text);

    return 0;
}

/**
 * Scans a user string input and stores it.
 * Stops at the first white space it encounters.
 *
 * @return user input (before first white space)
 */
int noSpaceHandling()
{
    printf("Enter your full name: ");
    char text[20];

    scanf(" %s", text);
    printf("User's full name: %s", text);

    return 0;
}

int main(void)
{
    printf("\n== scanf() demo ==\n");
    // enterAge();
    printf("\n== scanf() NO space handling ==\n");
    // noSpaceHandling();
    printf("\n== scanf() spaces handling ==\n");
    // handleSpaces();

    return 0;
}
