#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 10

int main(void)
{
    char n_s[STR_SIZE], char_1 = '-', char_2 = 'x';
    int n = 0;

    printf("Enter n: ");
    fgets(n_s, STR_SIZE, stdin);
    if ((n = atoi(n_s)) <= 0)
        return 1;

    int ctl = 1, rows = 2 * n - 1, rowlim = 0;
    for (int row = 0; row < rows; row++)
    {
        if (row >= n)
            rowlim -= 1;
        else
            rowlim = row;
        for (int col = 0; col < rowlim; col++)
        {
            if (!(col % 2))
                printf("%c", char_1);
            else
                printf("%c", char_2);
        }
        printf("\n");
    }

    return 0;
}