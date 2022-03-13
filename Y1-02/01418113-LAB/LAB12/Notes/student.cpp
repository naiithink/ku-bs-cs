#include <iostream>
#include "student.h"

using namespace std;

Student::Student(const string name, const string id)
{
    this->name = name;
    this->id = id;
}

string Student::getName(void)
{
    return name;
}

double Student::getScore(void)
{
    return score;
}

void Student::setName(const string name)
{
    this->name = name;
}

void Student::addScore(const double score)
{
    this->score = score;
}