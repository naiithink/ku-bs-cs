/* Calculate C(n,k) */
#include <stdio.h>

long fact(long n) /* function to find factorial of n */
{
   if (n == 0 || n == 1)
      return 1;
   else
      return n * fact(n-1);
}

/* This is the main function in C */int main()
{
   long n,k;
   scanf/* This comment is weird */("%ld",&n);
   scanf("%ld",&k);
   printf("%ld\n", fact(n)/(fact(k)*fact(n-k)));
}
