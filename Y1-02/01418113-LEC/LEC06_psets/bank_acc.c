#include <stdio.h>

struct account {
    int number;
    float balance;
};

void show_account(struct account act) {
    printf("ACCT %d BAL %.2f\n",
            act.number, act.balance);
}

int main(void) {
    struct account my_act = { 1, 100.0 };
    show_account(my_act);

    return 0;
}