#include <stdio.h>

struct person {
    int id;
    float height;
    char name[15];
    double weight;
};

int main(void)
{
    int size = sizeof(struct person);
    printf("%d\n", size);

    return 0;
}