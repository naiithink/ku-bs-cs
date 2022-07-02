#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 32
#define DEC_MAX 2147483647

int main(void)
{
    long dec_max = 1;

    for (int i = 0, exp = CHAR_MAX - 1; i < exp; ++i)
        dec_max *= 2;
    dec_max++;

    printf("%ld\n", dec_max);

    unsigned int decimal_in = 0;
    unsigned int char_index = 0;
    int result_string_lenth = 0;
    char binary_out[CHAR_MAX];

    for (int i = 0; i < CHAR_MAX; ++i)
        binary_out[i] = '\0';

    printf("Decimal in: ");
    scanf("%d", &decimal_in);

    if (decimal_in < 0)
    {
        fprintf(stderr, "Error: Cannot convert negative numbers.\n");
        return 1;
    }
    else if (decimal_in > DEC_MAX)
    {
        fprintf(stderr, "Error: Number too large (%d max).\n", DEC_MAX);
        return 1;
    }
    else if (decimal_in == 0)
    {
        printf("Binary out: %d\n", 0);
        return 0;
    }

    while (decimal_in > 0)
    {
        if (decimal_in & 1)
            binary_out[char_index] = '1';
        else
            binary_out[char_index] = '0';
        decimal_in >>= 1;
        char_index++;
    }

    for (; binary_out[result_string_lenth] != '\0'; ++result_string_lenth);

    printf("Binary out: ");
    for (; result_string_lenth > -1; --result_string_lenth)
        printf("%c", binary_out[result_string_lenth]);
    printf(" (unsigned)\n");

    return 0;
}
