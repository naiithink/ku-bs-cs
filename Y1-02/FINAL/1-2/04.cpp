// ปลูกผัก [ภาษา C++ คะแนน 2%]

#include <iostream>

using namespace std;

class Vegetable
{
    public:
        explicit
        Vegetable (const string name, const int wReq)
        {
            this->wGotten = 0;
            this->name = name;

            if (wReq >= 0)
            {
                this->wReq = wReq;
            }
            else
            {
                this->wReq = 0;
            }
        }

        string
        GetName (void)
        {
            return this->name;
        }

        int
        Water (const int volume)
        {
            int ok = 0;
            if (volume >= 0)
            {
                this->wGotten += volume;
                ok = 1;
            }
            return ok;
        }

        int
        IsReadyToPick (void)
        {
            if (this->wGotten < this->wReq)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

    private:
        string name;
        int wReq;
        int wGotten;
};

int main() {
    // เขียน main function เพื่อทดสอบเอง

    // Vegetable tomato("Tomato", 10);
    // Vegetable rice("Rice", 15);

    // cout << tomato.GetName() << endl;
    // cout << rice.GetName() << endl;

    // tomato.Water(8);
    // cout << tomato.IsReadyToPick() << endl;

    // rice.Water(20);
    // cout << rice.IsReadyToPick() << endl;

    // tomato.Water(6);
    // cout << tomato.IsReadyToPick() << endl;

    Vegetable test("", 0);
    cout << test.GetName() << endl << test.Water(-1) << endl << test.IsReadyToPick() << endl;

    return 0;
}
