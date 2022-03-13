#include <stdio.h>

#define ARRAY_SIZE 5

typedef struct
{
    char id[12];
    int midterm;
    int final;
    char grade;
}
StudentRecord;

void findTop(StudentRecord pRec[], int size, StudentRecord **topMid, StudentRecord **topFin)
{
    int xmid[] = { 0, 0 };
    int xfin[] = { 0, 0 };

    for (int i = 0; i < size; i++)
    {
        if (pRec[i].midterm > xmid[1])
        {
            xmid[0] = i;
            xmid[1] = pRec[i].midterm;
        }
        if (pRec[i].final > xfin[1])
        {
            xfin[0] = i;
            xfin[1] = pRec[i].final;
        }
    }

    *topMid = &pRec[xmid[0]];
    *topFin = &pRec[xfin[0]];
}

int main()
{

    StudentRecord students[ARRAY_SIZE], *pTopMid, *pTopFin;
    int gradeCount[5] = {0};
    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Enter Student ID: ");
        scanf("%s", students[i].id);
        printf("Enter Student Midterm: ");
        scanf("%d", &students[i].midterm);
        printf("Enter Student Final: ");
        scanf("%d", &students[i].final);
    }

    findTop(students, ARRAY_SIZE, &pTopMid, &pTopFin);

    // print grade
    printf("Top Score for Midterm:\n");
    printf("Student ID %s with score %d\n", pTopMid->id, pTopMid->midterm);
    printf("Top Score for Final:\n");
    printf("Student ID %s with score %d\n", pTopFin->id, pTopFin->final);

    return 0;
}