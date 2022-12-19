/**
 * 01418232, LAB01, The Beginning
 * 
 * Potsawat Thinkanwatthana
 * 6410451199
 */

#include <stdio.h>
#include <stdlib.h>

int proper_gcd(int, int);

int main(void /* int argc, char **argv */)
{
    int res = 0;
    int n; // (int) strtol(argv[1], NULL, 10);
    int m; // (int) strtol(argv[2], NULL, 10);

    scanf("%d %d", &n, &m);

    if (n < 1 || m > 10000)
        // return 1;
        exit(0);
    else if (n == m || (n * m) == 0)
    {
        printf("%d\n", n == m   ? n
                                : !n    ? m
                                        : n);

        return 0;
    }

    res = n > m     ? proper_gcd(n, m)
                    : proper_gcd(m, n);

    printf("%d\n", res);

    return 0;
}

int proper_gcd(int n, int m)
{
    if (m == 0)
        return n;

    return proper_gcd(m, n % m);
}
