#include <stdio.h>

#define L_BOUND 1
#define U_BOUND 40
#define TABLE_STACK 6
#define DNE 0

int main(void)
{
    int tables = 0;
    int reserved_seats = 0;
    int row = 0;
    int seating_map[U_BOUND][TABLE_STACK] = { DNE };

    scanf("%d", &tables);

    if (reserved_seats < L_BOUND || reserved_seats > U_BOUND)
    {
        fprintf(stderr, "Error");

        if (reserved_seats > U_BOUND)
            printf("!\n");
        else
            printf("\n");

        return 1;
    }

    scanf("%d", &reserved_seats);

    if (reserved_seats < L_BOUND || reserved_seats > U_BOUND)
    {
        fprintf(stderr, "Error");

        if (reserved_seats > U_BOUND)
            printf("!\n");
        else
            printf("\n");

        return 1;
    }

    for (int i = 0, n = 0, sigbreak = 0; i < reserved_seats && !sigbreak; ++i)
        for (int j = 0; j < TABLE_STACK; ++j)
        {
            if (n >= reserved_seats)
            {
                sigbreak = 1;
                break;
            }

            seating_map[i][j] = 0;
            n++;
        }

    for (int i = 0, a = 0, b = 0; i < reserved_seats; ++i, a = 0, b = 0)
    {
        scanf("%d %d", &a, &b);
        seating_map[a][b] = 1;
    }

    for (int i = 0; i < TABLE_STACK; ++i)
        for (int j = 0; j < TABLE_STACK; ++j)
            

    return 0;
}
