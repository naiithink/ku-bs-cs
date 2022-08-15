#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

typedef struct list
{
    int length;
    node *head;
} list;

node *newNode();
void initList(list **);
void insertEnd(list *, node *);
void printHeadList(list);

int main(void)
{
    list *NL;
    node *N;

    initList(&NL);

    for (int i = 0; i < 3; ++i)
    {
        N = newNode();
        N->num = i;

        insertEnd(NL, N);
    }

    printHeadList(*NL);

    return 0;
}

/**
 * Inserts node n to the end of list l.
 */
void insertEnd(list *l, node *n)
{
    if (l == NULL || n == NULL)
    {
        fprintf(stderr, "%s:%s:%d: invalid argument", __FILE__, __func__, __LINE__);
        exit(1);
    }

    if (l->head != NULL)
    {
        node *head = l->head;

        while (head->next != NULL)
            head = head->next;

        head->next = n;
        l->length++;
    }
    else
        l->head = n;
}

node *newNode()
{
    node *p;

    if ((p = malloc(sizeof *p)) == NULL)
        exit(1);

    p->next = NULL;

    return p;
}

void initList(list **n)
{
    *n = malloc(sizeof *n);
    (*n)->head = NULL;
    (*n)->length = 0;
}

void printHeadList(list l)
{
    node *pCurr = l.head;

    while (pCurr != NULL)
    {
        printf("Num: %d\n", pCurr->num);
        pCurr = pCurr->next;
    }
}
