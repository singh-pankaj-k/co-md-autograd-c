//
// Created by Pankaj Priscilla on 2023-04-23.
//

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "read_csv.h"

#define MAXCHAR 1000

int addTwoNumbers(int firstNumber, int secondNumber) {
    return firstNumber + secondNumber;
}

int anotherFunction(int a) {

    printf("The a in outer scope - %d\n", a);

    return 0;
}

// Variadic function to add numbers
int AddNumbers(int n, ...) {
    int Sum = 0;

    // Declaring pointer to the
    // argument list
    va_list ptr;

    // Initializing argument to the
    // list pointer
    va_start(ptr, n);

    for (int i = 0; i < n; i++)

        // Accessing current variable
        // and pointing to next one
        Sum += va_arg(ptr, int);

    // Ending argument list traversal
    va_end(ptr);

    return Sum;
}

int printLimits() {

    printf("%s contains %zu bits.\n", "A char", 8 * sizeof(char));
    printf("    %s takes values from %d to %d.\n", "A signed char", SCHAR_MIN, SCHAR_MAX);
    printf("    %s takes values from %u to %u.\n", "An unsigned char", 0, UCHAR_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "A short", 8 * sizeof(short));
    printf("    %s takes values from %d to %d.\n", "A signed short", SHRT_MIN, SHRT_MAX);
    printf("    %s takes values from %u to %u.\n", "An unsigned short", 0, USHRT_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "A long", 8 * sizeof(long));
    printf("    %s takes values from %ld to %ld.\n", "A signed long", LONG_MIN, LONG_MAX);
    printf("    %s takes values from %u to %lu.\n", "An unsigned long", 0, ULONG_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "A long long", 8 * sizeof(long long));
    printf("    %s takes values from %lld to %lld.\n", "A signed long long", LLONG_MIN, LLONG_MAX);
    printf("    %s takes values from %u to %llu.\n", "An unsigned long long", 0, ULLONG_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "An int", 8 * sizeof(int));
    printf("    %s takes values from %d to %d.\n", "A signed int", INT_MIN, INT_MAX);
    printf("    %s takes values from %u to %u.\n", "An unsigned int", 0, UINT_MAX);
    printf("\n");

    return 0;
}

int readCsv() {

    printf("reading csv\n\n");

    FILE *fp;
    char row[MAXCHAR];
    int is_ok = EXIT_FAILURE;

    fp = fopen("/Users/pankajpriscilla/CLionProjects/NeuralNet/data/test.csv", "r");

    if (fp == NULL)
    {
        printf("Can not open file");
    }

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        printf("Row: %s", row);
    }

    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp)) {
        puts("End of file is reached successfully");
        is_ok = EXIT_SUCCESS;
    }

    fclose(fp);
    return is_ok;
}