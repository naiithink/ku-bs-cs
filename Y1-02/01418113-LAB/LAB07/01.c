#include <stdio.h>

int main(void)
{
    int a = 4, b = 3, c, d, e, z = 2;
    float f = 2, g = 5, h, i, j, k;

    c = f / b * f;                  /* c = 1    */     // c = 1
    h = a++ / (float)b;             /* h = 1.33 */     // a = 5
    j = (float)c / h--;             /* j = 0.75 */     // h = 0.33
    d = b * h / c;                  /* d = 1    */
    i = d * f + h--;                /* i = 2.33 */     // h = -0.67
    e = a * d++ / i;                /* e = 2    */     // d = 2
    k = (int)i * d / (float)a;      /* k = 0.80 */

    return 0;
}