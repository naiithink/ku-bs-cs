#include <stdio.h>

#define STR_SIZE 3

double findAverage(char *filename)
{
    FILE *src;
    double res = 0;
    int count = 0;
    int n = 0;
    int sum = 0;
    char buf[3];

    src = fopen(filename, "r");
    while (fscanf(src, "%d\n", &n) != EOF)
    {
        sum += n;
        count++;
    }
    fclose(src);

    res = (double) sum / count;

    return res;
}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    average = findAverage(filename);
    printf("Average score is %.4lf\n", average);
}