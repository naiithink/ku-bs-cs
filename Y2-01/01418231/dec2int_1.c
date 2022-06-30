/*
 * Homework 1: Decimal to Binary
 * 
 * Potsawat Thinkanwatthana
 * Student ID: 6410451199
 */

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 100

/* Signing flag */
static int is_signed;

int main(void)
{
    /* The `decimal_in' variable holds the input value to be converted */
    int decimal_in = 0;
    int char_index = 0;
    int result_string_lenth = 0;
    char binary_out[CHAR_MAX];

    /* Initializes `binary_out' char array to '\0' */
    for (int i = 0; i < CHAR_MAX; ++i)
        binary_out[i] = '\0';

    /* Gets an input */
    printf("Decimal in: ");
    scanf("%d", &decimal_in);

    /* Asserts that the input is negative; LSB signing bit */
    if (decimal_in < 0)
    {
        is_signed = 1;
        decimal_in *= -1;
    }

    /* Conversion */
    while (decimal_in > 0)
    {
        if (decimal_in & 1)
            binary_out[char_index] = '1';
        else
            binary_out[char_index] = '0';
        decimal_in >>= 1;
        char_index++;
    }

    /* Adds the sign bit */
    if (is_signed == 1)
    {
        char_index++;
        binary_out[char_index] = '1';
    }

    /* strlen: for printing */
    for (; binary_out[result_string_lenth] != '\0'; ++result_string_lenth);

    /* Prints the result */
    printf("Binary out: ");

    for (; result_string_lenth > -1; --result_string_lenth)
        printf("%c", binary_out[result_string_lenth]);

    if (is_signed == 1)
        printf(" (signed)");
    else
        printf(" (unsigned)");

    printf("\n");

    return 0;
}
