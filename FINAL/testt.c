#include <stdio.h>
#include <string.h>
#include <ctype.h>

// char *trimwhitespace(char *str) {
//     char *end;
//     while(isspace((unsigned char)*str)) str++;
//     if(*str == 0) return str;
//     end = str + strlen(str) - 1;
//     while(end > str && isspace((unsigned char)*end)) end--;
//     end[1] = '\0';
//     return str;
// }

void func(void)
{
    char tt[100];
    char *buff;
    while (1)
    {
        scanf("%s", buff);

        if (!strcmp(buff, "."))
        {
            break;
        }

        strcat(tt, buff);
    }

    printf("%s\n", tt);

}

int main(void)
{
    //char s[] = " hello ";
//
    //printf("%s", s);
    //printf("!\n");
//
    //// while(isspace((unsigned char) *s)) s++;
//
    //char *s1 = trimwhitespace(s);
//
    //printf("%s", s1);
    //printf("!\n");

    func();

    return 0;
}