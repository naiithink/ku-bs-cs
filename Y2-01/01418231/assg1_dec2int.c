#include <stdio.h>

<<<<<<< HEAD
#define BIT_LEN (sizeof(int) * 8)
#define DEC_MAX (1 << (BIT_LEN - 1))

int main(void)
{
    int decimal_in = 0;
    int result_string_lenth = 0;
    int char_index = 0;
    char binary_out[BIT_LEN];

    for (int i = 0; i < BIT_LEN; ++i)
=======
#define STR_MAX 32
#define DEC_MAX 2147483647

int main(void)
{
    long dec_max = 1;

    for (int i = 0, exp = STR_MAX - 1; i < exp; ++i)
        dec_max *= 2;
    dec_max++;

    printf("%ld\n", dec_max);

    unsigned int decimal_in = 0;
    unsigned int char_index = 0;
    int result_string_lenth = 0;
    char binary_out[STR_MAX];

    for (int i = 0; i < STR_MAX; ++i)
>>>>>>> 00646508ddd623e8e5fd370aff4a68e390917371
        binary_out[i] = '\0';

    printf("Decimal in: ");
    scanf("%d", &decimal_in);

    if (decimal_in < 0 || decimal_in > (unsigned) DEC_MAX)
    {
        fprintf(stderr, "Error: Input must fall within [0, %u).\n", DEC_MAX);
        return 1;
    }

    do
    {
        if (decimal_in & 1)
            binary_out[char_index] = '1';
        else
            binary_out[char_index] = '0';
        decimal_in >>= 1;
        char_index++;
    }
    while (decimal_in > 0);

    for (; binary_out[result_string_lenth] != '\0'; ++result_string_lenth);

    printf("Binary out: ");
    for (; result_string_lenth > -1; --result_string_lenth)
        printf("%c", binary_out[result_string_lenth]);
    printf(" (unsigned)\n");

    return 0;
}
