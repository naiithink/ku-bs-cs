#include <stdio.h>

#define N 5

int a(int, int);

int main(void)
{
    for (int i = 1; i <= N; i++)
        printf("%d\n", a(i, 2));

    return 0;
}

int a(int n, int sum)
{
    if (n <= 1)
        return sum;
    else
        return a(n - 1, sum + 3);
}
