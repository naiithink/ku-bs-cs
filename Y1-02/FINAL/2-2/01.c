/**
 * 1->1% ข้อ 1 (1%)
 * passed 100
 */

#include <stdio.h>

int main(void)
{
    int n = 0, m = 0, c = 0, d = 0;

    scanf ("%d %d %d %d", &n, &m, &c, &d);

    for (int i = m, lim = n - 1; i > lim; --i)
    {
        if (i % d && !(i % c))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}