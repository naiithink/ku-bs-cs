#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REVIEWER_NAME_LEN 64
#define RATE_MIN 1.0
#define RATE_MAX 5.0

typedef struct
{
    unsigned id;
    double rate;
    char reviewer[REVIEWER_NAME_LEN];
}
item;

static unsigned ReviewRecords;
static unsigned recorded_reviews;

int main(void)
{
    int d_buf = 0;

    scanf("%d", &d_buf);

    if (d_buf < 0)
    {
        fprintf(stderr, "ERROR\n");
        return 1;
    }
    else if (d_buf == 0)
    {
        printf("No reviews found\n");
        return 0;
    }

    ReviewRecords = d_buf;
    item review_data[ReviewRecords];
    item *ordered_reviews[ReviewRecords];

    for (int i = 0; i < ReviewRecords; i++)
        ordered_reviews[i] = NULL;

    for (int i = 0; i < ReviewRecords; i++)
    {
        int f_buf = 0;
        char s_buf[REVIEWER_NAME_LEN];
        item *hold = NULL;
        item *temp = NULL;
        item *head = NULL;
        item *next = NULL;

        scanf("%d %s", &f_buf, s_buf);

        if (f_buf < RATE_MIN || f_buf > RATE_MAX || strlen(s_buf) > REVIEWER_NAME_LEN)
        {
            i--;
            continue;
        }

        review_data[recorded_reviews].id = recorded_reviews + 1;
        review_data[recorded_reviews].rate = f_buf;
        strcpy(review_data[recorded_reviews].reviewer, s_buf);

        hold = &review_data[recorded_reviews];

        for (int ii = 0; ii < ReviewRecords; ii++)
        {
            if (ordered_reviews[ii+1] == NULL)
                break;

            head = ordered_reviews[ii]->rate;
            next = ordered_reviews[ii+1]->rate;

            if (head->rate <= next->rate)
                continue;
            else
            {
                temp = head;
                head = hold;
            }
        }

        recorded_reviews++;
    }

    return 0;
}
