/**
 * Accepts n > 1 inputs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_MAX 255
#define PRINT_OORNG() printf("`Out of range`\n")

int main(void)
{
    int array_size = 0;

    scanf("%i\n", &array_size);

    if (array_size < 1)
        return 0;

    // The array
    int array[array_size - 1];

    // Sum of natural nums
    int sum_ex = array_size * (array_size + 1) / 2;
    int sum_ac = 0;
    char str_in[LEN_MAX];
    char *token, *string, *tofree;

    fflush(stdin);
    fgets(str_in, LEN_MAX, stdin);

    str_in[strcspn(str_in, "\n")] = '\0';

    tofree = string = strdup(str_in);

    {
        int i = 0;
        int num = 0;
        while ((token = strsep(&string, " ")) != NULL)
        {
            if (i >= array_size - 1)
            {
                PRINT_OORNG();
                return 0;
            }

            num = atoi(token);

            if (num < 1 || num > array_size)
            {
                PRINT_OORNG();
                return 0;
            }

            sum_ac += array[i++] = num;
        }
    }

    int missing = sum_ex - sum_ac;

    if (missing == 0)
        return 0;
    else
        printf("%i\n", missing);

    free(tofree);
    return 0;
}
