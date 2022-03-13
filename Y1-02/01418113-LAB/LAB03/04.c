#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibo(int n)
{
    int x = ( (pow((1 + sqrt(5)), n)) - (pow((1 - sqrt(5)), n)) ) / (pow(2, n) * (sqrt(5)));
    return x;
}

void main()
{
    char input_n[5];
    int n;

    fgets(input_n, 5, stdin);
    n = atoi(input_n);

    for (int i = 0; i < n+1; i++)
    {
        printf("F(%d) = %d\n", i, fibo(i));
    }
}