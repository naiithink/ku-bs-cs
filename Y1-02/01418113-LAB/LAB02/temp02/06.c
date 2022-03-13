#include<stdio.h>

int main()
{
    char c;
    scanf ("%c", &c);

    if(c >='A' && c <='Z')
    {
        printf("Output: upper case");
    }else if (c >= 48 && c <= 57){
        printf("Output: digit");

    }
    else if (c >= 'a' && c <= 'z')
    {
        printf ("Output: lower case");
    }else{
        printf("Output: others");
    }

    return 0;
    
}