#include <stdio.h>
#include <wchar.h>

#define STR_LEN 128

#define GET_INPUT 3

struct flower
{
    wchar_t id[STR_LEN];
    wchar_t name[STR_LEN];
    double cost;
    wchar_t district[STR_LEN];
    wchar_t province[STR_LEN];
};

int main(void)
{
    struct flower flowers[GET_INPUT];

    wchar_t s_buff[STR_LEN];
    double lf_buff = 0.0;

    printf("You will be, in turn, asked to enter infos about %d flower", GET_INPUT);
    if (GET_INPUT > 1)
        printf("s.\n");
    else
        printf(".\n");

    for (int i = 0; i < GET_INPUT; i++)
    {
        printf("\n");
        printf("<<<<< #%d <<<<<\n", i + 1);

        printf("ID:   ");
        fgetws(flowers[i].id, STR_LEN, stdin);

        fflush(stdin);

        printf("Name: ");
        fgetws(flowers[i].name, STR_LEN, stdin);

        fflush(stdin);

        printf("Cost: ");
        scanf("%lf", &flowers[i].cost);

        fflush(stdin);

        printf("LOCALE\n");

        printf("- District: ");
        fgetws(flowers[i].district, STR_LEN, stdin);

        fflush(stdin);

        printf("- Province: ");
        fgetws(flowers[i].province, STR_LEN, stdin);

        for (int i = 0; i < GET_INPUT; i++)
        {
            for (int j = 0; j < STR_LEN; j++)
                if (flowers[i].id[j] == '\n')
                    flowers[i].id[j] = '\0';

            for (int j = 0; j < STR_LEN; j++)
                if (flowers[i].name[j] == '\n')
                    flowers[i].name[j] = '\0';

            for (int j = 0; j < STR_LEN; j++)
                if (flowers[i].district[j] == '\n')
                    flowers[i].district[j] = '\0';

            for (int j = 0; j < STR_LEN; j++)
                if (flowers[i].province[j] == '\n')
                    flowers[i].province[j] = '\0';
        }

        fflush(stdin);
    }

    printf("\n>>>>> Summary >>>>>\n");

    for (int i = 0; i < GET_INPUT; i++)
        printf("\
#%- 4d   ID:       %ls\n\
        Name:     %ls\n\
        Cost:     %.2lf\n\
        Locale:   %ls, %ls\n", i + 1, flowers[i].id, flowers[i].name, flowers[i].cost, flowers[i].district, flowers[i].province);

    return 0;
}
