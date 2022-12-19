/**
 * 01418232, LAB01, The End (of The Beginning)
 * 
 * Potsawat Thinkanwatthana
 * 6410451199
 */

#include <stdio.h>

#define ARR_LEN 255

void dup(char *, char *, int **);

int strlen(char *);

int main(int argc, char **argv)
{
    void *res;

    char n[255];
    char m[255];

    scanf("%s", n);
    scanf("%s", m);

    int ln = strlen(n);
    int lm = strlen(m);

    printf("%d, %d\n", ln, lm);

    if (ln * lm == 0)
        return 0;
    else if (ln > lm)
    {
        int ires[ln] = { 0 };
        res = ires;
        dup(n, m, res);
    }
    else
    {
        int ires[lm] = { 0 };
        res = ires;
        dup(m, n, res);
    }

    int eiei[] = res;

    for (int i = 0, c = 0; c < lm; i++)
        printf("%d\n", eiei[i]);

    return 0;
}

int strlen(char *s)
{
    int res = 0;

    while (*s++ != '\0')
        res++;

    return res;
}

void dup(char *n, char *m, int **res)
{
    if (*n == '\0')
        ;
}
