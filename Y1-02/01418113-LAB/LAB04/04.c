#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char sym_chr = '*', cols_str[5], rows_str[5];
    int cols = 0, rows = 0;

    fgets(cols_str, sizeof(cols_str), stdin);
    fgets(rows_str, sizeof(rows_str), stdin);

    cols = atoi(cols_str);
    rows = atoi(rows_str);

    for (int j = 0; j < rows; j++)
    {
        for (int tab = 0; tab < j; tab++)
        {
            printf("%c", 32);
        }
        for (int i = 0; i < cols; i++)
        {
            if (j && i && j != rows-1 && i-(cols-1))
            {
                printf("%c", 32);
            }
            else
            {
                printf("%c", sym_chr);
            }
        }
        printf("\n");
    }
}