#include <stdio.h>

unsigned int strlen_t(char *);

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;

    for (int i = 1; i < argc; ++i)
    {
        printf("\
String: %s\n\
Length: %u\n", argv[i], strlen_t(argv[i]));
    }

    return 0;
}

unsigned int strlen_t(char *str)
{
    unsigned int res = 0;

    while (*str++ != '\0')
        res++;

    return res;
}
