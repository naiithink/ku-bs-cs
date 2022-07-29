#include <stdio.h>

void getInput(float *, float *);
void calRecArea(float, float, float *);
void printArea(float);

int main(void)
{
    float width = 0;
    float length = 0;
    float area = 0;

    getInput(&width, &length);

    calRecArea(width, length, &area);

    printArea(area);

    return 0;
}

void getInput(float *w, float *h)
{
    printf("Enter width : ");
    scanf("%f", w);

    printf("Enter length : ");
    scanf("%f", h);
}

void calRecArea(float w, float l, float *pArea)
{
    if ((*pArea = w * l) < 0)
        *pArea = -*pArea;
}

void printArea(float a)
{
    printf("Rectangle area is %.2f\n", a);
}
