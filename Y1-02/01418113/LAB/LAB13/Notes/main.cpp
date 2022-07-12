#include <iostream>
#include "person.h"
#include "student.h"
#include "teacher.h"

using namespace std;

int main(void)
{
    Person *p1 = new Person("Tony");

    cout << p1->getName() << endl;

    return 0;
}