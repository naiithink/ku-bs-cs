#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

int merged_is_odd;
int *non_empty_int_arr;
int non_empty_int_arr_len;

void pretty_print(float);
float get_int_arr_med_unary(int *, int);
float get_int_arr_med_binary(int *, int, int *, int);

int main(void)
{
    float med = 0.0f;
    int ia_a[MAX_LEN] = {0};
    int ia_b[MAX_LEN] = {0};

    int a_len = 0;
    int b_len = 0;

    scanf("%i %i", &a_len, &b_len);

    if (a_len < 0 || b_len < 0 || (!a_len && !b_len))
        return 0;

    // Array A in
    for (int i = 0, lim = a_len - 1; i < lim; ++i)
        scanf("%i%*[^ ]%*s", &ia_a[i]);

    if (a_len >= 1)
        scanf("%i", &ia_a[a_len - 1]);
    else
        scanf("%*[\n]");

    // Array B in
    for (int i = 0, lim = b_len - 1; i < lim; ++i)
        scanf("%i%*[^ ]%*s", &ia_b[i]);

    if (b_len >= 1)
        scanf("%i", &ia_b[b_len - 1]);
    else
        scanf("%*[^\n]s");

    // Oddity
    if ((a_len + b_len) % 2)
        merged_is_odd = 1;
    else
        merged_is_odd = 0;

    // If there empty
    if (a_len * b_len == 0)
    {
        non_empty_int_arr = a_len == 0 ? ia_b
                                       : ia_a;
        non_empty_int_arr_len = a_len == 0 ? b_len
                                           : a_len;

        med = get_int_arr_med_unary(non_empty_int_arr, non_empty_int_arr_len);
    }
    else
        med = get_int_arr_med_binary(ia_a, a_len, ia_b, b_len);

    pretty_print(med);

    return 0;
}

void pretty_print(float num)
{
    if (num != (int) num)
        printf("%.1f\n", num);
    else
        printf("%.0f\n", num);
}

float get_int_arr_med_unary(int *int_arr, int len)
{
    if (!*int_arr)
        return 0.0f;

    float res = 0.0f;
    int l = len / 2;

    if (merged_is_odd)
        return int_arr[len / 2];
    else
        res = (int_arr[l] + int_arr[l - 1]) / 2;

    return res;
}

float get_int_arr_med_binary(int *arr1, int arr1_len, int *arr2, int arr2_len)
{
    if (!arr1 || !arr2)
        return 0.0f;

    int merged_arr_len = arr1_len + arr2_len;

    int offset = 0;
    int lim = ((int) merged_arr_len / 2) + 1;

    int *arr1_term = arr1 + arr1_len;
    int *arr2_term = arr2 + arr2_len;

    int l = 0;
    int r = 0;

    while (offset < lim)
    {
        l = r;

        if ((arr1 < arr1_term && *arr1 <= *arr2) || arr2 >= arr2_term)
            r = *arr1++;
        else
            r = *arr2++;

        offset++;
    }

    if (merged_is_odd)
        return r;
    else
        return (float) (l + r) / 2;
}
