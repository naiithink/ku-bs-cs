#include <stdio.h>
#include <math.h>

struct Point
{
    double X;
    double Y;
};

int main(void)
{
    int n = 0;

    printf("Number of Points: ");
    scanf("%d", &n);

    struct Point points[n];
    for (int i = 0; i < n; i++)
    {
        printf("P%d.X: ", i + 1);
        scanf("%lf", &points[i].X);
        printf("P%d.Y: ", i + 1);
        scanf("%lf", &points[i].Y);
    }

    printf("Length:\n");

    for (int i = 0, round = n - 1; i < round; i++)
    {
        int p1 = i;
        int p2 = i + 1;
        double dX = points[p2].X - points[p1].X;
        double dY = points[p2].Y - points[p1].Y;
        double len = sqrt(pow(dX, 2) + pow(dY, 2));

        printf("Length from P%d(%.2lf, %.2lf) to P%d(%.2lf, %.2lf) is %.2lf\n" \
              , p1+1, points[p1].X, points[p1].Y, p2+1, points[p2].X, points[p2].Y, len);
    }

    return 0;
}