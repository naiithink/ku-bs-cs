#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char salary_str[10];
    float salary, due = 0;

    fgets(salary_str, 10, stdin);
    salary = atof(salary_str);

    if (salary < 0.00)
    {
        printf("Error: Salary must be greater or equal to 0\n");
        return 1;
    }
    else if (salary > 300000.00)
    {
        float rate2 = 0.10;
        float rate2_amount = salary - 300000.00;
        due = rate2_amount * rate2;
        salary = salary - rate2_amount;
    }
    if (salary)
    {
        float rate1 = 0.05;
        due = due + (salary * rate1);
    }

    printf("%.2f\n", due);

    return 0;
}