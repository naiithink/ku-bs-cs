#include <stdio.h>

typedef struct account {
    int number;
    float balance;
} BankAccount;

void deposit(struct account act, float amount) {
    act.balance = act.balance + amount;
}

int main(void) {
    BankAccount my_act = { 1, 100.0 };
    deposit(my_act, 50);

    printf("%.2f\n", my_act.balance);

    return 0;
}