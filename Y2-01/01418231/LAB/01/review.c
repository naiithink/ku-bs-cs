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
    double rate_avg = 0.0;

    int i_buf = 0;
    double lf_buf = 0.0;
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
    review *record_min = NULL;
    review *record_max = NULL;

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
        double total_rate = 0.0;
        double current_rate = 0.0;
        int remain = ReviewRecords;
        int id = 0;
        review *record_p_cur = NULL;
        review *tmp = NULL;

        while (remain)
        {
            scanf("%lf %s", &lf_buf, c_arr_buf);

            if (lf_buf < RATE_MIN || lf_buf > RATE_MAX)
                continue;

            record_p_cur = records[id];

            record_p_cur->id = id + ID_START;
            record_p_cur->rate = lf_buf;
            strncpy(record_p_cur->reviewer, c_arr_buf, NAME_LEN);

            tmp = record_min;
            current_rate = record_p_cur->rate;

            total_rate += lf_buf;

            if (record_min != NULL && current_rate <= record_min->rate)
            {
                record_p_cur->next = record_min;
                record_min->prev = record_p_cur;
                record_min = record_p_cur;
            }
            else if (record_max != NULL && current_rate > record_max->rate)
            {
                record_p_cur->prev = record_max;
                record_max->next = record_p_cur;
                record_max = record_p_cur;
            }
            else if (id > ID_START)
            {
                while (tmp != NULL)
                {
                    if (current_rate > tmp->rate)
                    {
                        if (tmp->next != NULL && current_rate <= tmp->next->rate)
                        {
                            record_p_cur->prev = tmp;
                            record_p_cur->next = tmp->next;
                            tmp->next->prev = record_p_cur;
                            tmp->next = record_p_cur;
                        }
                        else if (tmp->next == NULL)
                        {
                            record_p_cur->prev = tmp;
                            tmp->next = record_p_cur;
                            record_max = record_p_cur;
                        }
                    }

                    tmp = tmp->next;
                }
            }
            else if (id == 0)
            {
                record_min = record_p_cur;
                record_max = record_p_cur;
            }
            else if (id == 1)
            {
                if (record_p_cur->rate <= tmp->rate)
                {
                    record_p_cur->next = tmp;
                    tmp->prev = record_p_cur;
                    record_min = record_p_cur;
                }
                else
                {
                    record_p_cur->prev = tmp;
                    tmp->next = record_p_cur;
                    record_max = record_p_cur;
                }
            }

            id++;
            remain--;
        }

        rate_avg = total_rate / ReviewRecords;
    }

    {
        review *tmp = record_max;

        printf("Average Score: %.2lf\n", rate_avg);
        while (tmp != NULL)
        {
            printf("%.2lf %s (id: %d)\n", tmp->rate, tmp->reviewer, tmp->id);
            tmp = tmp->prev;
        }
    }

    for (int i = 0; i < ReviewRecords; i++)
        free(records[i]);

    return 0;
}
