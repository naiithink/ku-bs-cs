#include <stdio.h>
#include <stdlib.h>

#define TABLE_MAX 40
#define TABLE_MIN 1
#define TABLE_PER_ROW 6
#define MAP_START_ROW 1
#define MAP_START_COL 1
#define RESERVED 1
#define DNE -1
#define SYM_RESERVED 'S'
#define SYM_FREE 'X'

void validateNum(int, int, int, int);

int main(void)
{
    int tables = 0;
    int reserved_seats = 0;
    int rows = 0;
    int dne_seats = 0;

    scanf("%d", &tables);
    validateNum(tables, TABLE_MIN, TABLE_MAX, 1);

    scanf("%d", &reserved_seats);
    validateNum(reserved_seats, TABLE_MIN - 1, tables, 0);

    if ((rows = tables / TABLE_PER_ROW) == 0)
        rows = 1;

    if ((dne_seats = reserved_seats % TABLE_PER_ROW) > 0 && tables > TABLE_PER_ROW)
        rows++;

    dne_seats = tables % TABLE_PER_ROW;

    int seat_map[rows][TABLE_PER_ROW];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < TABLE_PER_ROW; j++)
            seat_map[i][j] = 0;

    for (int i = rows - MAP_START_ROW, j = dne_seats; j < TABLE_PER_ROW; j++)
        seat_map[i][j] = DNE;

    for (int i = 0, checked_out = 0, ii = 0, jj = 0; checked_out < reserved_seats && i < rows; i++)
        for (int j = 0; checked_out < reserved_seats && j < TABLE_PER_ROW; j++)
        {
            scanf("%d %d", &ii, &jj);

            ii = ii - MAP_START_ROW;
            jj = jj - MAP_START_COL;

            if (ii >= rows || (ii + MAP_START_ROW) < MAP_START_ROW
                || seat_map[ii][jj] == DNE || jj >= TABLE_PER_COL || (jj + MAP_START_COL) < MAP_START_COL)
            {
                fprintf(stderr, "%d %d Out of range!\n", ii + MAP_START_ROW, jj + MAP_START_COL);
                continue;
            }

            if (seat_map[ii][jj] == RESERVED)
                continue;

            seat_map[ii][jj] = RESERVED;
            checked_out++;
        }

    for (int i = 0, stop = 0; !stop && i < rows; i++)
    {
        for (int j = 0; !stop && j < TABLE_PER_ROW; j++)
        {
            if (seat_map[i][j] == DNE)
                stop = 1;

            if (seat_map[i][j] == RESERVED)
                printf("%c", SYM_RESERVED);
            else
                printf("%c", SYM_FREE);
        }
        printf("\n");
    }

    return 0;
}

void validateNum(int num, int min, int max, int write_errmsg)
{
    if (num < min || num > max)
    {
        if (write_errmsg)
        {
            fprintf(stderr, "Error");
            if (num < TABLE_MIN)
                fprintf(stderr, "\n");
            else
                fprintf(stderr, "!\n");
        }

        /* exit(1); */
        exit(0);
    }
}
