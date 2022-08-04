#include <stdio.h>

#define N 3

int Ack(int, int);

int main(void)
{
    for (int i = 1; i <= N; i++)
        printf("%d\n", Ack(2, i));

    return 0;
}

int Ack(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return Ack(m - 1, 1);
    else if (m > 0 && n > 0)
        return Ack(m - 1, Ack(m, n - 1));
}
