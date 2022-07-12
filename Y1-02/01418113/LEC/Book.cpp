#include <iostream>

using namespace std;

class Book
{
    public:
        Book(string n, string a)
        {
            name = n;
            author = a;
            quantity = 10;
        }

        void Buy(int buy_quantity)
        {
            if (buy_quantity <= quantity)
            {
                quantity = quantity - buy_quantity;
            }
        }

        int GetQuautity() const
        {
            return quantity;
        }

    private:
        string name;
        string author;
        int quantity;
};

int main()
{
    Book c_book("C Programming", "Dennis");
    Book python_book("Python Cookbook", "Brian");

    c_book.quantity = 25;
    c_book.Buy(5);
    Buy(c_book, 5);

    return 0;
}