#include <stdio.h>

int remove_vowel(char *str)
{
    int vowel[] = { 65, 69, 73, 79, 85, 97, 101, 105, 111, 117 };
    int new_i = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0, n = (sizeof(vowel)/sizeof(int))+1, found = 0; j < n && !found; j++)
        {
            if ((j+1) == n)
                str[new_i++] = str[i];
            else if (str[i] == vowel[j])
                found = 1;
        }
    }
    str[new_i] = '\0';

    return 1;
}

int main()
{
    char str[80];

    printf(" Input: ");
    gets(str);

    remove_vowel(str);
    printf("Output: %s\n", str);

    return 0;
}