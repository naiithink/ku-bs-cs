#include <stdio.h>

void removeTarget(int *array, int size, int target);

int main()
{
    int num, count, target, i;

    scanf("%d", &num);
    scanf("%d", &count);

    int numbers[num];
    int *numbersPtr = &numbers[0];

    // initialize array numbers from 1 to num by numbersPtr
    for (int i = 1, *bp = numbersPtr+num; numbersPtr < bp; numbersPtr++, i++) {
        *numbersPtr = i;
    }

    // loop through count
    for (int i = 0; i < count; i++) {
        scanf("%d", &target);
        removeTarget(&numbers[0], num, target);
    }

    numbersPtr = &numbers[0];

    // print elements in numbers using numberPtr
    for (int *bp = numbersPtr+num; numbersPtr < bp; numbersPtr++) {
        printf("%d ", *numbersPtr);
    }
    puts("");
}

// remove target from array by pointer *array and append last position by 0
void removeTarget(int *array, int size, int target)
{
    for (int i = 0, found = 0; i < size; i++, array++)
    {
        if (*array == 0)
            return;
        else if (found || *array == target)
        {
            *array = *(array+1);
            found = 1;
            if (i+1 == size)
                *array++ = 0;
        }
    }
}