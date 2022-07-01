/*
 * Homework 1: This program converts an array of decimal integers to an array binaries
 * 
 * Potsawat Thinkanwatthana
 * Student ID: 6410451199
 */

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 100

/* Signing flag */
static int is_signed;

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;

    /* The `decimal_in' variable holds the input value to be converted */
    int decimal_in;
    int char_index;
    int result_string_lenth;
    char binary_out[CHAR_MAX];

    /* Converts input from argv in turn */
    for (int argi = 1; argi < argc; ++argi)
    {
        decimal_in = (int) strtol(argv[argi], NULL, 10);
        char_index = 0;
        result_string_lenth = 0;

        printf("Decimal in: %d\n", decimal_in);

        if (decimal_in == 0)
        {
            printf("Birnay out: (unsigned)\t0\n");
            continue;
        }

        /* Initializes `binary_out' char array to '\0' */
        for (int i = 0; i < CHAR_MAX; ++i)
            binary_out[i] = '\0';

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

        if (is_signed == 1)
            printf("(signed)\t");
        else
            printf("(unsigned)\t");

        for (; result_string_lenth > -1; --result_string_lenth)
            printf("%c", binary_out[result_string_lenth]);

        printf("\n");
    }

    return 0;
}
