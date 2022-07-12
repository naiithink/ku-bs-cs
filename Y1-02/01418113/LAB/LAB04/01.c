#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char dec_str[3];
    int dec, prt, bit[4];

    fgets(dec_str, sizeof(dec_str), stdin);
    dec = atoi(dec_str);
    prt = dec;

    int i = 3;
    while (i > -1)
    {
        bit[i] = dec & 1;
        dec = dec>>1;
        i--;
    }

    printf("Binary number of %i is %i%i%i%i.\n", prt, bit[0], bit[1], bit[2], bit[3]);

    return EXIT_SUCCESS;
}