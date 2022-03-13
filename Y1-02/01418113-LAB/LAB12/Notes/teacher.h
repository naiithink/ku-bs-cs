#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"

using namespace std;

class Teacher
{
    public:
        explicit Teacher(const string);
        string getName(void);
        void setName(const string);
        void giveScore(Student, const double);
        void giveScore(Student *, const double);

    private:
        string name;
};

#endif