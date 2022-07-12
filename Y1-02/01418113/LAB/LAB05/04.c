#include <stdio.h>
#include <stdlib.h>

#define STR_IN_SIZE 12

int main(void)
{
    char n_str[STR_IN_SIZE];
    int n = 0, flow = 1;

    printf("Enter n: ");
    fgets(n_str, STR_IN_SIZE, stdin);
    n = atoi(n_str);
    if (n < 1)
        return 1;

    for (int line = 0; line > -1; line += flow)
    {
        if (line >= n)
            flow = -1;
        for (int i = 0; i < line; i++)
        {
            if (!(i % 2))
                printf("-");
            else
                printf("x");
        }
        if (line > 0)
            printf("\n");
    }

    return 0;
}