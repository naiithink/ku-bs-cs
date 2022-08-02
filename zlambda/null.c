#include <stdio.h>

int main(void)
{
    char *s = "";

    do
    {
        printf("%d\n", *s);
    }
    while (*s++ != '\0');

    return 0;
}
