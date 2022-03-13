#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
    public:
        explicit Person(const string);
        string getName(void);
        void setName(const string);

    private:
        string name;
};

#endif