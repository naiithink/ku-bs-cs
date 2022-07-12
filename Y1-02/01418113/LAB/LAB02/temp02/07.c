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
    
    if (x == 0 && y == 0) //center
    {
        printf("Center");
    }
    else if (x < 0 && y == 0) //West
    {
        printf("West");
    }
    else if (x < 0 && y < 0 ) // South-west
    {
        printf("South-west");
    }
    else if (x < 0 && y > 0) // North-west
    {
        printf("North-west");
    }
    else if (x > 0 && y == 0) // East
    {
        printf("East");
    }
    else if (x > 0 && y < 0 ) // South-east
    {
        printf("South-east");
    }
    else if (x > 0 && y > 0) // North-east
    {
        printf("North-east");
    }
    else if (x == 0 && y > 0) // North
    {
        printf("North");
    }
    else if (x == 0 && y < 0) // South
    {
        printf("South");
    }
    return 0;
}