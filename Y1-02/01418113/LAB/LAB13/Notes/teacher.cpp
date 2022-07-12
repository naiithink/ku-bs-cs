#include <iostream>
#include "teacher.h"

using namespace std;

Teacher::Teacher(const string name)
{
    this->name = name;
}

string Teacher::getName(void)
{
    return name;
}

void Teacher::setName(const string name)
{
    this->name = name;
}

void Teacher::giveScore(Student student, const double score)
{
    student.addScore(score);
}

void Teacher::giveScore(Student *student, const double score)
{
    student->addScore(score);
}