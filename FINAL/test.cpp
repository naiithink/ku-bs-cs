#include <iostream>

using namespace std;

#define LIM 4

class t
{
    public:
        t(int n)
        {
            this->n = n;
        }

        int n;
};

// int main(void)
// {
//     // int *arr[LIM];
// // 
//     // int a = 1, b = 2, c = 3;
// // 
//     // // for (int i = 0; i < LIM; ++i)
//     // // {
//     //     arr[0] = &a;
//     //     arr[1] = &b;
//     //     arr[2] = &c;
//     // // }
// // 
//     // for (int i = 0; i < LIM; ++i)
//     // {
//     //     cout << *arr[i] << endl;
//     // }
// 
//     t x("i");
// 
//     cout << x.n << endl;
// 
//     return 0;
// }

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
        GetSalary (void)
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
    Person a("foo", 100);
    cout << a.Tax(10) << endl;
}