#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char /* s = 's', */ goal_str[10], saved_str[10];
    float goal = 0, remain = 0, saved = 0, topping_up = 0;
    int day = 0;

    printf("Enter your goal amount: ");
    fgets(goal_str, sizeof(goal_str), stdin);
    if ((goal = atof(goal_str)) <= 0)
        return 1;
    
    remain = goal;

    while (1)
    {
        day++;

        printf("Enter money collected today: ");
        fgets(saved_str, sizeof(saved_str), stdin);
        if ((saved = atof(saved_str)) >= 0);
        else
            saved = 0;

        remain -= saved;
        topping_up += saved;
        
        if (remain <= 0)
        {
            // ทำงี้ไม่ได้เฉย
            // if (day == 1)
            //     s = '\0';
            // printf("Congratulations! You take %i day%c to reach your goal.\n", day, s);
            if (day == 1)
                printf("Congratulations! You take %i day to reach your goal.\n", day);
            else
                printf("Congratulations! You take %i days to reach your goal.\n", day);
            return 0;
        }
        printf("Total money collected up to day %i is %.2f. You need %.2f more.\n", day, topping_up, remain);
    }
}