#ifndef DICE_H
#define DICE_H

#include "RandomGenerator.h"

class Dice : public RandomGenerator
{
    public:
        void random ();
        void (Dice::*p) ();
};

#endif