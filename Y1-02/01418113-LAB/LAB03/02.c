#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y) {

    int i = 0;
    int gcd = 0;

    for (i=1; i <= x && i <= y; ++i)
    {
        if(x%i==0 && y%i==0)
            gcd = i;
    }

    return gcd;
}

int main(void)
{
    char M_str[12], N_str[12];
    long long M, N, gcd, lcm;

    fgets(M_str, 12, stdin);
    fgets(N_str, 12, stdin);

    M = atoll(M_str);
    N = atoll(N_str);

    gcd = GCD(M, N);
    lcm = M * N / gcd;

    printf("GCD: %lli\nLCM: %lli\n", gcd, lcm);

    return 0;
}