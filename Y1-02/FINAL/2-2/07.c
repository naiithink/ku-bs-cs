/**
 * 7->3% ข้อ 7 (3%)
 */

#include <stdio.h>

int main(void)
{
    int n = 0;

    scanf ("%d", &n);

    int arr[n];
    int srt[n];
    int buffer = 0;

    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &buffer);
        arr[i] = buffer;
    }
    
    for (int i = 0, max = 0, here = 0; i < n; ++i, max = 0)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[j] && arr[j] > max)
            {
                max = arr[j];
                here = j;
            }
        }

        srt[i] = max;
        arr[here] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        printf ("%d\n", srt[i]);
    }

    return 0;
}