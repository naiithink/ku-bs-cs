#include <iostream>
#include "Coin.h"

using namespace std;

// 0 | 1
void
Coin::random ()
{
    result = rand () % 2;
}

string
Coin::translate ()
{
    string res;

    switch (result)
    {
        case 0:
            res = "HEAD";
        case 1:
            res = "TAIL";
    }

    return res;
}