#include <stdio.h>
#include <stdlib.h>

#define NUM_STR_SIZE 11
#define EXPO 2

int main(void)
{
    char number_str[NUM_STR_SIZE];
    unsigned long long number = 0, prt = 0, digit_count = 0, res = 0, res_i = 0, is_automorphic = 0;

    fputs("Input n = ", stdout);
    fgets(number_str, NUM_STR_SIZE, stdin);
    if ((number=atoi(number_str)) <= 0 || number > 100000000)
        return 1;
    res = number;
    prt = number;

    if (number <= 0)
        return 1;

    { /* LOCAL */
        long unsigned int n = number;
        while (n)
        {
            n /= 10;
            digit_count++;
        }
    }

    long unsigned int number_dig[digit_count], res_dig[digit_count];

    for (long unsigned int i = 1; i < EXPO; i++)
    {
        res *= number;
    }

    res_i = res;

    for (long unsigned int i = 0; i < digit_count; i++)
    {
        if ((number_dig[i] = number%10) != (res_dig[i]=res_i%10))
        {
            is_automorphic = 0;
            break;
        }
        number /= 10;
        res_i /= 10;
        is_automorphic = 1;
    }

    printf("n^2 = %lli\n", res);
    if (is_automorphic)
        printf("Yes. %lli is automorphic number.\n", prt);
    else
        printf("No. %lli is not automorphic number.\n", prt);

    return 0;
}