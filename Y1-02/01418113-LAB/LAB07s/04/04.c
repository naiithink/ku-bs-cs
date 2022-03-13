#include <stdio.h>
#include <string.h>

int main(void)
{
    int char_count = 0;
    int word_count = 0;

    scanf("%d\n\
%d\n", &char_count, &word_count);

    char prev[char_count+1];
    char curr[char_count+1];
    
    scanf("%s\n", prev);

    for (int i = 0, diff = 0, torn = 0; i < word_count; i++, diff = 0)
    {
        scanf("%s\n", curr);
        for (int j = 0; !torn && j < char_count; j++)
        {
            if (prev[j] != curr[j])
                diff++;
            if (diff > 2)
                torn = 1;
        }
        if (!torn)
            strcpy(prev, curr);
    }

    printf("%s\n", prev);

    return 0;
}