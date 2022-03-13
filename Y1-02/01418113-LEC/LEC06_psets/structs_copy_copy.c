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
    struct customer nai[2];
    nai[0].national_id = 12345;
    nai[0].customer_account.number = 123;
    nai[0].customer_account.balance = 10000001.0;

    nai[1].national_id = 12349;
    nai[1].customer_account.number = 126;
    nai[1].customer_account.balance = 0.0;

    printf("\
ID  : %d\n\
NO  : %d\n\
BAL : %.2f\n"\
, nai[0].national_id, nai[0].customer_account.number, nai[0].customer_account.balance);

    fputs("\n", stdout);

    printf("\
ID  : %d\n\
NO  : %d\n\
BAL : %.2f\n"\
, nai[1].national_id, nai[1].customer_account.number, nai[1].customer_account.balance);

    printf("%ld\n", sizeof(nai));
    return 0;
}