#include <stdio.h>

/**
 * Q2: What is the size of this struct? Why?
 *
 * A: 12 bytes (on modern 32/64-bit systems)
 *    CPU doesn't read memory 1 byte at a time
 *      but instead it grabs chunks (like 4 or 8 bytes)
 *
 *    If int is split across two different chunks, CPU needs to do two
 *    reads and some math <- makes program slow.
 *      To stay fast, compiler adds padding (empty space) so int
 *      starts exactly where the CPU expects it.
 *
 *    Note: different computers might add padding differently. Not accounting
 *          for those "empty spaces" (padding), the data gets shifted, and
 *          program starts to read the wrong numbers -> ruining
 *          File I/O (saving/loading) and Networking (sending data).
 *
 *    Therefore, if char a is 1 byte.... + 3 bytes to align. Total = 4
 *                  int  b is 4 bytes... already aligned.    Total = 8
 *                  char c is 1 byte.... + 3 bytes to align. Total = 12
 */
struct Mystery {
    char a;  // 1 byte
    int b;   // 4 bytes
    char c;  // 1 byte
};

/**
 * Q3:
 * You have a system that currently uses float for currency,
 * but you suspect you might need to change it to double later.
 *
 * Is there a way to address it in one place? How?
 *
 * A:
 * Yes. Using 'typedef' <- think of it as an "alias" or "nickname"
 *      lets you create a new name for an existing data type
 * Q3.A
 * This specific example shows how 'typedef' is used to create Abstraction.
 *  1. instead of writing 'float price;' all over the code, you define your
 *     intent once at the very top.
 *
 * Q3.B
 * Can make DRYer code with structs -> basically a shortcut
 *
 *
 */
typedef float currency_t; // Q3.A

struct Student // Q3.B
{
    char name[50];
    int id;
};

// Have to write 'struct' every time...
struct Student s1;
struct Student s2;

// declare it as a typedef instead..
typedef struct Student
{
    char name[50];
    int id;
} Student_t;

// Cleaner
Student_t s3;
Student_t s4;


void counter(void);

int main(void)
{
    // Q1
    counter();
    counter();
    counter();

    // Q3
    currency_t price = 19.99;

    return 0;
}

/**
 * Q1: Last week we learnt that static limits visibility for
 *     functions to the current file.
 *
 * Does it have other powers?
 * What do you expect to be the output of this code?
 */
void counter(void)
{
    /*
     * A:
     * 1. in a normal function, when a function ends, it gets cleaned up
     *    and thrown away
     *
     * 2. count is declared static -> gains a permanent memory
     *       when the function ends, count stays exactly where it is and waiting
     *       for the next time you call the function
     *
     * 3. most local variables live on the stack, but static variables
     *    live in the data segment

     * 4. if count were a normal variable, it would be set to 1 every single time
     *    counter was called.
     *
     *    since count is a static variable, it only gets initialized ONCE (the first
     *    time counter gets called) and initialization after every subsequent call
     *    gets ignored -> it holds its state
     *
     * 5. even if the variable count lives for the entire program, its scope is still
     *    contained inside the counter() function -> encapsulation
     *
     * 6. if you declare a function OR a variable static in the global scope (top of
     *    your file. without any surrounding brackets) it belongs to THIS file only.
     *    no other files (.c) in this project can see it, or use it -> like private in Java
     */
    static int count = 1;
    printf("This has been called %d time(s)\n", count);
    count++;



    /**
     * Q6
     */
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s\n", buffer);
    }
    fclose(fp);

    int c; // type is int to accomodate EOF
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fp);

    // Loop continues as long as fscanf successfully reads one integer
    while (fscanf(file, "%d", &number) == 1) {
        // Process the read number
        printf("Read number: %d\n", number);
    }

    // Check if the loop terminated due to EOF or a matching failure
    if (feof(file)) {
        printf("Reached end of file.\n");
    } else if (ferror(file)) {
        printf("An input error occurred.\n");
    } else {
        printf("Matching failure (e.g., non-numeric input encountered).\n");
    }


    FILE *fp;
    int x = 32;

    fp = fopen("output.txt", "w");

    fputc('B', fp);
    fputc('\n', fp);
    fprintf(fp, "x = %d\n", x);
    fputs("Hello, world!\n", fp);

    fclose(fp);



}

/**
 * Q5:
 * FILE* is a pointer that tells you exactly where that file you're referencing is.
 *  if file doesn't exist or is restricted -> fopen fails and returns NULL
 *      why checking is critical?
 *      if you don't check if the file opened successfully and immediately
 *      try to read from it, you are DEREFERENCING A NULL POINT.
 *          - likely crash (segmentation)
 */
FILE *fp = fopen("test.txt", "r");
if (fp == NULL)
{
    fprintf(stderr, "Error: File not found!\n"); // use stderr for errors
    return 1;
}


