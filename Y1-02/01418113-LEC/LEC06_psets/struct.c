#include <stdio.h>

typedef struct
{
    char a;
    char b;
} test;

int main(void)
{
    test z;
    z.a = 'a';
    z.b = 'b';
    printf("%c, %c\n", z.a, z.b);
}