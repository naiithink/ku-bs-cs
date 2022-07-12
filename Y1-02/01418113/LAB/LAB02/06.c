#include <stdio.h>

int main(void)
{
    char c[2], *ttype;
    fgets(c, 2, stdin);

    if (48 <= c[0] && c[0] <= 57)
    {
        ttype = "digit";
    }
    else if (65 <= c[0] && c[0] <= 90)
    {
        ttype = "upper case";
    }
    else if (97 <= c[0] && c[0] <= 122)
    {
        ttype = "lower case";
    }
    else
    {
        ttype = "others";
    }

    printf("Output: %s\n", ttype);

    return 0;
}