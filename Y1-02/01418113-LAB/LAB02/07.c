#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x_str[5], y_str[5];

    printf("Enter the x coordinate: ");
    fgets(x_str, 5, stdin);
    printf("Enter the y coordinate: ");
    fgets(y_str, 5, stdin);

    int x = atoi(x_str);
    int y = atoi(y_str);

    //
    
    /*
    if (x == y && y == 0)
    {
        printf("Center\n");
        return 0;
    }
    
    char *dim_x, *dim_y, sep;

    if (y > 0)
    {
        dim_y = "North";
    }
    else if (y < 0)
    {
        dim_y = "South";
    }
    else
    {
        dim_y = "";
    }

    if (x > 0)
    {
        if (! y)
        {
            dim_x = "East";
        }
        else
        {
            dim_x = "east";
        }
    }
    else if (x < 0)
    {
        if (! y)
        {
            dim_x = "West";
        }
        else
        {
            dim_x = "west";
        }
    }
    else
    {
        dim_x = "";
    }

    if (x && y)
    {
        sep = '-';
    }

    printf("%s%c%s\n", dim_y, sep, dim_x);

    */

    char *dim;

    if (! x && ! y)
    {
        dim = "Center";
    }
    else if (x < 0 && y == 0)
    {
        dim = "West";
    }
    else if (x < 0 && y < 0)
    {
        dim = "South-west";
    }
    else if (x < 0 && y > 0)
    {
        dim = "North-west";
    }
    else if (x > 0 && y == 0)
    {
        dim = "East";
    }
    else if (x > 0 && y < 0)
    {
        dim = "South-east";
    }
    else if (x > 0 && y > 0)
    {
        dim = "North-east";
    }
    else if (x == 0 && y > 0)
    {
        dim = "North";
    }
    else if (x == 0 && y < 0)
    {
        dim = "South";
    }

    printf("%s\n", dim);

    //

    return 0;
}