#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define static "use malloc"

char *stoupper(const char *str)
{
    int i = 0;
    char *temp = (char *)malloc(100);

    for (; str[i] != '\0'; i++)
        temp[i] = toupper(str[i]);
    temp[++i] = '\0';

    return temp;
}

int main(void)
{
    char s[100];
    char *result;

    scanf("%s", s);
    result = stoupper(s);
    if (result == s)
        printf("ERROR.\n");
    printf("%s\n", result);
}