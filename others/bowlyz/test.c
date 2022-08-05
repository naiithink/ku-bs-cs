/**
 * @file test.c
 * @author Potsawat Thinkanwatthana (potsawattkw@outlook.com)
 * @brief 
 * @version 0.0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * n = 4
 * lines = (n * 2) - 1
 * 
 * -
 * -X
 * -X-
 * -X-X
 * -X-
 * -X
 * -
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);

    int lines = (n * 2) - 1;

    int lim = 0;

    for (int row = 0; row < lines; row++)
    {
        if (row >= n)
            lim--;
        else
            lim = row + 1;

        for (int col = 0; col < lim; col++)
        {
            if (col % 2 == 0)
                printf("-");
            else
                printf("X");
        }
        printf("\n");
    }

    return 0;
}
