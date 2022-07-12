#include <iostream>

using namespace std;

class CashCard
{
    public:
        CashCard(int typeID, double cash)
        {
            this->typeID = typeID;
            this->cash = cash;
        }
        
        CashCard(int typeID)
        {
            this->typeID = typeID;
            this->cash = 0;
        }

        int getCardType(void)
        {
            return typeID;
        }

        double getCash(void)
        {
            return cash;
        }

        // Return 1 if success, otherwise if failed.
        double setCash(double cash)
        {
            int ok = 0;

            if (cash >= 0)
            {
                this->cash = cash;
                ok = 1;
            }
            else
            {
                ok = 0;
            }

            return ok;
        }

        // Return 1 if success, otherwise if failed.
        int deposit(double amount)
        {
            int ok = 0;

            if (amount >= 0 && amount < cash)
            {
                cash -= amount;
                ok = 1;
            }
            else
            {
                ok = 0;
            }

            return ok;
        }

        // Return 1 if success, otherwise if failed.
        virtual int topUp(double amount)
        {
            int ok = 0;

            if (amount >= 0.0)
            {
                cash += amount;
                ok = 1;
            }
            else
            {
                ok = 0;
            }

            return ok;
        }
    
    private:
        // e.g. food court      ::= 0
        //      railway pass    ::= 1
        unsigned int typeID;
        double cash;
};

class PromoCard : public CashCard
{
    public:
        PromoCard(int typeID, double cash)
            : CashCard(typeID, cash) {}

        PromoCard(int typeID)
            : CashCard(typeID) {}
        
        int topUp(double amount)
        {
            int ok = 0;

            if (amount >= 200.0)
            {
                CashCard::topUp(20.0);
            }

            ok = CashCard::topUp(amount);

            return ok;
        }
};

int main(void)
{
    cout << "Card Type ID " << endl
         << "   0: Cash Card"  << endl
         << "   1: Cash Card + Promotion" << endl;

    PromoCard myCard(1);

    cout << "This Card Type ID:         " << myCard.getCardType() << endl;
    cout << "   Remain Cash:            " << myCard.getCash() << endl;

    cout << "Deposit 1199 was done?:    " << myCard.deposit(1199) << endl;
    cout << "   Remain Cash:            " << myCard.getCash() << endl;

    cout << "Topping up 100 was done?   " << myCard.topUp(100.0) << endl;
    cout << "   Remain Cash:            " << myCard.getCash() << endl;

    cout << "Topping up 200 was done?   " << myCard.topUp(200.0) << endl;
    cout << "   Remain Cash:            " << myCard.getCash() << endl;
    cout << "Deposit 400  was done?:    " << myCard.deposit(400.0) << endl;
    cout << "   Remain Cash:            " << myCard.getCash() << endl;
    cout << "Deposit 399  was done?:    " << myCard.deposit(318.9) << endl;
    cout << "   Remain Cash:            " << myCard.getCash() << endl;

    return 0;
}