#include <stdio.h>
#include <stdlib.h>
int main()
{
    char salary_str[10], Tax_str[10];

        fgets(salary_str, 10, stdin);
        
        float salary = atof(salary_str);
        float tax = atof(Tax_str);
        
        
        if (salary <= 300000.00 )
        {
            tax = (salary * 5/100);
            printf("%.02f",tax);
        }
        else if (salary == 500000.00)
        {
            tax =(((salary-300000)*5/100) + ((salary - 200000)*10/100));
            printf("%.02f",tax);
        }
}