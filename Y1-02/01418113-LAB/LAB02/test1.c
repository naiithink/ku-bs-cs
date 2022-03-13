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

    char *pos;
    int i = 0;

    if (x == y && y == 0)
    {
        pos = "center";
    }

    if (x > 0)
    {
        pos = "east";
        i = 6;
    }
    else if (x < 0)
    {
        pos = "west";
        i = 6;
    }

    if (y > 0)
    {
        pos[i] = "north";
    }
    else if (y < 0)
    {
        pos[i] = "south";
    }

    if (x && y)
    {
        pos[i-1] = '-';
    }

    pos[0] = pos[0] - 32;

    printf("%s\n", pos);

    //

    return 0;
}