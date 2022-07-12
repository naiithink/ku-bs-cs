#include <iostream>
#include "person.h"

using namespace std;

Person::Person(const string name)
{
    this->name = name;
}

string Person::getName(void)
{
    return name;
}

void Person::setName(const string name)
{
    this->name = name;
}
