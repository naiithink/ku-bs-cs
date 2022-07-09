#include <stdio.h>

#define NAME_LEN 16
#define NUM_STUDENT 5

typedef struct
{
    char name[NAME_LEN];
    double mark;
}
student;

int main(void)
{
    student students[NUM_STUDENT];
    double total_mark = 0;
    double avg_mark = 0;

    for (int i = 0; i < NUM_STUDENT; ++i)
    {
        printf("Student #%d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Student #%d mark: ", i + 1);
        scanf("%lf", &students[i].mark);
        total_mark += students[i].mark;
    }

    avg_mark = total_mark / NUM_STUDENT;
    printf("Average mark: %.2f\n", avg_mark);

    for (int i = 0; i < NUM_STUDENT; ++i)
        if (students[i].mark > avg_mark)
            printf("%.2f\t%s\n", students[i].mark, students[i].name);

    return 0;
}
