#include <iostream>
using namespace std;

class Animal
{
private:
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

int main()
{
    Animal cat(50, 50, 50);

    cout << cat.getHappiness() << endl;
    cout << cat.getEnergy() << endl;
    cout << cat.getFullness() << endl;

    cout << endl;
    cat.eat(51);
    cout << cat.getHappiness() << endl;
    cout << cat.getEnergy() << endl;
    cout << cat.getFullness() << endl;

    cout << endl;
    cat.play(2);
    cout << cat.getHappiness() << endl;
    cout << cat.getEnergy() << endl;
    cout << cat.getFullness() << endl;

    cout << endl;
    cat.sleep(1);
    cout << cat.getHappiness() << endl;
    cout << cat.getEnergy() << endl;
    cout << cat.getFullness() << endl;

    return 0;
}