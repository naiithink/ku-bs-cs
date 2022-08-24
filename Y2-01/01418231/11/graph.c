/**
 * Lecture 11 -- Graph
 * 
 * Potsawat Thinkanwatthana
 * 6410451199
 */

#include <stdio.h>

#define START_NODE_NUM 1
#define INDEX_OF(X) (X - START_NODE_NUM)

#define NODE_DNE 0
#define NODE_EXIST 1

#define NODES 5

int main(void)
{
    int graph[NODES][NODES] = { 0 };

    graph[INDEX_OF(1)][INDEX_OF(2)] = NODE_EXIST;
    graph[INDEX_OF(1)][INDEX_OF(4)] = NODE_EXIST;
    graph[INDEX_OF(2)][INDEX_OF(5)] = NODE_EXIST;
    graph[INDEX_OF(3)][INDEX_OF(1)] = NODE_EXIST;
    graph[INDEX_OF(3)][INDEX_OF(4)] = NODE_EXIST;
    graph[INDEX_OF(4)][INDEX_OF(5)] = NODE_EXIST;

    printf("   ");
    for (int i = 0; i < NODES; ++i)
        printf("%d ", i + START_NODE_NUM);
    printf("\n\n");

    for (int i = 0; i < NODES; ++i)
    {
        printf("%d  ", i + START_NODE_NUM);
        for (int j = 0; j < NODES; ++j)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
