#include <stdio.h>

int main(void)
{
    char s[50];
    int count = 0;
    printf("String (without a space): ");
    scanf("%s", &s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
        {
            printf("%c ", s[i]);
            count++;
        }
    }
    printf("\nThis string contains %d %s.", count, count > 1 ? "vowels" : "vowel");
    return 0;
}