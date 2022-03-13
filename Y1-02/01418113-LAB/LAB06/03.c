#include <stdio.h>
#define ARRAY_SIZE 98

int main()
{
    int i, j;
    int A[ARRAY_SIZE] = {0};

    for (i = 2; i < ARRAY_SIZE; i++)
        A[i] = 1;

    for (i = 2, A[i] = i, j = i+1; !((i*i) > ARRAY_SIZE); j++) {
        if (j >= ARRAY_SIZE)
        {
            i++;
            if (A[i] == i)
                j = i + 1;
            else
                continue;
        }
        if (!(j%i))
            A[j] = 0;
        else if (A[j])
            A[j] = j;
    }

    for (i = 2; i < ARRAY_SIZE; i++)
        if (A[i])
            printf("%d ", A[i]);
    
    printf("\n");

  return 0;
}