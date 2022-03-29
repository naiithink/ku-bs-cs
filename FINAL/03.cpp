// ภาษีบุคคล [ภาษา C++ คะแนน 2%]

#include <iostream>
using namespace std;

class Person
{
    public:
        explicit
        Person (string name, const int salary)
        {
            this->name = name;
            this->salary = salary;
        }

        string
        GetName (void)
        {
            return this->name;
        }

        int
        Getsalaryary (void)
        {
            return this->salary;
        }

        int
        IncomeYearly (void)
        {
            return this->salary * 12;
        }

        int
        Tax (const int rate)
        {
            int res = 0;
            int get = rate * 0.1;

            res = this->salary * get;

            return res;
        }

    private:
        string name;
        int salary;
};

int main() {
    // เขียน main function เพื่อทดสอบเอง
}
