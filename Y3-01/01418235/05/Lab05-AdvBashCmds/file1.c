#include <stdio.h>
#include <string.h>

int main()
{
   char  string1[1024];

   sprintf (string1, "This is the output from file1.c.\n"
                     "There is two lines here.");
   printf ("%s", string1);
}
