#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char in[10];
    int n, count, in_use;
    double price, discount;

    fgets(in, 10, stdin);
    n = atoi(in);

    fgets(in, 10, stdin);
    price = atof(in);

    if (n >= 9)
    {
        in_use = 9;
        discount = 0.4;
    }
    else if (n >= 6)
    {
        in_use = 6;
        discount = 0.3;
    }
    else if (n >= 3)
    {
        in_use = 3;
        discount = 0.2;
    }
    else if (n >= 2)
    {
        in_use = 2;
        discount = 0.15;
    }
    else if (n >= 1)
    {
        in_use = 1;
        discount = 0.1;
    }
    else
    {
        in_use = 0;
        discount = 0;
    }

    discount = discount * 100.0;
    
    printf("You get %i percents discount.\n", (int) discount);
    printf("Total amount due is %.2f Baht.\n", price-(price*discount/100.0));
    printf("And you have %i stickers left.\n", n-in_use);
}