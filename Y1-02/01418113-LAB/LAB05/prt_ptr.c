#include <stdio.h>

typedef struct binary_pointer
{
    int ptr_f;
    binary_pointer *ptr_l;
}
binary_pointer;


int main(void)
{
    int *p1, *p2;
    long int pp = 0;

    char c = 'a';
    pp = (char *) &c;

    printf("0x%x - %li\n", pp, pp);
    puts("---");

    if (pp % 2)
        p1 = pp / 2 + 1;
    else
        p1 = pp / 2;
    // p2 = pp - p1;
    printf("0x%x: %i\n", &p1, p1);

    return 0;
}