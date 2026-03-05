#include <stdio.h>

int readByLine(FILE *fp);
int readByChar(FILE *fp);
int readFormatted(FILE *fp);

int main(void)
{
    FILE *fp = fopen("format_test.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR: File not found.\n");
    }
    else
    {
        printf("File found.\n");
    }

    // printf("Read by line:\n");
    // readByLine(fp);

    // printf("Read by char:\n");
    // readByChar(fp);

    printf("Read by formatted text:\n");
    readFormatted(fp);

    return 0;
}

int readByLine(FILE *fp)
{
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    return 0;
}

int readByChar(FILE *fp)
{
    int c; // MUST be int (NOT char) to hold EOF

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c); // a super-fast version of printf("%c", c);
    }

    return 0;
}

int readFormatted(FILE *fp)
{
    char name[100];
    float length;
    int mass;

    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
    {
        printf("Type: %s whale\nWeight: %d tonnes\nLength: %.1f metres\n\n", name, mass, length);
    }

    // check why we stopped
    if (feof(fp))
    {
        printf("Reached the end of the file.\n");
    } else if (ferror(fp))
    {
        printf("A readding error occured.\n");
    } else
    {
        printf("Data format error (e.g. non-numeric input).\n");
    }

    return 0;
}
