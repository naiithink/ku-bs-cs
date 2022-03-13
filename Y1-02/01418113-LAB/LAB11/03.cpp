#include <iostream>
using namespace std;

class Animal
{
protected:
    int happiness;
    int energy;
    int fullness;
    const int MAX_HAPPINESS = 100;
    const int MAX_ENERGY = 100;
    const int MAX_FULLNESS = 100;
    void limitStat();
public:
    Animal(int, int, int);
    int getHappiness();
    int getEnergy();
    int getFullness();
    void eat(int);
    void play(int);
    void sleep(int);
};

class Bird : public Animal
{
public:
    Bird(int, int, int);
    void fly(int);
    void sing();
};

Animal::Animal(const int happiness, const int energy, const int fullness)
{
    this->happiness = happiness;
    this->energy = energy;
    this->fullness = fullness;

    limitStat();
}

inline void Animal::limitStat()
{
    if (fullness < 0)
    {
        fullness = 0;
    }
    else if (fullness > MAX_FULLNESS)
    {
        fullness = MAX_FULLNESS;
    }
    
    if (happiness < 0)
    {
        happiness = 0;
    }
    else if (happiness > MAX_HAPPINESS)
    {
        happiness = MAX_HAPPINESS;
    }

    if (energy < 0)
    {
        energy = 0;
    }
    else if (energy > MAX_ENERGY)
    {
        energy = MAX_ENERGY;
    }
}

int Animal::getHappiness()
{
    return happiness;
}

int Animal::getEnergy()
{
    return energy;
}

int Animal::getFullness()
{
    return fullness;
}

void Animal::eat(const int food)
{
    if (food < 0)
    {
        return;
    }

    fullness += food;

    if (fullness > MAX_FULLNESS)
    {
        happiness -= 10;
    }

    limitStat();
}

void Animal::play(const int hour)
{
    if (hour < 0)
    {
        return;
    }

    if (energy > 0)
    {
        energy -= hour * 10;
        fullness -= hour * 20;
        happiness += hour * 5;
    }

    limitStat();
}

void Animal::sleep(const int hour)
{
    if (hour < 0)
    {
        return;
    }

    energy += hour * 10;
    fullness -= hour * 10;

    limitStat();
}

Bird::Bird(const int happiness, const int energy, const int fullness)
: Animal(happiness, energy, fullness)
{
    // done construction
}

void Bird::fly(const int hour)
{
    const int consume = 5;

    if (hour < 0 || energy < (hour * consume))
    {
        return;
    }

    energy -= hour * consume;

    limitStat();
}

void Bird::sing()
{
    happiness += 5;

    limitStat();
}

int main()
{
    Bird grinny(50, 50, 50);

    cout << grinny.getHappiness() << endl;
    cout << grinny.getEnergy() << endl;
    cout << grinny.getFullness() << endl;

    cout << endl;
    grinny.fly(11);
    cout << grinny.getHappiness() << endl;
    cout << grinny.getEnergy() << endl;
    cout << grinny.getFullness() << endl;

    cout << endl;
    grinny.sing();
    cout << grinny.getHappiness() << endl;
    cout << grinny.getEnergy() << endl;
    cout << grinny.getFullness() << endl;

    return 0;
}