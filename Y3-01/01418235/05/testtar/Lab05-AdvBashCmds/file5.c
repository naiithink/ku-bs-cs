#include <stdio.h>
#include <stdlib.h>

int main()  {
   int i=65;
   int x;
   int y;

   for (i=0; i<30; i++)  {
      x = (rand() % 26) + 65;
      y = (rand() % 26) + 65;
      printf ("%2d %c %2d\t%d\n", x, x, i+1, y);
   }
}
