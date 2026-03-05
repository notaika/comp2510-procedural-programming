#include <stdio.h>

int safeRead(FILE *fp);
int charRead(FILE *fp);

int main(void)
{
    return 0;
}

int safeRead(FILE *fp)
{
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), fp))
    {
        printf("%s\n", buffer);
    }

    return 0;
}

int charRead(FILE *fp)
{
    int c;

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    return 0;
}
