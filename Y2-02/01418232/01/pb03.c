#include <stdio.h>

#define STR_LEN 255

int strlen_t(char *);

char *skip_spaces(char *);

void print_dups(char *, char *);

int main(void)
{
    char n[STR_LEN];
    char m[STR_LEN];

    scanf("%[^\n]%*c", n);
    scanf("%[^\n]%*c", m);

    int n_len = strlen_t(n);
    int m_len = strlen_t(m);

    if (n_len < m_len)
        print_dups(n, m);
    else
        print_dups(m, n);

    return 0;
}

int strlen_t(char *s)
{
    int res = 0;

    while (*s++ != '\0')
        res++;

    return res;
}

char *skip_spaces(char *str)
{
    char *s = str;

    while (*s == ' ')
        s++;

    return s;
}

void print_dups(char *s_low, char *s_high)
{
    if (!*s_low || !*s_high)
    {
        // printf("\n");
        return;
    }

    if (*s_low == *s_high)
    {
        printf("%c ", *s_low);
        s_low++;
        s_high++;
    }
    else if (*s_low > *s_high)
        s_high++;
    else if (*s_low < *s_high)
        s_low++;
    else
        printf("unknown condition\n");

    print_dups(skip_spaces(s_low), skip_spaces(s_high));
}
