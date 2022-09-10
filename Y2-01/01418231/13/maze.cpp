/**
 *  0 A: (1)
 *  1 B: (2, 3)
 *  2 C: (4, 5)
 *  3 D: (6, 7, 8)
 *  4 E: ()
 *  5 F: (9, 10, 11)
 *  6 G: ()
 *  7 H: ()
 *  8 I: ()
 *  9 J: ()
 * 10 K: ()
 * 11 L: (12, 13)
 * 12 M: ()
 * 13 N: (14, 15, 16)
 * 14 O: ()
 * 15 P: ()
 * 16 Q: ()
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_NODES 17

int in_record(int **, int **);

int main(void)
{
    int *graph[NUMBER_OF_NODES][NUMBER_OF_NODES] = { NULL };
    int *visited[NUMBER_OF_NODES] = { NULL };
    int *(*queue)[NUMBER_OF_NODES] = NULL;
    int ***head = NULL;

    int *start = &graph[0];
    int *finish = &graph[16];

    graph[0][0] = &graph[1];

    graph[1][0] = &graph[2];
    graph[1][1] = &graph[3];

    graph[2][0] = &graph[4];
    graph[2][1] = &graph[5];

    graph[3][0] = &graph[4];
    graph[3][1] = &graph[4];
    graph[3][2] = &graph[4];

    // graph[4][0] = NULL;

    graph[5][0] = &graph[9];
    graph[5][1] = &graph[10];
    graph[5][2] = &graph[11];

    // graph[6][0] = NULL;
    // graph[7][0] = NULL;
    // graph[8][0] = NULL;
    // graph[9][0] = NULL;
    // graph[10][0] = NULL;

    graph[11][0] = &graph[12];
    graph[11][1] = &graph[13];

    // graph[12][0] = NULL;

    graph[13][0] = &graph[14];
    graph[13][1] = &graph[15];
    graph[13][2] = &graph[16];

    // graph[14][0] = NULL;
    // graph[15][0] = NULL;
    // graph[16][0] = NULL;

    for (int i = 0; i < NUMBER_OF_NODES; ++i)
    {
        printf("%p [%d]:\t", graph[i], i);
        for (int j = 0; j < NUMBER_OF_NODES; ++j)
                printf(" (%d) %p ", j, graph[i][j]);
        printf("\n");
    }

    for (int i = 0, vs = 0; i < NUMBER_OF_NODES; ++i, vs = 0)
    {
        queue = graph[i];

        for (int j = 0; j < NUMBER_OF_NODES; ++j)
        {
            head = queue[j];
            if (!in_record(queue[i], head))
                (*visited)[vs++] = head;

            // printf(" (%d) %p ", j, graph[i][j]);
            if (graph[i][j] == finish)
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}

int in_record(int **record, int **node)
{
    if (record == NULL)
        return 0;

    for (int i = 0; record[i] != NULL; ++i)
        if (record[i] == node)
            return 1;

    return 0;
}
