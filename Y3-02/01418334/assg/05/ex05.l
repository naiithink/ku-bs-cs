%top{
/*
 * INPUT:
 * ABCdabc
 * Aabcd
 * BCdbA
 * bc
 * abccdba
 */

#include <stdio.h>
}

%%

\n                      { printf("1") ;}
A                       { printf("2") ;}
a                       { printf("3") ;}
d                       { printf("4") ;}
[b-d]*                  { printf("5") ;}
abc                     { printf("6") ;}
[A-C]*                  { printf("7"); }
[a-c]*                  { printf("8") ;}
[^a-c]+d[^A-C]+         { printf("9") ;}

%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char **argv)
{
    yylex();
    return 0;
}
