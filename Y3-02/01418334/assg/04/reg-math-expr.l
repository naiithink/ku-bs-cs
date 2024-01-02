%top{
/*
 * This program tokenizes regular mathematical expressions
 */

#include <stdio.h>

#define PRINT_COUPLE(elem1, elem2) printf("<%s, %s>\n", elem1, elem2)
}

equal       "="
terminal    "."
integer     [0-9]+
real        [0-9]+"."[0-9]+
word        [A-Za-z_][A-Za-z0-9_]*
add         "+"
minus       "-"
multiply    "*"
divide      "/"

%%

[ ]
{equal}     PRINT_COUPLE("EQUAL", yytext);
{terminal}  PRINT_COUPLE("TERMINAL", yytext);
{integer}   PRINT_COUPLE("INTEGER", yytext);
{real}      PRINT_COUPLE("REAL", yytext);
{word}      PRINT_COUPLE("WORD", yytext);
{add}       PRINT_COUPLE("ADD", yytext);
{minus}     PRINT_COUPLE("MINUS", yytext);
{multiply}  PRINT_COUPLE("MULTIPLY", yytext);
{divide}    PRINT_COUPLE("DIVIDE", yytext);

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
