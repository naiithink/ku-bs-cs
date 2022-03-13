#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int amount = 50;
    int noteTypes = 4;
    int notes[] = {50, 20, 5, 1};
    int remain = amount;
    int noteCount[noteTypes];

    for (int i = 0; i < noteTypes; i++)
    {
        if (remain >= notes[i])
        {
            noteCount[i] = remain / notes[i];
        }
        else
        {
            noteCount[i] = 0;
        }
        remain = remain - noteCount[i] * notes[i];
    }

    for (int i = noteTypes-1; i > -1; i--)
    {
        printf("%i: %i\n", notes[i], noteCount[i]);
    }
}
