#include <stdio.h>

#define N 5

int a(int);

int main(void)
{
    for (int i = 1; i <= N; i++)
        printf("%d\n", a(i));

    return 0;
}

int a(int n)
{
    if (n <= 1)
        return 2;
    else
        return a(n - 1) + 3;
}
