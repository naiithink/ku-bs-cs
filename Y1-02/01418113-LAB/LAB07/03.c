#include <stdio.h>

int A, B, C, D, E, F;

int main(void)
{
    int x = 1, y = 0, z = 32;
    float i = 65;
    char a = 'A', b = 'a';

    A = (b == a + z) && (x > y)         /* Ans1 = T     */ ;
    //       65 + 32       1
    //  97 == 97     &&    1
    //      1        &&    1
 
    B = (y == z) && (!y)                /* Ans2 = F     */ ;
    //      0    &&  1
 
    C = (a / 4 == i / 4) || (!z)        /* Ans3 = F     */ ;        // float v int comparison
    //    16   ==   16.  ||  0
    //          0        ||  0
 
    D = (z >= y) && (a != 65)           /* Ans4 = F     */ ;
    //      1    &&    0
 
    E = (x * y) || (x) && (z  % 5)       /* Ans5 = T     */ ;
    //     0        1  &&    2
    //     0    ||     1
 
    F = (b < i) || (z / 2)              /* Ans6 = T      */ ;
    //     0    ||    16


    return 0;
}