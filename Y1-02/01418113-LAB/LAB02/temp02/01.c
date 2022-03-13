/*
#include <studio.h>
#include <stdlib.h>
void main()
{
    char hour_str[3], min_str[3];
    int hour, min;

    printf("Enter hour: "):
    fget(hour_str, 3, stdin);

    printf("Enter minute: "):
    get(minstr);

    hour = atoi(hour_str);
    minute = atoi(minstr);

    printf("Time is %d:%d, hour, minute");
}
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    char hour_str[4], min_str[4];
    int hour, minute;

    printf("Enter hour: ");
    fgets(hour_str, 4, stdin);

    printf("Enter minute: ");
    fgets(min_str, 4, stdin);

    hour = atoi(hour_str);
    minute = atoi(min_str);

    printf( "Time is %02d:%02d\n", hour, minute);
}