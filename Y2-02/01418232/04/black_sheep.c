#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

#define PRINT_BALANCE "Balance (T-T)"

int main(void)
{
    int nonneg_mode[MAX_LEN] = { 0 };
    int max = 0;
    int min = 0;

    int mode = 0;
    int count = 0;

    int size = 0;

    char in_string[MAX_LEN];
    char *tofree, *string, *token;

    for (int i = 0; i < MAX_LEN; ++i)
        nonneg_mode[i] = 0;

    fgets(in_string, MAX_LEN, stdin);

    in_string[strcspn(in_string, "\n")] = '\0';

    tofree = string = strdup(in_string);

    {
        int in_int = 0;
        int nonneg_mode_index = 0;

        while ((token = strsep(&string, " ")) != NULL)
        {
            in_int = atoi(token);

            if (in_int > max)
                max = in_int;

            nonneg_mode[in_int]++;
            size++;
        }
    }

    for (int i = 1, lim = max + 1; i < lim; ++i)
        if (nonneg_mode[i] > mode)
        {
            mode = i;
            count = nonneg_mode[i];
        }

    if (size < 2)
        return 0;
    else if (count <= size / 2)
        printf("%s\n", PRINT_BALANCE);
    else if (mode)
        printf("%i\n", mode);

    free(tofree);
    return 0;
}
