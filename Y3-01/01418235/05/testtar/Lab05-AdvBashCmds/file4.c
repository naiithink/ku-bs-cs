#include <stdio.h>
#include <stdlib.h>

int main()  {
   int i=65;
   int x;

   for (i=0; i<30; i++)  {
      x = (rand() % 26) + 65;
      printf ("%2d %c %2d\n", x, x, i+1);
   }
}
