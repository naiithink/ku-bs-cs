#include <iostream>
#include "RandomGenerator.h"
#include "Coin.h"

using namespace std;

int
main (void)
{
    RandomGenerator *generator = new RandomGenerator ();

    for (int i = 0; i < 10; ++i)
    {
        generator->random ();
        cout << generator->getResult () << " ";
    }
    cout << endl;

    Coin *coin = new Coin ();

    for (int i = 0; i < 10; ++i)
    {
        coin->random ();
        cout << coin->getResult () << " "
             << "(" << coin->translate () << ")" << " - ";
    }
    cout << endl;

    RandomGenerator *coinGenerator = new Coin ();

    for (int i = 0; i < 10; ++i)
    {
        coinGenerator->random ();
        cout << coinGenerator->getResult () << ", ";
    }
    cout << endl;

    delete generator;
    delete coin;
    delete coinGenerator;

    return 0;
}