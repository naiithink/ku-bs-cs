/*
 * 4->1% ข้อ 4 (1%)
 * passed
 */

#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Please Input Dimension of Matrix (m*n): ");
    scanf("%d*%d", &m, &n);
    float a[m][n];
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("Input Number for (%d, %d): ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\n=== Original Matrix ===\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%8.2f", a[i][j]);
        }
        printf("\n");
    }

    printf("\n=== Transpose Matrix ===\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%8.2f", a[j][i]);
        }
        printf("\n");
    }
}