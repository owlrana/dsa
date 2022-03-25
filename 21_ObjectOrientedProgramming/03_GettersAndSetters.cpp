# include <iostream>
using namespace std;

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
        // getter for a private attribute in class
        int get_price ()
        {
            return price;
        }
        // setter for a private attribute in class
        void set_price(int aPrice)
        {
            if (aPrice > 0)
            {
                cout << "Price is now set to: " << aPrice << endl;
                price = aPrice;
            }
            else
                cout << "INVALID PRICE INPUT!" << endl;
        }
};

int main ()
{
    // for PrivateCar class
    PrivateCar car1;
    cout << car1.get_discounted_price(0.20);

    int price;
    cout << "Enter what price you want to set: " << endl;
    cin >> price;

    car1.set_price(price);
    cout << car1.get_price() << endl;

    return 0;
}