#include <stdio.h>
#include <string.h>

#define PATIENT_NUM 99
#define NAME_LEN 12
#define DNE -1

typedef struct
{
    int id;
    int level;
    char name[NAME_LEN];
}
patient;

int main(void)
{
    patient *head;
    register int max;
    int n;
    int m;
    int id;
    int level;
    register int exist_i;
    register int maxim_i;
    char s_buff[NAME_LEN] = "";

    register double cumuLevel = 0.0;

    scanf("%d", &n);

    if (n == 0)
    {
        printf("Nothing to show\n");
        return 0;
    }
    else if (n < 0 || n > PATIENT_NUM)
    {
        printf("ErRor.!\n");
        return 0;
    }

    m = n;

    patient people[PATIENT_NUM];
    int exist[n];
    patient *maxim[n];

    while (m)
    {
        scanf("%d", &id);
        if (id < 1 || id > PATIENT_NUM)
            continue;

        scanf("%s", s_buff);
        scanf("%d", &level);

        if (level < 1 || id > 10)
            continue;
        else if (m == n)
            max = level;

        if (id < 1 || id > PATIENT_NUM)
            continue;
        else if (level > max)
            max = level;

        head = &people[id];

        head->id = id;
        head->level = level;
        strcpy(head->name, s_buff);

        exist[exist_i++] = id;

        cumuLevel += (double) level;

        m--;
    }

    cumuLevel = cumuLevel / (double) n;

    if (cumuLevel > (int) cumuLevel)
        cumuLevel += 0.1;

    printf("All patient:\n");
    for (int i = 0, j = 0; (j = exist[i]); i++)
    {
        head = &people[j];
        printf("  %02d %-10s %d\n", head->id, head->name, head->level);

        if (head->level == max)
            maxim[maxim_i++] = head;
    }

    printf("Critical:\n");
    int i = 0;
    while ((head = maxim[i++]) != NULL)
        printf("  %02d %-10s %d\n", head->id, head->name, head->level);

    printf("Average: %.1lf\n", cumuLevel);

    return 0;
}
