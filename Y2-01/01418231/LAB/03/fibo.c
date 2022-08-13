#include <stdio.h>

int main(void)
{
    unsigned long n = 0;

    unsigned long i = 0;
    unsigned long j = 1;
    unsigned long t = 0;

    scanf("%lu", &n);

    for (int loop = 0; loop < n; loop++)
    {
        printf("%lu\n", i);
        t = j;
        j = i + j;
        i = t;
    }

    return 0;
}
