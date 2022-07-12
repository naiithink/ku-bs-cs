#include <stdio.h>
#include <stdlib.h>

#define STR_IN_SIZE_T 12

int main(void)
{
    char time12_str[STR_IN_SIZE_T];
    char temp_time12[3][3] = { "\0\0", "\0\0", "\0\0" };
    int time12[] = { 0, 0, 0 }, time24[] = { 0, 0 };

    printf("Enter a 12-hour time [eg. 12:34 am]: ");
    fgets(time12_str, STR_IN_SIZE_T, stdin);

    for (int i = 0, temp_time12_list = 0, temp_time12_index = 0; time12_str[i] != '\0'; i++)
    {
        if (time12_str[i] == ':' || time12_str[i] == 32)
        {
            temp_time12_list++;
            temp_time12_index = 0;
            continue;
        }
        temp_time12[temp_time12_list][temp_time12_index] = time12_str[i];
        temp_time12_index++;
    }

    switch (temp_time12[2][0])
    {
        case 'A':
        case 'a':
            time12[2] = 0;
            break;
        case 'P':
        case 'p':
            time12[2] = 1;
            break;
        default:
            exit(1);
    }

    time12[0] = atoi(&temp_time12[0][0]);
    time12[1] = atoi(&temp_time12[1][0]);

    if (time12[0] < 1       \
        || time12[0] > 12   \
        || time12[1] < 0    \
        || time12[1] > 59   )
        return 1;
    
    if (!time12[2])
    {
        if ((time24[0] = time12[0]) >= 12)
            time24[0] = 0;
    }
    else if ((time24[0] = time12[0] + 12) >= 24)
        time24[0] = time12[0];
    time24[1] = time12[1];

    printf("Equivalent 24-hour time: %02d:%02d\n", time24[0], time24[1]);

    return 0;
}