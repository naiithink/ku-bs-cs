#include <stdio.h>

#define LEN 5

int main(void)
{
    char *s1 = NULL;
    int ns[LEN] = { 0, 1, 2, 3, 4 };
    char *s2 = NULL;

    ns[16];

    for (int i = 0; i < 16; i++)
        printf("%d\n", ns[i]);

    return 0;
}
