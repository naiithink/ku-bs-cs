#include <stdio.h>
#include <stdlib.h>

#define HELP_MSG "\
This program requires one argument.\n\
Try ./td_fibo 10"

int fibo(int (*cache_p)[], int n)
{
    if (n <= 1)
        return n;

    if ((*cache_p)[n] != 0)
        return (*cache_p)[n];

    return fibo(cache_p, n - 1) + fibo(cache_p, n - 2);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        fprintf(stderr, "%s\n", HELP_MSG);
        return 1;
    }

    int i = strtol(argv[1], NULL, 10);

    int (*cache)[] = calloc(i, sizeof(int));

    int n = fibo(cache, i);

    printf("%i\n", n);

    free(cache);
    return 0;
}
