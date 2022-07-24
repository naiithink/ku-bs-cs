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
    struct item *start;
}
item;

static unsigned ReviewRecords;
static unsigned recorded_reviews;
static item *review_data_starter;

int main(void)
{
    char *s_buf = NULL;
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

    printf("gotcha\n");

    remain = ReviewRecords = i_buf;
    item *review_data[ReviewRecords];
    item *item_ptr_min = review_data[0];
    item *item_ptr_max = NULL;
    item *item_ptr_cur = NULL;

    for (int i = 0; i < ReviewRecords; i++)
    {
        review_data[i]->start = &review_data_starter;
        review_data[i]->prev = NULL;
        review_data[i]->next = NULL;
    }

    printf("gotcha\n");

    {
        int id = 0;
        while (remain)
        {
            scanf("%lf %s", &lf_buf, s_buf);

            if (lf_buf < RATE_MIN || lf_buf > RATE_MAX)
                continue;


            review_data[id]->id = id + ID_START;
            review_data[id]->rate = lf_buf;
            strncpy(review_data[id]->reviewer, s_buf, REVIEWER_NAME_LEN);

            if (lf_buf < item_ptr_min->rate)
            {
                review_data[id]->next = item_ptr_min;
                item_ptr_min->prev = review_data[id];
                item_ptr_min = review_data[id];
            }
            else if (item_ptr_min->next == NULL && lf_buf > item_ptr_min->rate)
            {
                review_data[id]->prev = item_ptr_min;
                item_ptr_min->next = review_data[id];
                item_ptr_max = review_data[id];
            }
            else if (lf_buf > item_ptr_max->rate)
            {
                review_data[id]->prev = item_ptr_max;
                item_ptr_max->next = review_data[id];
                item_ptr_max = review_data[id]
            }
            else
            {
                item_ptr_cur = item_ptr_min;
                while (item_ptr_cur->next != NULL)
                {
                    if (lf_buf > item_ptr_cur->rate && lf_buf < item_ptr_cur->next->rate)
                    {
                        
                    }
                    else if (lf_buf < item_ptr_cur->rate)
                    {
                        review_data[id]->next = item_ptr_cur;
                        item_ptr_min = review_data[id];
                    }
                }
            }

            id++;
            remain--;
        }
    }

    for (int i = 0; i < ReviewRecords; i++)
        if (review_data[i]->prev == NULL)
            item_ptr_cur = review_data[i];
    
    while (item_ptr_cur->next != NULL)
    {
        printf("%.2lf %s (id: %u)\n", item_ptr_cur->rate, item_ptr_cur->reviewer, item_ptr_cur->id);
        item_ptr_cur = item_ptr_cur->next;
    }

    return 0;
}
