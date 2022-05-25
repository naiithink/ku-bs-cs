#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
};

class Taxi : public Transportation
{
    public:
        explicit Taxi() {};

        double fare()
        {
            double res = 35;
            res += distance * 2;
            return res;
        }

        void setDistance(double distance)
        {
            this->distance = distance;
        }

    private:
        double distance;
};

class BmtaBus : public Transportation
{
    public:
        explicit BmtaBus() {};

        double fare()
        {
            double res = 6.5;
            return res;
        }
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

class Passenger
{
    public:
        explicit Passenger()
        {
            this->total_fare = 0;
        }

        void addTransportation(Transportation &transit)
        {
            this->total_fare += transit.fare();
        }

        double getTotalFare()
        {
            return total_fare;
        }
    
    private:
        double total_fare;
};

int main()
{
    Passenger passenger;
    while(1) {
        char transportType;
        cin >> transportType;
        if (transportType == 'A') {
            Taxi *taxi = new Taxi();
            double distance;
            cin >> distance;
            taxi->setDistance(distance);
            passenger.addTransportation(*taxi);
        } else if (transportType == 'B') {
            BmtaBus *bus = new BmtaBus();
            passenger.addTransportation(*bus);
        }  else if (transportType == 'C') {
            BTS *bts = new BTS();
            int station;
            cin >> station;
            bts->setStation(station);
            passenger.addTransportation(*bts);
        } else {
            break;
        }
    }
    cout << "Total Fare: " << passenger.getTotalFare() << endl;
}