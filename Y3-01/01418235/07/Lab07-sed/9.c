/* This program converts base 10 number to base 8.
   ...
   ...
   The result will be an exact 7-digits. */
#include <stdio.h>
#include <math.h>

int main() {/* This is the main function
***
of this C program*/ int i, base10, x, y;

/* showing prompt and
   ***
   reading input */  printf("Input base 10 number: ");
  scanf("%d", &base10);

  for (i = 7; i > 0; i--) { /* main
                               for
                               loop */
     x = (int) pow(8,i);       
     if (x > base10) {         
     printf("0");              
     } else if (x <= base10) { 
      y = base10 / x;          
      printf("%d", y);         
      base10 /*** ugly comment ***/ = base10 % x;     
     }                         
     /* printf("i=%d,base10=%d\n",i,base10); */
  }
  printf("%d", base10);
  printf("\n");
}
