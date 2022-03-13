#include <stdio.h>

typedef struct
{
    char id[13];
    int midterm;
    int final;
    int sum;
    char grade;
}
Record;

int main(void)
{
    Record students[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter Student ID: ");
        scanf("%s", students[i].id);
        printf("Enter Student Midterm: ");
        scanf("%d", &students[i].midterm);
        printf("Enter Student Final: ");
        scanf("%d", &students[i].final);
    }

    for (int i = 0, inv = 0; i < 5; i++)
    {
        students[i].sum = students[i].midterm + students[i].final;
        inv = (int)students[i].sum / 10;
        switch (inv)
        {
            case 10:
            case 9:
            case 8:
                students[i].grade = 'A';
                break;
            case 7:
                students[i].grade = 'B';
                break;
            case 6:
                students[i].grade = 'C';
                break;
            case 5:
                students[i].grade = 'D';
                break;
            default:
                students[i].grade = 'F';
                break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Student ID %s receives grade %c.\n", students[i].id, students[i].grade);
    }

    return 0;
}