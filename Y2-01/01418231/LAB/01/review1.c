#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REVIEWER_NAME_LEN 64
#define RATE_MIN 1.0
#define RATE_MAX 5.0
#define ID_START 1

typedef struct item
{
    unsigned id;
    double rate;
    char reviewer[REVIEWER_NAME_LEN];
    struct item *prev;
    struct item *next;
}
item;

static unsigned ReviewRecords;
static unsigned recorded_reviews;
static item *review_data_starter;

int main(void)
{
    char s_buf[REVIEWER_NAME_LEN] = "";
    int i_buf = 0;
    double lf_buf = 0;
    int remain = 0;

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

    item review_data[ReviewRecords];
    item *item_ptr_cur = &review_data[0];

    review_data_starter = &review_data[0];
    remain = ReviewRecords = i_buf;

    for (int i = 0; i < ReviewRecords; i++)
    {
        review_data[i].prev = NULL;
        review_data[i].next = NULL;
    }

    {
        int id = 0;
        while (remain)
        {
            scanf("%lf %s", &lf_buf, s_buf);

            if (lf_buf < RATE_MIN || lf_buf > RATE_MAX)
                continue;

            review_data[id].id = id + ID_START;
            review_data[id].rate = lf_buf;

            printf("gotcha %d\n", remain);

            strncpy(review_data[id].reviewer, s_buf, strlen(s_buf));

            printf("gotcha %d\n", remain);

            if (id)
            {
                if (lf_buf < review_data_starter->rate)
                {
                    printf(">> gotcha %d\n", remain);

                    review_data[id].next = review_data_starter;
                    review_data_starter->prev = &review_data[id];
                    review_data_starter = &review_data[id];

                    printf("<< gotcha %d\n", remain);
                }
                else
                {
                    printf(">>> gotcha %d\n", remain);

                    item_ptr_cur = review_data_starter;

                    while (item_ptr_cur != NULL)
                    {
                        printf(">>>> gotcha %d\n", remain);
                        if (lf_buf > item_ptr_cur->rate && lf_buf < item_ptr_cur->next->rate)
                        {
                            review_data[id].prev = item_ptr_cur;
                            review_data[id].next = item_ptr_cur->next;
                            item_ptr_cur->next->prev = &review_data[id];
                            item_ptr_cur->next = &review_data[id];
                        }
                        else if (item_ptr_cur->next == NULL /* && lf_buf > item_ptr_cur->rate */)
                        {
                            review_data[id].prev = item_ptr_cur;
                            item_ptr_cur->next = &review_data[id];
                        }

                        item_ptr_cur = item_ptr_cur->next;
                        printf("<<<< gotcha %d\n", remain);
                    }

                    printf("<<< gotcha %d\n", remain);
                }
            }

            id++;
            remain--;
        }
    }

    // for (int i = 0; i < ReviewRecords; i++)
    //     if (review_data[i]->prev == NULL)
    //         item_ptr_cur = review_data[i];

    item_ptr_cur = review_data_starter;

    while (item_ptr_cur != NULL)
    {
        printf("%.2lf %s (id: %u)\n", item_ptr_cur->rate, item_ptr_cur->reviewer, item_ptr_cur->id);
        item_ptr_cur = item_ptr_cur->next;
    }

    return 0;
}
