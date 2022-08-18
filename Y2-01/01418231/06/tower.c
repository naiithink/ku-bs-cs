#include <stdio.h>

void move(int, char, char, char);

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;

    int n = argv[1][0] - '0';
    move(n, 'A', 'B', 'C');

    return 0;
}

void move(int n, char from, char aux, char to)
{
    if (n == 0)
        return;

    move(n - 1, from, to, aux);

    printf("move disk %d from %c to %c\n", n, from, to);

    move(n - 1, to, aux, from);
}
