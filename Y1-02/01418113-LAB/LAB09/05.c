#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

void printList(node *pList) {
    node *temp = pList;
    while (temp->next != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("%d\n", temp->value);
}

node *insertNode(node *pList, int value) {
    node *temp = pList;
    int done = 0;
    int insert = 0;
    int len = 0;

    if (temp == NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->value = value;
        temp->next = NULL;
        return pList = temp;
    }
    len = 1;

    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }

    temp->next = (node *)malloc(sizeof(node));
    temp = temp->next;
    temp->value = 0;
    temp->next = NULL;
    len++;

    temp = pList;

    for (int i = 0, lim = len * 2; i < lim && !done; i += 2)
    {
        if (value < temp[i].value)
            insert = 1;
        else if ((value >= temp[i].value && value < temp[i+2].value) || temp[i+2].next == NULL)
        {
            i += 2;
            insert = 1;
        }

        if (insert)
        {
            for (int j = (len - 1) * 2; j > i; j -= 2)
            {
                temp[j].value = temp[j-2].value;
                temp[j-2].value = 0;
            }
            temp[i].value = value;
            done = 1;
        }
    }
    
    return pList;
}

int main() {
    int i, value;
    node *pList=NULL;

    for (i = 0; i < 5; i++) {
        scanf(" %d", &value);
        pList = insertNode(pList, value);
    }

    printList(pList);
}