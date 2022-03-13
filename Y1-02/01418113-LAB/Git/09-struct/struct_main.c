#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE_T 255
#define STR_N 4
#define STRUCT_ELEM_N 6
#define COL_MAX 20

typedef int THB;

typedef struct
{
    char name[STR_SIZE_T];
    char developer[STR_SIZE_T];
    char category[STR_SIZE_T];
    THB thb_price;
    char iap[STR_SIZE_T];
    int stars;
}
App;

void removeSpace(char *str);
void indExceeding(char *str);

int main(void)
{
    // char line[30];
    // fgets(line, 29, stdin);
    // printf("struct %s", line);

    char sbuf[STR_N][STR_SIZE_T];
    THB dbuf = 0;
    int star_buf = 0;
    int app_number = 0;
    
    App apps[4];

    /* Import */
    while (1)
    {
        if (scanf("%s %s %s %d %s %d\n", sbuf[0], sbuf[1], sbuf[2], &dbuf, sbuf[3], &star_buf) == EOF)
            break;
        
        for (int i = 0; i < STR_N; i++)
        {
            removeSpace(sbuf[i]);
            indExceeding(sbuf[i]);
        }

        if (star_buf > 5 || star_buf < 0)
            star_buf = -1;
        
        if (dbuf < 0)
            dbuf = -1;
        
        strcpy(apps[app_number].name, sbuf[0]);
        strcpy(apps[app_number].developer, sbuf[1]);
        strcpy(apps[app_number].category, sbuf[2]);
        strcpy(apps[app_number].iap, sbuf[3]);
        apps[app_number].thb_price = dbuf;
        apps[app_number].stars = star_buf;
        app_number++;
    }

    /* Export */
    printf("\
%-8s\
%-24s\
%-24s\
%-24s\
%9s\
%15s\
%-4s\
%-15s\n", "ID", "NAME", "DEVELOPER", "CATEGORY", "STARS", "PRICE (THB)", "", "IN-APP PURCHASE");

    for (int i = 0; i < app_number; i++)
    {
        char star;
        if (apps[i].stars == -1)
            star = '?';
        else
            star = 48 + apps[i].stars;
        printf("\
%04d\
%-4s\
%-24s\
%-24s\
%-24s\
%8s\
%c\
% 15d\
%-4s\
%-15s\n", i+1, "", apps[i].name, apps[i].developer, apps[i].category, "", star, apps[i].thb_price, "", apps[i].iap);
    }

    return 0;
}

void removeSpace(char *str)
{
    if (!str)
        return;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '_')
            str[i] = 32;
    }
}

void indExceeding(char *str)
{
    if (!str)
        return;

    int len = 0;

    if ((len = strlen(str)) > COL_MAX)
    {
        str[COL_MAX-1] = '.';
        str[COL_MAX-2] = '.';
        str[COL_MAX-3] = '.';
        str[COL_MAX] = '\0';
    }
}