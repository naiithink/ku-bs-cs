#include <stdio.h>
#include <stdlib.h>

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

void pre_order(node *);

void inorder(node *);

void post_order(node *);

int main(void)
{
    node *root = malloc(sizeof *root);
    int value = 0;

    root->height = 0;
    root->parent = NULL;

    scanf("%d", &value);
    if (!value)
    {
        printf("What is emptier, my heart or this tree?\n");
        return 0;
    }

    root->value = value;

    while (value)
    {
        scanf("%d", &value);

        if (!value)
            break;

        insert_node(root, new_node(value));
    }

    printf("Height: ");
    if (root->left == NULL && root->right == NULL)
        printf("0\n");
    else if (root->left != NULL && root->right != NULL)
        printf("%d\n", 1 + (root->left->height > root->right->height ? root->left->height
                                                                     : root->right->height));
    else if (root->left != NULL)
        printf("%d\n", root->left->height + 1);
    else
        printf("%d\n", root->right->height + 1);

    printf("Preorder:");
    pre_order(root);
    printf("\nInorder:");
    inorder(root);
    printf("\nPostorder:");
    post_order(root);
    printf("\n");

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
        return insert_node(root->right, child);
    }
    else if (child->value < root->value && root->left != NULL)
    {
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

void pre_order(node *node)
{
    if (node == NULL)
        return;

    printf(" %d", node->value);

    pre_order(node->left);

    pre_order(node->right);
}

void inorder(node *node)
{
    if (node == NULL)
        return;

    inorder(node->left);

    printf(" %d", node->value);

    inorder(node->right);
}

void post_order(node *node)
{
    if (node == NULL)
        return;

    post_order(node->left);

    post_order(node->right);

    printf(" %d", node->value);
}
