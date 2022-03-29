// ฟาร์ม [ภาษา C++ คะแนน 4%]

#include <iostream>

using namespace std;

#define MAXPLANT 10

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

        // 1 if succeeded, 0 if failed.
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


class Farm
{
    public:
        explicit
        Farm (void)
        {
            this->planted = 0;
            
            for (int i = 0; i < MAXPLANT; ++i)
            {
                this->inFarm[i] = NULL;
            }
        }

        int
        Plant (Vegetable *vegetable)
        {
            int index = this->planted;

            if (planted == MAXPLANT || vegetable == NULL)
            {
                return 0;
            }
            else if (inFarm[index] == NULL)
            {
                inFarm[index] = vegetable;
                this->planted++;
            }

            return planted;
        }

        // Number of watered plants.
        int
        Water (const int volume)
        {
            int watered = 0;
            Vegetable *head = NULL;

            if (volume < 0)
            {
                return watered = 0;
            }

            for (int i = 0; i < this->planted; ++i)
            {
                head = inFarm[i];
                watered += head->Water (volume);
            }

            return watered;
        }

        int
        Pick (void)
        {
            int pickable = 0;
            Vegetable *head = NULL;

            for (int i = 0; i < this->planted; ++i)
            {
                head = inFarm[i];
                pickable += head->IsReadyToPick();
            }

            return pickable;
        }

    private:
        Vegetable *inFarm[MAXPLANT];
        int planted;
};

int main() {
    // เขียน main function เพื่อทดสอบเอง

    Vegetable cabbage("Cabbage", 6);
    Vegetable tomato("Tomato", 10);
    Vegetable rice("Rice", 15);

    Farm farm;


    farm.Plant(&cabbage);
    farm.Plant(&tomato);
    farm.Plant(&rice);

    
    farm.Water(8);
    cout << farm.Pick() << endl;

    farm.Water(10);
    cout << farm.Pick() << endl;

    return 0;
}