#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student
{
    public:
        explicit Student(const string, const string);
        string getName(void);
        double getScore(void);
        void setName(const string);
        void addScore(const double);
    
    private:
        string name;
        string id;
        double score;
};

#endif