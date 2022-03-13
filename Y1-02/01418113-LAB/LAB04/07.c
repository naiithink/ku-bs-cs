#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char symb = '*', u_str[10];
    int u = 0, amp = 0, incre = 1;

    fgets(u_str, sizeof(u_str), stdin);
    u = atoi(u_str);

    for (int stack = 0, height = (2*u)-1; stack < height; stack++)
    {
        if (stack >= u && incre > 0)
        {
            incre *= -1;
        }
        amp += incre;
        for (int i = 0; i < amp; i++)
        {
            printf("%c", symb);
        }
        printf("\n");
    }

    return 0;
}