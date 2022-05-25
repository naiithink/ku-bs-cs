#include <stdio.h>

int charcount(char *s)
{
    int count = 0;

    for (; s[count] != '\0'; count++);

    return count;
}

void charweave(char *s,char *result)
{
    int ptr = 0;
    int len = charcount(s);
    int reslen = len * 2;

    for (int i = 0; i < reslen; i++)
    {
        if (i % 2)
        {
            ptr = (i + 1) / 2;
            result[i] = s[len-ptr];
        }
        else
        {
            ptr = i / 2;
            result[i] = s[ptr];
        }
    }
    result[reslen] = '\0';
}

main()
{  char str[100],result[200];

   printf("String: ");
   gets(str);   /* read a line of characters from the input to "str" variable */
   charweave(str,result);
   printf("Output: %s\n",result);
   return 0;
}