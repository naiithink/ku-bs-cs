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

class Pet
{
protected:
    string name;
public:
    Pet(string);
    string getName();
    void setName(string);
};

class OwnedBird : public Bird, public Pet
{
public:
    OwnedBird(string, int, int, int);
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

// Bird
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

// Pet
Pet::Pet(const string name)
{
    this->name = name;
}

string Pet::getName()
{
    return name;
}

void Pet::setName(const string name)
{
    this->name = name;
}

// OwnedBird
OwnedBird::OwnedBird(const string name, const int happiness, const int energy, const int fullness)
: Bird(happiness, energy, fullness), Pet(name)
{
    // done construction
}

int main()
{
char action;
    int hour;
    int happiness, energy, fullness;
    cin >> happiness >> energy >> fullness;
    OwnedBird animal("Dobby", happiness, energy, fullness);
    while (1) {
        cin >> action;
        if (action == 'q') break;
        cin >> hour;
        switch (action) {
            case 'e':
                animal.eat(hour);
                break;
            case 'p':
                animal.play(hour);
                break;
            case 's':
                animal.sleep(hour);
                break;
            case 'f':
                animal.fly(hour);
                break;
            case 'i':
                for (int i = 0; i < hour; i++)
                    animal.sing();
                break;
            case 'n':
                if (hour < 5)
                    animal.setName("Debby");
                else
                    animal.setName("Shogun");
                break;
        }
        // test(animal);
    }
}