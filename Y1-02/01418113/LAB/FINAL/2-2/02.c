/**
 * 2->2% ข้อ 2 (2%)
 * passed 100
 */

#include <stdio.h>
#include <stdlib.h>

int *
make_it (int n, int d)
{
    int *res;
    int *resarr;
    int *arr;
    int ind = 0;

    arr = (int *) malloc (sizeof(int) * n);

    for (int i = 1, lim = n + 1; i < lim; ++i)
    {
        if (!(i % d))
        {
            arr[ind++] = i;
        }
    }

    resarr = (int *) malloc (sizeof(int) * (ind + 1));

    for (int i = 0; i < ind; ++i)
    {
        resarr[i] = arr[i];
    }

    res = resarr;
    free (arr);
    free (resarr);
    return res;
}

void print_array(int* array, int size);

int main(int argc, char **argv)
{
    // int n, d;
    int n = atoi(argv[1]);
    int d = atoi(argv[2]);
    // scanf("%d %d", &n, &d);
    int* array = make_it(n, d);
    print_array(array, n / d);
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d,", array[i]);
    }
}