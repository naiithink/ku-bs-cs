#include <iostream>
#include <string>

using namespace std;

class Hero
{
    public:

    string name;
    int level;

    explicit Hero(string name, int level)
    {
        this->name = name;
        this->level = level;
    }

    string getName(void)
    {
        return name;
    }

    int getLevel(void)
    {
        return level;
    }
};

int main()
{
    string name;
    int level;

    cin >> name >> level;

    Hero foo(name, level);
    
    cout << foo.getName() << " " << foo.getLevel() << endl;

    return 0;
}