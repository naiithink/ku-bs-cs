#include <stdio.h>

int main(void)
{
    int i, j = 12;
    int *pi, *pj = &j;
    
    *pj     =     j + 3    ;        // j  = 15  ::=  j += 3,      pj = &j
      i     =   *pj + 7    ;        // i  = 22  ::=  j += 7
     pi     =    pj        ;        // pi = &j  ::=  pi = pj
    *pi     =     i + j    ;        // j  = 37  ::=  j = i + j
    
    //  i = 22
    //  j = 37
    //  pi = pj = &j = FF00
    //  &i = FF04

    return 0;
}