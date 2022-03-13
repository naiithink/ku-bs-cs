#include <stdio.h>
#include <stdlib.h>

#define STR_IN_SIZE 12
#define SYM_CNT 3

int main(void)
{
    char sym[SYM_CNT+1] = "-O^", hgt_str[STR_IN_SIZE], cstep_str[STR_IN_SIZE];
    int hgt = 0, rnd = 0, head_index = 0, new_head_index = 0, cstep = 0;
    int sig = 0;

    printf("Input number of stairs: ");
    fgets(hgt_str, STR_IN_SIZE, stdin);
    hgt = atoi(hgt_str);
    if (hgt < 2)
        return 1;

    char lad[hgt+1];
    head_index = hgt - 2;
    
    do
    {
        rnd++;

        for (int i = 0; i < hgt; i++)
        {
            if (i == head_index)
            {
                for (int c = 1; c < SYM_CNT; c++)
                {
                    lad[i] = sym[c];
                    i++;
                }
            }
            lad[i] = sym[0];
        }

        printf("---- round %d ----\n", rnd);
        for (int i = 0; i < hgt; i++)
            printf("|-%c-|\n", lad[i]);

        printf("Input step command: ");
        fgets(cstep_str, STR_IN_SIZE, stdin);
        cstep = atoi(cstep_str);
        cstep *= -1;
        new_head_index = head_index + cstep;

        if (!cstep)
            sig = 1;
        else if (new_head_index < 0)
            head_index = 0;
        else if (new_head_index > (hgt-2))
            head_index = hgt - 2;
        else
            head_index += cstep;
    }
    while (!sig);

    return 0;
}