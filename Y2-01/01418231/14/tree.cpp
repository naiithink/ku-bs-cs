#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node
{
    int size;
    struct node *parent;
    struct node *child1;
    struct node *child2;
    struct node *child3;
}
node;

node *create_node(int, node *);

void traverse_postorder(node *);

static int total;

int main(void)
{
    // Level 0
    node *lv0_0_user_rt_courses = create_node(1000, NULL);

    // Level 1
    node *lv1_0_cs016 = create_node(2000, lv0_0_user_rt_courses);

    node *lv1_1_cs252 = create_node(1000, lv0_0_user_rt_courses);

    // Level 2
    node *lv2_0_grades = create_node(8000, lv1_0_cs016);
    node *lv2_1_homeworks = create_node(1000, lv1_0_cs016);
    node *lv2_2_programs = create_node(1000, lv1_0_cs016);

    node *lv2_3_projects = create_node(1000, lv1_1_cs252);
    node *lv2_4_grades = create_node(3000, lv1_1_cs252);

    // Level 3
    node *lv3_0_hw1 = create_node(3000, lv2_1_homeworks);
    node *lv3_1_hw2 = create_node(2000, lv2_1_homeworks);
    node *lv3_2_hw3 = create_node(4000, lv2_1_homeworks);

    node *lv3_3_pr1 = create_node(57000, lv2_2_programs);
    node *lv3_4_pr2 = create_node(97000, lv2_2_programs);
    node *lv3_5_pr3 = create_node(74000, lv2_2_programs);

    node *lv3_6_papers = create_node(1000, lv2_3_projects);
    node *lv3_7_demos = create_node(1000, lv2_3_projects);

    // Level 4
    node *lv4_0_buylow = create_node(26000, lv3_6_papers);
    node *lv4_1_sellhigh = create_node(55000, lv3_6_papers);

    node *lv4_2_market = create_node(4786000, lv3_7_demos);

    traverse_postorder(lv0_0_user_rt_courses);

    cout << "Total: " << total << endl;

    return 0;
}

node *create_node(int size, node *parent)
{
    node *new_node = (node *) malloc(sizeof *new_node);

    new_node->size = size;
    new_node->parent = parent;
    new_node->child1 = NULL;
    new_node->child2 = NULL;
    new_node->child3 = NULL;

    if (parent == NULL)
        return new_node;

    if (parent->child1 == NULL)
        parent->child1 = new_node;
    else if (parent->child2 == NULL)
        parent->child2 = new_node;
    else if (parent->child3 == NULL)
        parent->child3 = new_node;

    return new_node;
}

void traverse_postorder(node *a_node)
{
    if (a_node == NULL)
        return ;

    traverse_postorder(a_node->child1);

    traverse_postorder(a_node->child2);

    traverse_postorder(a_node->child3);

    total += a_node->size;
}
