#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char n_str[10];
    int n;
    
    fgets(n_str, 10, stdin);
    n = atoi(n_str);

    for (int i = n; i > -1; i--)
    {
        printf("%i\n", i);
    }

    return 0;
}