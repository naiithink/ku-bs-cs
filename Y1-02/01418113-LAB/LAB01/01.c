#include <stdio.h>

void main(void)
{
    int computer_time = 1678;
    int days = computer_time / 1440;
    int hours = (computer_time - days * 1440) / 60;
    int mins = computer_time - (days * 1440 + hours * 60);
    printf("It is %i days %i hours and %i minutes.\n", days, hours, mins);
}