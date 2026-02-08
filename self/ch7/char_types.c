#include <stdio.h>

int clearInputBuffer(void);
int clearInputBufferCondensed(void);
int getMessageLength(void);

int main(void)
{
    getMessageLength();
}

/**
 * Clears the input buffer by reading characters until a newline is encountered (flushing stdin).
 * Used to consume and discard characters until the line ends.
 *
 * @return 0 on success
 */
int clearInputBuffer(void)
{
    // temporary trash variable
    char ch;

    printf("Enter a character: \n");
    do
    {
        scanf("%c", &ch);
    } while (ch != '\n');

    return 0;
}

/**
 * Clears the input buffer by reading characters until a newline is encountered (flushing stdin).
 * Used to consume and discard characters until the line ends.
 *
 * @return 0 on success
 */
int clearInputBufferCondensed(void)
{
    // temporary trash variable
    char ch;

    printf("Enter a character: \n");

    while ((ch = getchar()) != '\n');

    return 0;
}

/**
 * Loops through input message, using getchar to read characters.
 *
 * @return 0 on success
 */
int getMessageLength(void)
{
    char ch;
    int len = 0;

    printf("Enter a message: ");
    while (getchar() != '\n')
    {
        len++;
    }

    printf("Your message was %d character(s) long.\n", len);

    return 0;
}
