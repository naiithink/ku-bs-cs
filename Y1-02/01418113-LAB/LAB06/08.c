#include <stdio.h>

void removeKilled(int *array, int size, int killedPrisoner);

int main()
{
    int numPrisoners, m, i;

    scanf("%d", &numPrisoners);
    scanf("%d", &m);

    int prisoners[numPrisoners];
    int killed[numPrisoners];

    // generate array 1 to numPrisoners
    for (i = 0; i < numPrisoners; i++)
    {
        prisoners[i] = i + 1;
    }

    int *killerPtr = &prisoners[0];

    // printf("@@ &prisoners[0] %d\n", (int) &prisoners[0]);
    // printf("@@ &prisoners[%d] %d\n", numPrisoners - 1, (int) &prisoners[numPrisoners - 1]);

    // Select prisoner to be killed
    for (i = 0; i < numPrisoners; i++)
    {
        int count = 0;
        int *max_p = &prisoners[0] + (numPrisoners - 1);
        int exceeding = 0;

        if (i == 0)
            killerPtr += m - 1;
        else
        {
            while (count < m || !(*killerPtr))
            {
                exceeding = (killerPtr + 1) - max_p;
                if (exceeding > 0)
                    killerPtr = &prisoners[0] + (exceeding - 1);
                else
                    killerPtr++;
                if (*killerPtr)
                    count++;
            }
        }
        
        // append number of prisoner who is killed to array `killed`
        killed[i] = *killerPtr;
        // remove number killed prisoner from array `prisoners`
        removeKilled(&prisoners[0], numPrisoners, *killerPtr);
    }

    for (i = 0; i < numPrisoners; i++)
    {
        printf("%d ", killed[i]);
    }
}

void removeKilled(int *array, int size, int killedPrisoner)
{
    for (int i = 0; i < size; i++, array++)
    {
        if (*array == killedPrisoner)
        {
            *array = 0;
            return;
        }
    }
}