#include <stdio.h>

int A, B, C, D, E, F;

int main(void)
{
    int a = 5, b = 2;

    A = a++ % b >> 2                /* Ans1 = 0     */ ;
    //     0011 >> 2

    B = a | b + 3                   /* Ans2 = 5     */ ;
    //       0101
    //    |  0101
    //       0101

    C = (b << 1) * a                /* Ans3 = 20    */ ;
    //      0100
    //         4 * 5

    D = a + (7 & b)                 /* Ans4 = 7     */ ;
    //      0111
    //   &  0010
    //      0010
    //  5 + 2

    E = --a * b % 3 << 2             /* Ans5 = 8    */ ;
    //    4 * 2
    //        8 % 3
    //            2 << 2
    //         0010
    //     <<     2
    //         1000

    F = (a + 5 * b >> 1) << 2       /* Ans6 = 28    */ ;
    //   5 + 10    >> 1
    //          15 >> 1
    //        1111
    //    >>     1
    //        0111       << 2
    //        0111
    //    <<     2
    //   0001 1100

    return 0;
}