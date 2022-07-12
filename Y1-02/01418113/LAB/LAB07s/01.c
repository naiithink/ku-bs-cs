#include <stdio.h>

int main(void)
{
    char buff[255];
    int vowel[] = { 65, 69, 73, 79, 85, 97, 101, 105, 111, 117 };
    int count = 0;

    printf("String (without a space): ");
    scanf("%s", buff);

    for (int i = 0; buff[i] != '\0'; i++)
    {
        for (int j = 0, n = sizeof(vowel)/sizeof(int); j < n; j++)
        {
            if (buff[i] == vowel[j])
            {
                printf("%c ", buff[i]);
                count++;
            }
        }
    }
    printf("\n");

    printf("This string contains %d vowel%c.\n", count, count > 1 ? "s" : "");

    return 0;
}