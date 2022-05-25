#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    char name[20];
    char out[20];
    double fbuf = 0;
    double in = 0;
    double sum = 0;

    cin >> name >> in;

    for (int i = 0; i < 12; i++)
    {
        cin >> fbuf;
        sum += in + fbuf * 0.15;
    }

    sprintf(out, "%s %.2f", name, sum);
    cout << out << endl;

    return 0;
}