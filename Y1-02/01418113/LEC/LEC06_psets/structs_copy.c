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
    struct account acct = {123, 10000001.0};
    struct customer nai;
    nai.national_id = 12345;
    nai.customer_account = acct;

    printf("\
ID  : %d\n\
NO  : %d\n\
BAL : %.2f\n"\
, nai.national_id, nai.customer_account.number, nai.customer_account.balance);

    nai.national_id = 12345;
    nai.customer_account.number = 0;

    printf("\
ID  : %d\n\
NO  : %d\n\
BAL : %.2f\n"\
, nai.national_id, nai.customer_account.number, nai.customer_account.balance);

    printf(">>> acct: %d, %.2f\n", acct.number, acct.balance);

    printf("%ld\n", sizeof(nai));

    return 0;
}