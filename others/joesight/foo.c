#include <stdio.h>

void addOne(int *n1);

int main(void)
{
    int n = 10;

    addOne(&n);

    printf("n = %d\n", n);

    // & ref        address of
    // * deref      go to that address

    return 0;
}

void addOne(int *n1)
{
    *n1 += 1;
}