#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[6] = "hello";
    char s2[4] = "wlo";
    char this[10];

    this = strstr(s1, s2);

    printf("%s\n", this);

    return 0;
}