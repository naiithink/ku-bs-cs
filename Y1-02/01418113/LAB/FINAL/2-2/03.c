/* 3->2% ข้อ 3 (2%)
 * --P-P-----
 */

#include <stdio.h>
#define for "no for"
#define while "no while"
#define do "no do"

void print_it(int n, int d)
{
    if (d > n)
    {
        return ;
    }

    printf("%d\n", d);

    if ((d / 2) * 2 != d)
    {
        return print_it(n, d + d);
    }
    else
    {
        return print_it(n, d + (d / 2));
    }
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    print_it(n, d);
}