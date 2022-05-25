#include <stdio.h>

#define ARRAY_SIZE 5

typedef struct
{
    int a;
    int b;
    int c;
}
S;

void test(S t[])
{
    printf("%d\n", t[0].a);
    printf("%d\n", t[1].a);
}

int main(void)
{
    S a[3];

    a[0].a = 100;
    a[1].a = 150;

    test(a);

    // for (int i = 0; i < 2; i++)
    // {
    //     printf("%d\n", a[i]);
    // }

    return 0;
}