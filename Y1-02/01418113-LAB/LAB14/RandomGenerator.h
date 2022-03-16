#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

class RandomGenerator
{
    public:
        virtual void random ();
        int getResult ();

    protected:
        int result;
};

#endif