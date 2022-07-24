#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 32

typedef enum { false, true } bool;

typedef struct dish
{
    int listed;
    char name[STR_LEN];
    struct dish *next;
}
dish;

static dish *menu_start = NULL;

int main(void)
{
    dish *menu;
    char s_buff[STR_LEN] = "";

    dish *temp = menu_start;
    int index = 0;
    int id = 0;

    while (1)
    {
        // printf("> ");
        scanf("%s", s_buff);

        switch (s_buff[0])
        {
            case 'a':
                if (s_buff[1] == 'd'
                    && s_buff[2] == 'd'
                    && s_buff[3] == '\0')
                {
                    // printf("+ ");
                    scanf("%s", s_buff);

                    dish *adish = malloc(sizeof *adish);

                    if (menu_start == NULL)
                    {
                        menu_start = adish;
                        adish->next = NULL;
                    }
                    else
                    {
                        temp = menu_start;

                        while (temp->next != NULL)
                            temp = temp->next;

                        temp->next = adish;
                    }

                    strncpy(adish->name, s_buff, STR_LEN);
                    adish->listed = true;
                }

                break;
            case 'd':
                if (s_buff[1] == 'e'
                    && s_buff[2] == 'l'
                    && s_buff[3] == '\0')
                {
                    index = 0;
                    id = 0;
                    temp = menu_start;

                    // printf("+ ");
                    scanf("%s", s_buff);

                    index = strtol(s_buff, NULL, 10);

                    while (temp != NULL)
                    {
                        if ((id += temp->listed) == index)
                            break;

                        temp = temp->next;
                    }

                    if (temp != NULL && id == index)
                        temp->listed = false;
                }

                break;
            case 's':
                if (s_buff[1] == 'h'
                    && s_buff[2] == 'o'
                    && s_buff[3] == 'w'
                    && s_buff[4] == '\0')
                {
                    index = 0;
                    id = 0;
                    temp = menu_start;

                    printf("<< Menu >>\n");

                    while (temp != NULL)
                    {
                        if (temp->listed == true)
                            printf("%d. %s\n", id += temp->listed, temp->name);

                        temp = temp->next;
                    }
                }

                break;
            case 'e':
                if (s_buff[1] == 'x'
                    && s_buff[2] == 'i'
                    && s_buff[3] == 't'
                    && s_buff[4] == '\0')
                {
                    index = 0;
                    id = 0;
                    temp = menu_start;

                    printf("<< Menu >>\n");

                    while (temp != NULL)
                    {
                        if (temp->listed == true)
                            printf("%d. %s\n", id += temp->listed, temp->name);

                        temp = temp->next;
                    }

                    exit(0);
                }

                break;
        }
    }

    return 0;
}
