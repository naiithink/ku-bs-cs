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
    // สร้าง Object เพื่อทดสอบด้วยตัวเอง
    Hero A("Nai", 100);

    cout << A.getName() << endl;
    cout << A.getLevel() << endl;
}