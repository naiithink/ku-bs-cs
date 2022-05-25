#include <stdio.h>
#include <stdlib.h>

#define STR_IN_SIZE_T 12
#define ASCII_OF_NOUGHT 48
#define RETRIABLE 1

int main(void)
{
    char from_stdin[STR_IN_SIZE_T];
    char scores_str[STR_IN_SIZE_T];
    int sbj_n = 0, sum_credit = 0, credit = -1, sum_score = 0;
    float gpa = 0.0;

    printf("Enter number of subject(s): ");
    fgets(from_stdin, STR_IN_SIZE_T, stdin);
    sbj_n = atoi(from_stdin);

    for (int i = 0, grade = 0; i < sbj_n; i++, from_stdin[1] = '\0', grade = 0, credit = -1)
    {
        printf("Enter credit,grade for subject #%d: ", i+1);
        fgets(from_stdin, STR_IN_SIZE_T, stdin);
        if ((!from_stdin[1] || (from_stdin[0] - ASCII_OF_NOUGHT) < 0 || (from_stdin[0] - ASCII_OF_NOUGHT) > 9) && RETRIABLE)
        {
            i--;
            continue;
        }
        else if (!RETRIABLE)
            exit(1);

        switch (from_stdin[2])
        {
            case 'F':
            case 'f':
                grade = 0;
                break;
            case 'A':
            case 'a':
                grade = 4;
                break;
            case 'B':
            case 'b':
                grade = 3;
                break;
            case 'C':
            case 'c':
                grade = 2;
                break;
            case 'D':
            case 'd':
                grade = 1;
                break;
            default:
                if (RETRIABLE)
                {
                    i--;
                    continue;
                }
                else
                    exit(2);
        }
        credit = from_stdin[0] - ASCII_OF_NOUGHT;
        sum_credit += credit;
        sum_score += credit * grade;
    }

    gpa = (float)(sum_score) / (float)(sum_credit) ;
    printf("GPA = %.2f\n", gpa);

    return 0;
}