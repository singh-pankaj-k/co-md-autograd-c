#include <stdio.h>
#include <stdbool.h>
#include "src/functions.h"


int main() {

    int a = 8, b = 10;
    int result = addTwoNumbers(a, b);

    bool z = true;

    printf("Sum of %d and %d is %d\n", a, b, result);

    printLimits();

    anotherFunction(a);

    // Variable number of arguments
    printf("\n 1 + 2 = %d ",
           AddNumbers(2, 1, 2));

    printf("\n 3 + 4 + 5 = %d ",
           AddNumbers(3, 3, 4, 5));

    printf("\n 6 + 7 + 8 + 9 = %d ",
           AddNumbers(4, 6, 7, 8, 9));

    readCsv();

    return 0;
}


