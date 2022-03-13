#include <stdio.h>
#include <stdlib.h>

static int s, p;

void print_bin(int n)
{
    if (!p && !n)
    {
        printf("0\n");
        return;
    }
    else if (!p)
    {
        n <<= 1;
        n++;
        p++;
    }
    else if (n)
    {
        s += n & 1;
        if (n >>= 1)
            s <<= 1;
    }
    else if (s > 1)
    {
        printf("%i", s&1);
        s >>= 1;
    }
    else
    {
        printf("\n");
        return;
    }
    return print_bin(n);
}

int main(void)
{
    char n_str[10];
    fgets(n_str, sizeof(n_str), stdin);
    print_bin(atoi(n_str));

    return 0;
}