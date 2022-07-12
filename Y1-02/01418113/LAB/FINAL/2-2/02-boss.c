/**
 * 2->2% ข้อ 2 (2%)
 */

#include <stdio.h>
#include <stdlib.h>

int* make_it(int n, int d){
    int *result = (int *)malloc(sizeof(int) * n/d);
    int j = 0,i;
    for (i = d; i <= n; i++){
        if ((i % d) == 0){
            result[j] = i;
            j++;
        }
    }
    free(result);
    return result;
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