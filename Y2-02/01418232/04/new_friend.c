/**
 * Accepts at most n - 1 inputs
 */

#include <stdio.h>

int main(void)
{
    int array_size = 0;

    scanf("%i", &array_size);

    if (array_size == 0)
        return 0;

    // Sum of nat nums
    int sum_ex = array_size * (array_size + 1) / 2;
    int sum_ac = 0;

    int array[array_size - 1];

    // Input
    int in = 0;

    scanf("%i", &in);

    if (in < 1 || in > array_size)
    {
        printf("`Out of range`\n");
        return 0;
    }

    array[0] = in;
    sum_ac += in;

    for (int i = 1, lim = array_size - 1; i < lim; ++i)
    {
        scanf("%i", &in);

        if (in < 1 || in > array_size)
        {
            printf("`Out of range`\n");
            return 0;
        }

        array[i] = in;
        sum_ac += in;
    }

    printf("%i\n", sum_ex - sum_ac);

    return 0;
}
