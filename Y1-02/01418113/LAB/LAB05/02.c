#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STR_IN_SIZE 12

int main(void)
{
    char n_str[STR_IN_SIZE];
    unsigned int found = 0, n = 0, c = 0, result[3] = {0, 0, 0};
    float slope = 0, prop = 0;

    fgets(n_str, STR_IN_SIZE, stdin);
    n = atoi(n_str);

    for (unsigned int b = 4; b < n && !found; b++)
    {
        for (unsigned int a = 3; a < b; a++)
        {
            slope = (float)(a) / (float)(b);
            if (slope >= 1)
                continue;
            else
            {
                c = n - (a + b);
                prop = pow((pow((double)(a), 2.0) + pow((double)(b), 2.0)), 0.5);
                if (c == prop && (a + b + c) == n)
                {
                    result[0] = a;
                    result[1] = b;
                    result[2] = c;
                    found = 1;
                    break;
                }
            }
        }
    }

    if (!found)
        printf("No triple found.\n");
    else if (found == 1)
        printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
    else
        return 1;

    return 0;
}