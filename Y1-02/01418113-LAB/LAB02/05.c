#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ttype, side_A_str[4], side_B_str[4], side_C_str[4];
    int side[2] = {0, 0, 0};

    printf("Enter length of side A: ");
    fgets(side_A_str, 4, stdin);
    printf("Enter length of side B: ");
    fgets(side_B_str, 4, stdin);
    printf("Enter length of side C: ");
    fgets(side_C_str, 4, stdin);

    side[0] = atoi(side_A_str);
    side[1] = atoi(side_B_str);
    side[2] = atoi(side_C_str);

    if  (                                      \
        (side[0] * side[1] * side[2] == 0)  || \
        (side[0] + side[1] <= side[2])      || \
        (side[1] + side[2] <= side[0])      || \
        (side[2] + side[0] <= side[1])         \
    )
    {
        ttype = "invalid";
    }
    else if (side[0] == side[1] && side[1] == side[2])
    {
        ttype = "equilateral";
    }
    else if (side[0] != side[1] && side[1] != side[2] && side[0] != side[2])
    {
        ttype = "scalene";
    }
    else
    {
        ttype = "isosceles";
    }

    printf("Triangle type is %s.\n", ttype);

    return 0;
}