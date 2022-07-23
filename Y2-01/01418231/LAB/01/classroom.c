#include <stdio.h>
#include <stdlib.h>

#define TABLE_MAX 40
#define TABLE_MIN 1
#define TABLE_PER_ROW 6
#define MAP_START_ROW 1
#define MAP_START_COL 1
#define DNE -1
#define FREE 0
#define RESERVED 1
#define SYM_FREE 'X'
#define SYM_RESERVED 'S'

int main(void)
{
    int tables = 0;
    int reserved_seats = 0;
    int rows = 0;
    int dne_seats = 0;

    scanf("%d", &tables);
    if (tables < TABLE_MIN || tables > TABLE_MAX)
    {
        /* fprintf(stderr, "Error"); */
        printf("Error");
        if (tables < TABLE_MIN)
        {
            /* fprintf(stderr, "\n"); */
            printf("\n");
        }
        else
        {
            /* fprintf(stderr, "!\n"); */
            printf("!\n");
        }

        /* exit(1); */
        exit(0);
    }

    scanf("%d", &reserved_seats);
    if (reserved_seats < 0 || reserved_seats > tables)
    {
        printf("Error");
        if (tables < TABLE_MIN)
        {
            /* fprintf(stderr, "\n"); */
            printf("\n");
        }
        else
        {
            /* fprintf(stderr, "!\n"); */
            printf("!\n");
        }

        /* exit(1); */
        exit(0);
    }

    rows = tables / TABLE_PER_ROW;

    if ((dne_seats = tables % TABLE_PER_ROW) > 0)
        rows++;

    int table_map[rows][TABLE_PER_ROW];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < TABLE_PER_ROW; j++)
            if (dne_seats > 0
                && i == (rows - MAP_START_ROW)
                && j >= dne_seats)
                table_map[i][j] = DNE;
            else
                table_map[i][j] = FREE;

    {
        int checkout = reserved_seats;

        while (checkout)
        {
            int ii = DNE;
            int jj = DNE;

            scanf("%d %d", &ii, &jj);

            ii = ii - MAP_START_ROW;
            jj = jj - MAP_START_COL;

            if (table_map[ii][jj] == DNE
                || ii + MAP_START_ROW < MAP_START_ROW || ii + MAP_START_ROW > rows
                || jj + MAP_START_COL < MAP_START_COL || jj + MAP_START_COL > TABLE_PER_ROW)
            {
                /* fprintf(stderr, "%d %d Out of range!\n", ii + MAP_START_ROW, jj + MAP_START_COL); */
                printf("%d %d Out of range!\n", ii + MAP_START_ROW, jj + MAP_START_COL);
                continue;
            }
            else if (table_map[ii][jj] == RESERVED)
                continue;

            table_map[ii][jj] = RESERVED;

            checkout--;
        }
    }

    for (int i = 0, stop = 0; !stop && i < rows; i++)
    {
        for (int j = 0; j < TABLE_PER_ROW; j++)
        {
            if (table_map[i][j] == DNE)
            {
                stop = 1;
                break;
            }

            if (table_map[i][j] == FREE)
                printf("%c ", SYM_FREE);
            else
                printf("%c ", SYM_RESERVED);
        }
        printf("\n");
    }

    return 0;
}
