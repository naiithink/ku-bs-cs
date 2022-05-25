#include <stdio.h>

void main(void)
{
    float preGrade = 1.75;
    int preCredit = 21;
    int credit = 18;
    float requiredGrade = 2.00;

    float preScore = preGrade * (preCredit / 1);
    float totalCredit = (preCredit / 1) + (credit / 1);
    float targetScore = (requiredGrade * totalCredit) - preScore;
    float targetGrade = targetScore / (credit / 1);

    printf("The GPA this semester should be %.2f\n", targetGrade);
}