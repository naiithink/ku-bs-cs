#include <stdio.h>
#include <stdlib.h>

// int b_point > 0
// inherited from LAB03-05PB
void print_string(int n, int b_point)
{
    // safety first
    if (n > 26 || n <= 0)
    {
        printf("-\n");
        return;
    }

    int i = n, loop = 0, incre = -1;

    while (1)
    {
        printf("%c", i+96);
        if (i == b_point)
        {
            if (n == b_point)
            {
                break;
            }
            incre *= -1;
            loop++;
        }
        else if (loop == 1 && i == n)
        {
            break;
        }
        printf("-");
        i += incre;
    }
}

// find the print-out string length
int find_width(int n)
{
    return ((2 * n) - 1) + ((n - 1) * 2);
}

int main(void)
{
    char sym_chr = '-', N_str[3];
    int N = 0, width = 0, ether = 0, padding = 0;

    fgets(N_str, sizeof(N_str), stdin);
    N = atoi(N_str);

    if (!N || N > 26 || N < 0)
    {
        print_string(N, N+1);
        return 1;
    }

    width = find_width(N);

    // for (int stack = 0; stack < 2; stack++)
    {
        for (int row = 0; row < (2*N)-1; row++)
        {
            if (row >= N)
            {
                ether = (N - row - 2) * -1;
            }
            else
            {
                ether = N - row;
            }
            for (int sec = 0; sec < 3; sec++)
            {
                if (sec % 2)
                {
                    print_string(N, ether);
                }
                else
                {
                    padding = (width - find_width(N-ether+1)) / 2;
                    for (int i = 0; i < padding; i++)
                    {
                        printf("%c", sym_chr);
                    }
                    if (sec == 2)
                    {
                        printf("\n");
                    }
                }
            }
        }
    }

    return 0;
}