#include <stdio.h>

struct account
{
    int number;
    float balance;
};

struct customer
{
    int national_id;
    struct account customer_account;
};

int main(void)
{
    struct customer nai;
    nai.national_id = 12345;
    nai.customer_account.number = 123;
    nai.customer_account.balance = 10000001.0;

    printf("\
ID  : %d\n\
NO  : %d\n\
BAL : %.2f\n"\
, nai.national_id, nai.customer_account.number, nai.customer_account.balance);

    printf("%d %d %.2f\n", nai);
}