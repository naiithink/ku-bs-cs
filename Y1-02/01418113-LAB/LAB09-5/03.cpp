#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int num = 0;

    cin >> num;

    int pris[num];
    int odd[num] = { 0 };
    int even[num] = { 0 };
    int maxx = 0;
    int oi = 0;
    int ei = 0;

    for (int i = 0, index = 0; i < num; i++)
    {
        cin >> pris[i];
        if (pris[i] > maxx)
            maxx = pris[i];
    }

    sort(pris, pris + num);

    int numm[maxx] = { 0 };

    for (int i = 0, index = 0; i < num; i++)
    {
        index = pris[i] - 1;
        numm[index] = pris[i];
    }

    for (int i = 0, val = 0; i < maxx; i++)
    {
        val = numm[i];
        if (!val)
        {
            if (i % 2)
                even[ei++] = i + 1;
            else
                odd[oi++] = i + 1;
        }
    }

    for (int i = 0; i < oi; i++)
    {
        if (odd[i])
            cout << odd[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ei; i++)
    {
        if (even[i])
            cout << even[i] << " ";
    }
    cout << endl;

    return 0;
}