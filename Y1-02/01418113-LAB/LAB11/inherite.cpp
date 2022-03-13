#include <iostream>

using namespace std;

class Parent
{
private:
    int n;
public:
    Parent(int number);
    int getN(void);
};

Parent::Parent(int number)
{
    this->n = number;
}

int Parent::getN(void)
{
    return this->n;
}

// class Child : public Parent
// {
// public:
//     Child(int number)
//     {
//         Parent Parent(number);
//     }
// };

int main(void)
{
    int x = 10;

    Parent parent(x);

    cout << parent.getN() << endl;

    return 0;
}