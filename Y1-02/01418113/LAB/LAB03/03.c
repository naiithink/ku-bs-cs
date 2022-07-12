#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y) {

    int i = 0;
    int gcd = 0;

    for(i=1; i <= x && i <= y; ++i)
    {
        if(x%i==0 && y%i==0)
            gcd = i;
    }

    return gcd;
}

int main(void)
{
    char div_str[6], dim_str[6], sep;
    int div, dim, res_dim, res_div, gcd;

    fgets(div_str, 12, stdin);
    fgets(dim_str, 12, stdin);

    div = atoi(div_str);
    dim = atoi(dim_str);

    if (dim == 0)
    {
        return 1;
    }

    gcd = GCD(div, dim);

    if (gcd)
    {
        res_div = div / gcd;
        res_dim = dim / gcd;
    }

    printf("= %i", res_div);

    if (res_dim != 1)
    {
        printf("/%i", res_dim);
    }
    printf("\n");

    return 0;
}