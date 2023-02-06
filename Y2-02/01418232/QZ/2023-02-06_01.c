#include <stdio.h>
#include <stdlib.h>

int fibo(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    return fibo(n - 1) + fibo(n - 2);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;

    int i = strtol(argv[1], NULL, 10);

    int n = fibo(i);

    printf("%i\n", n);

    return 0;
}
