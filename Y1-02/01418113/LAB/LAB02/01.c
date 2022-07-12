#include <stdio.h>
#include <stdlib.h>

void main()
{
    char hour_str[5], min_str[3];
    int hour, min;

    printf("Enter hour: ");
    fgets(hour_str, 5, stdin);

    printf("Enter minute: ");
    gets(min_str);

    hour = atoi(hour_str);
    min = atoi(min_str);

    printf("Time is %02d:%02d\n", hour, min);
}