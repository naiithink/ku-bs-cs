/**
 * 01418232, LAB01, Continue
 * 
 * Potsawat Thinkanwatthana
 * 6410451199
 */

/**
 * Integral square root of an integer
 * 
 * 
 * x, y are non-neg ints
 * 
 * floor(isqrt(y)) = (x + 1) ** 2 > y
 * 
 * 
 * Converging L and R bounds
 * 
 * L ------- M ------- R
 *           L -- M -- R            for M^2 <= y
 *           L -- R                 for M^2 > y
 */

#include <stdio.h>
// #include <stdlib.h>

int isqrt(int);

int main(int argc, char **argv)
{
    int res = 0;
    int n; // = (int) strtol(argv[1], NULL, 10);

    scanf("%d", &n);

    if (n == 1)
    {
        printf("%d\n", n);
        return 0;
    }
    else if (n < 1 || n > 5000)
        // return 1;
        exit(0);

    printf("%d\n", isqrt(n));

    return 0;
}

int isqrt(int n)
{
    int l = 0;
    int m = 0;
    int r = n + 1;

    while (r - 1 != l)
    {
        m = (l + r) / 2;

        if (m * m <= n)
            l = m;
        else
            r = m;
    }

    return l;
}
