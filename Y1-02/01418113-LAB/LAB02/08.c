#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    char size_str[5], opt_str0[5], opt_str1[5], opt_str2[5];
    int size, opt[3];
    float validator = 1.00, surf, extra_cost, cost, price;
    
    float fixed_cost = 5.00, bast_cost = 2.00;
    int area[3] = {10.00, 16.00, 20.00};
    float extras[3] = {0.50, 0.25, 0.30};

    printf("Welcome to My Pizza Shop!!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Enter pizza size (1=s, 2=m, or 3=l): ");
    fgets(size_str, 5, stdin);
    printf("Extra pepperoni? (1=yes, 0=no): ");
    fgets(opt_str0, 5, stdin);
    printf("Extra cheese? (1=yes, 0=no): ");
    fgets(opt_str1, 5, stdin);
    printf("Extra mushroom? (1=yes, 0=no): ");
    fgets(opt_str2, 5, stdin);

    size = atoi(size_str);
    if (size < 1 || size > 3)
    {
        validator = 0.00;
    }

    opt[0] = atoi(opt_str0);
    opt[1] = atoi(opt_str1);
    opt[2] = atoi(opt_str2);

    for (int i = 0; i < 3; i++)
    {
        if (opt[i])
        {
            extra_cost += extras[i];
        }
    }

    surf = M_PI * pow(area[size-1], 2.00) / 4.00;
    cost = fixed_cost + (bast_cost * surf) + (extra_cost * surf);
    price = validator * cost * 1.50;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Your order costs %.2f baht.\nThank you.\n", price);

    return 0;
}