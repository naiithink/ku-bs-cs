#include <stdio.h>

void stringcat(char src[], char dest[])
{
    int i = 0;
    int j = 0;
    int begin = 0;
    int done = 0;

    while (!done)
    {
        if (dest[i] == '\0')
            begin = 1;
        if (begin)
        {
            dest[i] = src[j];
            j++;
            if (src[j-1] == '\0')
                done = 1;
        }
        i++;
    }
}

int main()
{
    char in1[100], in2[100];

    printf("Input 1: ");
    gets(in1); /* read a line of characters from the input to "in1" variable */
    printf("Input 2: ");
    gets(in2); /* read another line of characters from the input to "in2" variable */
    stringcat(in1, in2);
    printf(" Output: ");
    printf("%s\n", in2);
    return 0;
}