#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 32
#define CMD_LEN 5

typedef enum { false, true } bool;

typedef struct dish
{
    int listed;
    char name[STR_LEN];
    struct dish *next;
}
dish;

static dish *menu_start = NULL;

void fprint_list(FILE *restrict stream);

int main(void)
{
    char cmd[][CMD_LEN] = { "add", "del", "show", "exit" };

    char s_buff[STR_LEN] = "";
    int index = 0;
    int id = 0;

    dish *temp = menu_start;

    while (true)
    {
        // printf("> ");
        // fgets(s_buff, STR_LEN, stdin);
        scanf("%s", s_buff);

        if (!strncmp(s_buff, cmd[0], CMD_LEN))
        {
            // printf("+ ");
            // fgets(s_buff, STR_LEN, stdin);
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
        else if (!strncmp(s_buff, cmd[1], CMD_LEN))
        {
            index = 0;
            id = 0;
            temp = menu_start;

            // printf("+ ");
            // fgets(s_buff, STR_LEN, stdin);
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
        else if (!strncmp(s_buff, cmd[2], CMD_LEN))
        {
            fprint_list(stdout);
        }
        else if (!strncmp(s_buff, cmd[3], CMD_LEN))
        {
            fprint_list(stdout);
            exit(0);
        }
    }

    return 0;
}

void fprint_list(FILE *restrict stream)
{
    int id = 0;
    dish *temp = menu_start;

    fprintf(stream, "<< Menu >>\n");

    while (temp != NULL)
    {
        if (temp->listed == true)
            fprintf(stream, "%d. %s\n", id += temp->listed, temp->name);

        temp = temp->next;
    }
}
