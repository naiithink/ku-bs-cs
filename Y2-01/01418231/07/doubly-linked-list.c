#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
}
node;

void newNode(node **, node *);

int main(void)
{
    node *list = NULL;
    node *temp = NULL;

    node *first = NULL;
    node *second = NULL;

    if ((first = malloc(sizeof *first)) == NULL
        || (second = malloc(sizeof *second)) == NULL)
        return 1;

    first->next = NULL;
    first->prev = NULL;
    first->value = 3;

    second->next = NULL;
    second->prev = NULL;
    second->value = 5;

    newNode(&list, first);
    newNode(&list, second);

    temp = list;

    while (temp->next != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->prev;
    }

    return 0;
}

void newNode(node **list_head, node *new_node)
{
    if (new_node == NULL)
        return ;

    node **head = list_head;
    node *prev = NULL;

    while ((*head) != NULL)
    {
        prev = *head;
        head = &(*head)->next;
    }

    *head = new_node;
    (*head)->prev = prev;
}
