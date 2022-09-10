#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int visited;
    struct node *next;
}
node;

static int gotcha;

int main(void)
{
    int nodes = 0;
    int edges = 0;

    scanf("%d", &nodes);
    scanf("%d", &edges);

    if (nodes < 0
        || edges < 0
        || edges > nodes)
        return 0;

    node *entries[nodes];
    node *head = NULL;

    for (int i = 0; i < nodes; ++i)
    {
        entries[i] = malloc(sizeof entries[i]);
        entries[i]->next = NULL;
    }

    {
        int i = edges;
        int u = 0;
        int v = 0;

        while (i)
        {
            head = NULL;
            scanf("%d %d", &u, &v);

            if (u < 0
                || u > nodes
                || v < 0
                || v > nodes)
                continue;
            else if (u == v)
                gotcha = 1;

            head = entries[u];

            while (head->next != NULL)
                head = head->next;

            head->next = entries[v];
            i--;
        }
    }

    if (!gotcha)
    {
        head = entries[0];

        for (int visited = 0; visited < nodes && !gotcha; ++visited)
        {
            head->visited = 1;
            head = head->next;

            if (head->visited)
                gotcha = 1;
        }
    }

    if (gotcha)
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    return 0;
}
