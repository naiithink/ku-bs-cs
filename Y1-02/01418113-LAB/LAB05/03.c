#include <stdio.h>
#include <stdlib.h>

#define CHAR_IN_SIZE 12

int main(void)
{
    char n_str[CHAR_IN_SIZE], opr_str[CHAR_IN_SIZE], opr, orand_str[CHAR_IN_SIZE];
    float n = 0.0, orand = 0.0, remain = 0.0;
    short int sig = 0;

    printf("Initial Value: ");
    fgets(n_str, CHAR_IN_SIZE, stdin);
    n = atof(n_str);
    remain = n;
    printf("\n");

    while (!sig)
    {
        printf("Operator: ");
        fgets(opr_str, CHAR_IN_SIZE, stdin);
                                  /* arith operator char {42, 43, 45, 47} */
        if (opr_str[1] == '\n' && opr_str[0] > 41 && opr_str[0] < 48)
        {
            opr = opr_str[0];
            if (opr != 44 && opr != 46)
            {
                printf("Input Value: ");
                fgets(orand_str, CHAR_IN_SIZE, stdin);
                orand = atof(orand_str);
            }
            else
            {
                printf("\n");
                sig = 1;
            }
        }
        else
        {
            printf("\n");
            sig = 1;
        }

        if (!sig)
        {
            switch (opr)
            {
            case '+':
                remain += orand;
                break;
            case '-':
                remain -= orand;
                break;
            case '*':
                remain *= orand;
                break;
            case '/':
                if (orand == 0)
                {
                    sig = 2;
                    break;
                }
                remain /= orand;
                break;
            default:
                sig = 1;
            }

            if (!sig)
            {
                printf("Present Value is %.4f\n", remain);
            }

            printf("\n");
        }
    }

    if (sig > 1)
        return sig;
    else
        printf("Finish Calculation. Final Value is %.4f\n", remain);

    return 0;
}