#include <stdio.h>

int main(void)
{
    int a[10] = {0, 1}, *ptr;
    int k;
    ptr = a + 2;

    for (k = 2; k < 10; k++)
        a[k] = a[k - 1] + a[k - 2];

    // a = { 0, 1, 1, 2, 3, 5, 8, 13 }
    //       0  1  2  3  4  5  6   7
    // ptr         0  1  2  3  4   5
    //       FFE0
    //          FFE4
    //             FFE8
    //                FFEC
    //                   FFF0
    //                      FFF4
    //                         FFF8
    //                            FFFC

    *ptr        = ?
    *(ptr+1)    = ?
    ptr         = ?
    ptr[3]      = ?
    ptr[-1]     = ?
    &a[4]       = ?
    *(ptr+2)    = ?
    ptr+3       = ?
    &ptr[3]     = ?
    ptr[5]      = ?

    return 0;
}