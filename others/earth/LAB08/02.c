#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[13];
    int score;
} studentRecord;

void init(studentRecord list[], int size)
{
    
}

void enterScore(studentRecord list[], int size)
{
    /* your code here
     *
     *
     *
     *
     *
     *
     *
     *
     *
     11 */
}

void printRecords(studentRecord list[], int size)
{
    int i;

    printf("   ID        Score\n");
    for (i = 0; i < size; i++)
    {
        printf("%s       %d\n", list[i].id, list[i].score);
    }
}

int main()
{
    int enter;
    studentRecord list[3];

    init(list, 3);
    enterScore(list, 3);
    printRecords(list, 3);
}