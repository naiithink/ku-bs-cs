#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // char str[10];

    // gets(str);
    // fgets(str, 10, stdin);

    // printf("in - %s\n", str);

    /*
    char str_i[10];
    char str_f[10];
    char str_l[10];

    printf("Enter I: ");
    fgets(str_i, 10, stdin);
    printf("Enter F: ");
    fgets(str_f, 10, stdin);
    printf("Enter L: ");
    fgets(str_l, 10, stdin);

    int i = atoi(str_i);
    float f = atof(str_f);
    long l = atol(str_l);

    printf("%d - %.2f - %ld\n", i, f, l);
    */

    // Boolean false
    int found = 0;
    float f2 = 0.0;
    char c = '\0';              // terminate charater, null character, ascii code = 0

    // "kong" = ['k', 'o', 'n', 'g', '\0']              // array of charaters

    // Boolean true
    char str[10] = "";
    fgets(str, 10, stdin);
    int i = atoi(str);

    // Expressions
    // Relational Operators:    > >= < <= == !=
    // Logical Operators:       && || !
    if (i < 500)
    {
        printf("if %d\n", i < 500);
    }
    else if (i >= 500 && i < 1000)
    {
        printf("else if %d\n", i >= 500 && i < 1000);
    }
    else
    {
        printf("else %d - %d\n", i < 500, i >= 500 && i < 1000);
    }

    return 0;
}