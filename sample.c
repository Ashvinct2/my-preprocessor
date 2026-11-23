#include <stdio.h>
#include "myheader.h"

// Single-line comment

#define NUMBER 100
#define CUBE(x) ((x)*(x)*(x))

int main()
{
    /* This is a
       multi-line comment */

    int a = NUMBER;
    int b = CUBE(3);
    int c = CUBE(4);

    display();

    printf("NUMBER = %d\n", a);
    printf("CUBE of 3 = %d\n", b);
    printf("CUBE of 4 = %d\n", c);

    return 0;
}
