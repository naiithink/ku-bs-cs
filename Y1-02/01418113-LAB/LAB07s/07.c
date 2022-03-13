#include <stdio.h>

void roman2arabic(char input[],char output[])
{
    int oi = 0;

    for (int i = 0, prev = 0, sum = 0, curr = 0, ni = 0, nv = 0; input[i] != '\0'; i++, curr = 0)
    {
        switch (input[i])
        {
            case 'I':
                curr = 1;
                ni++;
                break;
            case 'V':
                curr = 5;
                nv++;
                break;
            case 'X':
                curr = 10;
                break;
        }

        prev = sum;
        sum += curr;

        if (!curr)
        {
            if (sum)
            {
                output[oi++] = sum + 48;
                output[oi++] = input[i];
            }
            else
                output[oi++] = input[i];
            sum = 0;
            ni = 0;
            nv = 0;
        }
        else
        {
            if (sum)
            {
                if (curr > prev)
                {
                    if (ni == 1)
                        sum = curr - prev;
                    else if (prev)
                    {
                        output[oi++] = prev + 48;
                        sum = curr;
                    }
                }
                else if (sum > 9 || ni > 3 || nv > 1)
                {
                    if (ni > 3)
                    {
                        sum -= curr;
                        ni = 1;
                    }
                    else if (nv > 1)
                    {
                        sum -= curr;
                        nv = 1;
                    }
                    output[oi++] = sum + 48;
                    sum = curr;
                }
            }
            else
                sum += curr;
            if (input[i+1] == '\0' && sum)
                output[oi++] = sum + 48;
        }
    }
    output[oi] = '\0';
}

int main()
{  char input[80],output[80];

   printf(" Input: ");
   gets(input);  /* read a line of characters from the input to "input" variable */

   roman2arabic(input,output);
   printf("Output: %s\n",output);

   return 0;
}