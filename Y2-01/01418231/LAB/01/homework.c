#include <stdio.h>
#include <stdlib.h>

#define TABLE_MAX 40
#define TABLE_MIN 1
#define TABLE_PER_ROW 6
#define MAP_START_ROW 1
#define MAP_START_COL 1
#define RESERVED 1
#define DNE -1
#define SYM_RESERVED "S"
#define SYM_FREE "X"

void validateNum(int);

int main(void)
{
    int tables = 0;
    int reserved_seats = 0;
    int rows = 0;
    int dne_seats = 0;

    int out_of_range_i = 0;
    int out_of_range_j = 0;
    int out_of_range[TABLE_MAX][2];

    scanf("%d", &tables);
    validateNum(tables);

    scanf("%d", &reserved_seats);
    validateNum(reserved_seats);

    if ((rows = tables / TABLE_PER_ROW) == 0)
        rows = 1;

    if ((dne_seats = reserved_seats % TABLE_PER_ROW) > 0)
        rows++;

    dne_seats = reserved_seats % TABLE_PER_ROW;

    int seat_map[rows][TABLE_PER_ROW];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < TABLE_PER_ROW; j++)
            seat_map[i][j] = 0;

    for (int i = rows - MAP_START_ROW, j = dne_seats - MAP_START_COL; j < TABLE_PER_ROW; j++)
        seat_map[i][j] = DNE;

    for (int i = 0, checked_out = 0, ii = 0, jj = 0; checked_out < reserved_seats && i < rows; i++)
        for (int j = 0; checked_out < reserved_seats && j < TABLE_PER_ROW; j++)
        {
            scanf("%d %d", &ii, &jj);

            ii = ii - MAP_START_ROW;
            jj = jj - MAP_START_COL;

            if (seat_map[ii][jj] == 1)
                continue;

            if (seat_map[ii][jj] != 0
                || ii >= rows || ii < 0
                || seat_map[ii][jj] == DNE || jj >= TABLE_PER_ROW || jj < 0)
            {
                fprintf(stderr, "%d %d Out of range!\n", ii + MAP_START_ROW, jj + MAP_START_COL);
                continue;
            }

            seat_map[ii][jj] = RESERVED;
            checked_out++;
        }

    // out_of_range[out_of_range_i][out_of_range_j] = DNE;
    // 
    // for (int i = 0, stop = 0; !stop && i < TABLE_MAX; i++)
    //     for (int j = 0, to_print = 0; !stop && j < 2; j++, to_print = 0)
    //     {
    //         if ((to_print = out_of_range[i][j]) == DNE)
    //         {
    //             stop = 1;
    //             continue;
    //         }
    //         
    //         if (i % 2)
    //             fprintf(stderr, "%d Out of range!\n", to_print);
    //         else
    //             fprintf(stderr, "%d ", to_print);
    //     }

    for (int i = 0, stop = 0; !stop && i < rows; i++)
    {
        for (int j = 0; !stop && j < TABLE_PER_ROW; j++)
            if (seat_map[i][j] == DNE)
                stop = 1;
            else if (!seat_map[i][j])
                printf("%s", SYM_FREE);
            else
                printf("%s", SYM_RESERVED);
        printf("\n");
    }

    return 0;
}

void validateNum(int num)
{
    if (num < TABLE_MIN || num > TABLE_MAX)
    {
        fprintf(stderr, "Error");

        if (num < TABLE_MIN)
        {
            fprintf(stderr, "\n");
            // exit(1);
            exit(0);
        }
        else
        {
            fprintf(stderr, "!\n");
            // exit(1);
            exit(0);
        }
    }
}
