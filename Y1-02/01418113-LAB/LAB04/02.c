#include <stdio.h>
#include <stdlib.h>

/**/
int is_prime(int x)
{
    for (int i = x-1; i > 1; i--)
    {
        if (!(x % i))
        {
            return 0;
        }
    }
    return 1;
}
/**/

int main(void)
{
    char input[5];
    fgets(input, 5, stdin);

    int i, n;

    n = atoi(input);

    for ( /**/ i = 2; i < n+1; i++ /**/ )
    {
        if (is_prime(i))
        {
            printf("%d is a prime number.\n", i);
        }
    }

    return 0;
}