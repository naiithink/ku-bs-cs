#include <stdio.h>

int main()
{   unsigned char x;
    int n;

    printf("Enter an 8-bit number: ");
    scanf("%d", &n);
    x = (unsigned char)n;
    int numbits;

    numbits = 0;
    numbits += 1 & n;
    numbits += 1 & n >> 1;
    numbits += 1 & n >> 2;
    numbits += 1 & n >> 3;
    numbits += 1 & n >> 4;
    numbits += 1 & n >> 5;
    numbits += 1 & n >> 6;
    numbits += 1 & n >> 7;

    printf("The number %d has %d non-zero bits\n", x, numbits);
    return 0;
}