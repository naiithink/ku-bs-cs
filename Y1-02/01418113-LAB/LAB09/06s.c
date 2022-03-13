#include <stdio.h>

int main()
{   unsigned char x;
    int n;

    printf("Enter an 8-bit number: ");
    scanf("%d", &n);
    x = (unsigned char)n;
    int numbits;
    numbits = 0;
    for (int i = 0; (i < 8) && (numbits += 1 & n >> i); i++);

    printf("The number %d has %d non-zero bits\n", x, numbits);
    return 0;
}