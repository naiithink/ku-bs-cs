#include <iostream>
#include "Dice.h"

void
Dice::random ()
{
    p = &Dice::random;
    // result = ((&p % 6) + 1);
    std::cout << &p << std::endl;
}