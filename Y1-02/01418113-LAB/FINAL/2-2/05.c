/**
 * 5->3% ข้อ 5 (3%)
 */

/*  Submitted

    float **res;
    float *in;
    float *temp;

    in = original;

    temp = (float *) malloc (sizeof(float) * (m * n));

    for (int i = 1, lim = (m * n) + 1; i < lim; ++i)
    {
        temp[i] = in[lim-i];
    }

    res = &temp;
    // free (temp);
    return res;
*/

#include <stdio.h>
#include <stdlib.h>

float **
transpose_matrix (float *original, int m, int n)
{
    float **res;
    float *in;
    float *temp;

    in = original;

    temp = (float *) malloc (sizeof(float) * (m * n));

    for (int i = 1, lim = (m * n) + 1; i < lim; ++i)
    {
        temp[i] = in[lim-i];
    }

    res = &temp;
    free (temp);
    return res;
}

int main()
{
    int m, n, i, j;
    printf("Please Input Dimension of Matrix (m*n): ");
    scanf("%d*%d", &m, &n);
    float original[m][n];
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("Input Number for (%d, %d): ", i + 1, j + 1);
            scanf("%f", &original[i][j]);
        }
    }

    printf("\n=== Original Matrix ===\n");
    // เขียนโค้ดสำหรับแสดง original matrix เอง

    float **transpose = transpose_matrix(original[0], m, n);

    printf("\n=== Transpose Matrix ===\n");
    // เขียนโค้ดสำหรับแสดง transpose matrix เอง
}