#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snacks.h"

#define STARTING_CAPACITY 2

/*
 * Reads the maximum price (first line) and all snack records.
 * Stores the snacks in a dynamically allocated array.
 *   - filename: input file name
 *   - snacks: output parameter; receives pointer to the array
 *   - max_price: output parameter; receives the price limit from the file
 * Returns the number of snacks read, or -1 on error (file open or allocation failure).
 */
int load_snacks(const char *filename,
                Snack **snacks,
                float *max_price)
{
    // open file
    FILE *fp = fopen(filename, "r");

    if (fp == nullptr)
    {
        fprintf(stderr, "ERROR: File not found.");
        return -1;
    }

    int capacity = 2;
    int stored = 0;

    // allocate memory for snack array, start with 2
    *snacks = malloc(sizeof(Snack) * capacity);
    if (*snacks == nullptr)
    {
        fprintf(stderr, "ERROR: Memory allocation failed for 'Snack'");
        return -1;
    }

    // read max price and assign to max_price
    int num_items_scanned = fscanf(fp, "%f", max_price);
    fgetc(fp); // eat leftover \n

    // create buffer for fgets
    char line[255];

    // fgets to read string, make sure that max price has already been scanned
    while (fgets(line, sizeof(line), fp) != nullptr &&
           num_items_scanned == 1)
    {
        // increase array size if capacity == stored
        if (capacity == stored)
        {
            int newSize = capacity * STARTING_CAPACITY;
            Snack *temp = realloc(*snacks, newSize * sizeof(Snack));
            if (temp == NULL)
            {
                fprintf(stderr, "ERROR: Reallocation failed.");
                return -1;
            }
            else
            {
                *snacks = temp;
                capacity = newSize;
            }
        }

        printf("Line: %d\n", stored);
        char *column = strtok(line, "|\n");

        // store name
        if (column != nullptr)
        {
            strcpy((*snacks)[stored].name, column);
            printf("Name stored: %s\n", (*snacks)[stored].name);
        }

        // store location
        column = strtok(nullptr, "|\n");
        if (column != nullptr)
        {
            strcpy((*snacks)[stored].location, column);
            printf("Location stored: %s\n", (*snacks)[stored].location);
        }

        // store price
        column = strtok(nullptr, "|\n");
        if (column != nullptr)
        {
            float parse_price = atof(column);
            (*snacks)[stored].price = parse_price;
            printf("Price: %.2f\n", (*snacks)->price);
        }

        // store calories
        column = strtok(nullptr, "|\n");
        if (column != nullptr)
        {
            int parse_calories = atoi(column);
            (*snacks)[stored].calories = parse_calories;
            printf("Calories: %d\n", (*snacks)->calories);
        }

        printf("\n");
        stored++;
    }

    fclose(fp);
    return stored;
}


/*
 * Writes snacks with price <= max_price to the output file.
 *   - filename: output file name
 *   - snacks: array of snacks
 *   - count: number of snacks in the array
 *   - max_price: price limit
 * Returns the number of snacks written, or -1 if the output file cannot be opened.
 */
int save_budget_snacks(const char *filename,
                       const Snack *snacks,
                       int count,
                       float max_price)
{
    int written_count = 0;

    // file to write into
    FILE* fp = fopen(filename, "w");
    if (fp == nullptr)
    {
        fprintf(stderr, "ERROR: File not found.\n");
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        // filter
        if (snacks[i].price <= max_price)
        {
            if (written_count > 0)
            {
                fprintf(fp, "\n");
            }

            fprintf(fp, "%s|%s|%.2f|%d", snacks[i].name, snacks[i].location, snacks[i].price, snacks[i].calories);
            written_count++;
        }
    }

    fclose(fp);
    return written_count;
}
