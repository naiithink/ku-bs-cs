#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
};

class BTS : public Transportation
{
    public:
        explicit BTS() {};

        double fare()
        {
            double res = 15;
            res += station * 5;
            return res;
        }

        void setStation(const int stops)
        {
            if (stops < 0)
            {
                this->station = 0;
            }
            else
            {
                this->station = stops;
            }
        }

    private:
        int station;
};

int main()
{
    int tc;
    cin >> tc;
    if (tc == 1) {
        int station;
        cin >> station;
        BTS bts;
        bts.setStation(station);
        cout << "BTS fare: "
             << bts.fare() << endl;
    } else if(tc == 2) {
        int station;
        cin >> station;
        BTS bts;
        bts.setStation(station);
        Transportation *transport = &bts;
        cout << "Transporataion fare: "
             << transport->fare() << endl;
    }
}