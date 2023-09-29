#include <stdio.h>

int main() {
   int i;

   for (i=1;i<5;i++) {
      if (i/2 == (i-1)/2)
         fprintf (stderr,"Error! %d is an odd number\n", i);
      else
         fprintf (stdout,"Output! %d is an even number\n", i);
   }
}
