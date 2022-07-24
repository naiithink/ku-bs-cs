#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DNE (int) -1
#define NAME_LEN (size_t) 32

#define RATE_MIN (double) 1.0
#define RATE_MAX (double) 5.0
#define ID_START (int) 1

typedef struct review
{
    int id;
    double rate;
    char reviewer[NAME_LEN];
    struct review *prev;
    struct review *next;
}
review;

int main(void)
{
    register unsigned ReviewRecords = 0;

    int i_buf = 0;
    double lf_buf = 0;
    char c_arr_buf[NAME_LEN] = "";

    scanf("%d", &i_buf);

    if (i_buf < 0)
    {
        /* fprintf(stderr, "ERROR\n"); */
        printf("ERROR\n");
        /* exit(1); */
        exit(0);
    }
    else if (i_buf == 0)
    {
        printf("No reviews found\n");
        exit(0);
    }

    ReviewRecords = i_buf;

    review *records[ReviewRecords];
    review *record_start = NULL;

    for (int i = 0; i < ReviewRecords; i++)
    {
        records[i] = malloc(sizeof *records[i]);
        records[i]->prev = NULL;
        records[i]->next = NULL;
        records[i]->id = DNE;
        records[i]->rate = DNE;
        strncpy(records[i]->reviewer, c_arr_buf, NAME_LEN);
    }

    {
        int remain = ReviewRecords;
        int id = 0;

        while (remain)
        {
            scanf("%lf %s", &lf_buf, c_arr_buf);

            if (lf_buf < RATE_MIN || lf_buf > RATE_MAX)
                continue;

            printf("gotcha\n");
            records[id]->id = id + ID_START;
            records[id]->rate = lf_buf;
            strncpy(records[id]->reviewer, c_arr_buf, NAME_LEN);

            if (id > 0)
            {
                int i = 0;
                review *tmp = record_start;

                while (records[id] != NULL)
                {
                    if ()
                }
            }
            else
                record_start = records[id];

            printf("%d\n", ii);

            id++;
            remain--;
        }
    }

    // printf("%lu\n", sizeof *records);

    for (int i = 0; i < ReviewRecords; i++)
    {
        printf("%d\n", records[i]->id);
        printf("%f\n", records[i]->rate);
        printf("%s\n", records[i]->reviewer);
        free(records[i]);
    }

    return 0;
}
