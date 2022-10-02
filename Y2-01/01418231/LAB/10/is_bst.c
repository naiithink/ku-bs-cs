#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 4

#define IS_BIN_TREE     "A binary search tree, this is."
#define INVALID_TREE    "This tree is illegal."
#define ROOT_TREE       "This tree is lonely, give them a hug."
#define DUP_NODE        "Not what I am looking for, I am afraid."

typedef struct node
{
    int value;
    struct node *parent;
    struct node *left_c;
    struct node *right_c;
}
node;

node *new_node(const int);

/*
 * 0: inserts to the left
 * 1: inserts to the right
 */
int insert_node(const int, node *, const int);

node *find_node(node *, const int);

static node *root;

static int error_level;

int main(void)
{
    node *tmp_node;

    int in1 = 0;
    int in2 = 0;
    char in3[STR_LEN] = "";

    int last_returned = 0;

    do
    {
        scanf("%d", &in1);
        fflush(stdin);
    }
    while (!in1);

    root = new_node(in1);

    scanf("%d %d %s", &in1, &in2, in3);

    if (!in1
        && !in2
        && !strncmp(in3, "end", STR_LEN))
    {
        printf("%s\n", ROOT_TREE);

        return 0;
    }
    else
    {
        tmp_node = new_node(in2);

        last_returned = insert_node(in1, tmp_node, in3[0] == 'R');

        if (!error_level)
            error_level = last_returned;
    }

    while (in1
           && in2
           && strncmp(in3, "end", STR_LEN))
    {
        in1 = 0;
        in2 = 0;
        *in3 = '\0';

        scanf("%d %d %s", &in1, &in2, in3);

        tmp_node = new_node(in2);

        if (in1 == in2
            && !in1
            && !strncmp(in3, "end", STR_LEN))

            break;

        last_returned = insert_node(in1, tmp_node, in3[0] == 'R');

        if (!error_level)
            error_level = last_returned;
    }

    if (!error_level)
        printf("%s\n", IS_BIN_TREE);
    else if (error_level == 1)
        printf("%s\n", DUP_NODE);
    else
        printf("%s\n", INVALID_TREE);

    return 0;
}

node *new_node(const int val)
{
    node *res = malloc(sizeof *res);
    res->value = val;

    return res;
}

int insert_node(const int parent_val, node *child, const int child_position)
{
    if (child == NULL || child_position < 0 || child_position > 1)
        return 0;

    node *parent = find_node(root, parent_val);

    if (!child_position
        && parent->left_c == NULL
        && child->value < parent_val
        && (parent->right_c == NULL
            || parent->right_c->value > child->value))
    {
        parent->left_c = child;
        return 0;
    }
    else if (parent->right_c == NULL
            && child->value > parent_val
            && (parent->left_c == NULL
                || parent->left_c->value < child->value))
    {
        parent->right_c = child;
        return 0;
    }
    else if ((!child_position && parent->left_c != NULL)
             || (child_position && parent->right_c != NULL))
    {
        return 1;
    }

    return -1;
}

node *find_node(node *head, const int node_val)
{
    if (head == NULL || head->value == node_val)
        return head;

    if (head->value < node_val)
        return find_node(head->right_c, node_val);
    
    return find_node(head->left_c, node_val);
}
