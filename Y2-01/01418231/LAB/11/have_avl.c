#include <stdio.h>
#include <stdlib.h>

#define EMPTY       "empty tree"
#define HAVE        "This tree has AVL property"
#define DONT_HAVE   "This tree doesn't have AVL property"

typedef struct node
{
    int value;
    int height;
    struct node *parent;
    struct node *left;
    struct node *right;
}
node;

node *new_node(int);

int insert_node(node *, node *);

int check_avl(node *);

int main(void)
{
    int ok = 0;

    node *root = malloc(sizeof *root);
    int value = 0;

    root->height = 0;
    root->parent = NULL;

    scanf("%d", &value);
    root->value = value;

    while (value)
    {
        scanf("%d", &value);

        if (!value)
            break;
        else if (ok)
            continue;

        ok += insert_node(root, new_node(value));
    }

    if (!root->value)
        printf("%s\n", EMPTY);
    else if (!ok && check_avl(root))
        printf("%s\n", HAVE);
    else
        printf("%s\n", DONT_HAVE);

    return 0;
}

node *new_node(int val)
{
    node *res = malloc(sizeof *res);

    res->value = val;

    return res;
}

int insert_node(node *root, node *child)
{
    if (child == NULL || !child->value || child->value == root->value)
        return 1;

    if (child->value > root->value && root->right != NULL)
    {
        // root->right->height++;
        return insert_node(root->right, child);
    }
    else if (child->value < root->value && root->left != NULL)
    {
        // root->left->height++;
        return insert_node(root->left, child);
    }

    if (child->value > root->value)
        root->right = child;
    else
        root->left = child;

    child->parent = root;

    node *head = root;
    while (head->parent != NULL)
    {
        if (head->height + 1 < head->parent->height)
            break;

        head->height++;
        head = head->parent;
    }

    return 0;
}

int check_avl(node *node)
{
    if (node == NULL)
        return 1;

    int diff = 0;
    int left_height = 0;
    int right_height = 0;

    if (node->left == NULL)
        left_height = 0;
    else
        left_height = node->left->height;

    if (node->right == NULL)
        right_height = 0;
    else
        right_height = node->right->height;

    diff = left_height - right_height;

    if (diff < -1 || diff > 1)
        return 0;

    check_avl(node->left);
    check_avl(node->right);

    return 1;
}
