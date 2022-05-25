#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char n_str[3];
    int n;

    fgets(n_str, 3, stdin);
    n = atoi(n_str);

    if (n > 26 || n <= 0)
    {
        printf("-\n");
        return 1;
    }

    int i = n, loop = 0, switcher = -1;

    while (1)
    {
        printf("%c", i+96);

        if (i == 1)
        {
            if (n == 1)
            {
                printf("\n");
                break;
            }
            switcher *= -1;
            loop++;
        }
        else if (loop == 1 && i == n)
        {
            printf("\n");
            break;
        }

        printf("-");
        i += switcher;
    }

    return 0;
}


