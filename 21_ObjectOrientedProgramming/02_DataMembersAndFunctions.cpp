# include <iostream>
using namespace std;

// defining a new data type
class Car 
{
    public: // so things outside can access these variables
        int price;
        int model_no;
        char name[20];
};

// a more secure Class
class PrivateCar 
{
    private: // so things outside can access these variables
        int price = 100;
        int model_no;
        char name[20];

    public:
        float get_discounted_price (float x)
        {
            // calculates the discounted price based on the percentage discount "x" given (0-1 values)
            return price*(1-x);
        }
};

int main ()
{
    // for Car class
    Car c;
    c.price = 100;
    cout << c.price << endl;
    c.price = 120;
    cout << c.price << endl;

    // for PrivateCar class
    PrivateCar car1;
    cout << car1.get_discounted_price(0.20);

    return 0;
}