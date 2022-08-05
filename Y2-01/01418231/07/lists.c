#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

int main(void)
{
    struct Node *head = NULL;

    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *last = NULL;

    if ((first = malloc(sizeof *first)) == NULL
        || (second = malloc(sizeof *second)) == NULL
        || (last = malloc(sizeof *last)) == NULL)
        return 1;
    else
        head = first;


    first->num = 1;
    first->next = second;

    second->num = 3;
    second->next = last;

    last->num = 5;

    do
        printf("%d\n", head->num);
    while ((head = head->next) != NULL);

    return 0;
}
