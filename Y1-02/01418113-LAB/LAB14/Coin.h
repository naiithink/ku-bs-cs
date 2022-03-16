#ifndef COIN_H
#define COIN_H

#include "RandomGenerator.h"

class Coin : public RandomGenerator
{
    public:
        // 0 | 1
        void random ();
        std::string translate ();
};

#endif