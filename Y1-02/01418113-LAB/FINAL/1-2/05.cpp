// รีวิวภาพยนตร์ [ภาษา C++ คะแนน 2%]

#include <iostream>
using namespace std;

class Movie
{
    public:
        explicit Movie(string name)
        {
            this->name = name;
            this->star = 0;
            this->sumStar = 0;
            this->reviewer = 0;
        }

        string
        GetName(void)
        {
            return this->name;
        }

        int
        GiveStar(const int star)
        {
            int given = 0;
        
            if (star <= 1)
            {
                this->star = 1;
                this->sumStar += 1;
            }
            else if (star >= 5)
            {
                this->star = 5;
                this->sumStar += 5;
            }
            else
            {
                this->star = star;
                this->sumStar += star;
            }

            this->reviewer++;

            return given;
        }

        double
        AverageStar (void)
        {
            if (reviewer == 0)
            {
                return 0;
            }

            double res = (double) this->sumStar / this->reviewer;

            return res;
        }

    private:
        string name;
        int star;
        int sumStar;
        int reviewer;
};

int main(void)
{
    Movie batman("The Batman");

    cout << batman.GetName() << endl;
    cout << batman.AverageStar() << endl;

    batman.GiveStar(5);
    batman.GiveStar(3);
    cout << batman.AverageStar() << endl;

    batman.GiveStar(6);
    cout << batman.AverageStar() << endl;

    batman.GiveStar(-8);
    cout << batman.AverageStar() << endl;

    return 0;
}