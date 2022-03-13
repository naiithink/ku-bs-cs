#include <stdio.h>

const int SCORE_ARRAY_SIZE = 3;

int main(void)
{
    int score[SCORE_ARRAY_SIZE] = {2, 3, 5};
    int res = 0;

    for (int i = 0; i < SCORE_ARRAY_SIZE; i++)
    {
        res += score[i];
    }

    printf("%i\n", res);

    return 0;
}