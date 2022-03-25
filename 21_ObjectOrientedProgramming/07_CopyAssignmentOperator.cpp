/*  
    Some special functions that C++ Classes give you when you create a new class/object.
    Here are 4 different special functions that are always present when you create a class:
        1.  Constructor
        2.  Copy Constructor
        3.  Copy Assignment Operator
        4.  Destructor

    3.  Copy Assignment Operator
        -   denoted using " = "
        -   copies when you do assignment
        -   Eg. Car c2 = c1; // in this, a copy constructor will be called BUT:
                if you do this ->
                    Car c2;
                    c2 = c1; // NOW THE COPY ASSIGNMENT OPERATOR WILL BE CALLED
        -   This ALSO CREATES A SHALLOW COPY
        -   You can write your own copy assignment operator to get over shallow copy and make a deep one instead

    BIG DIFFERENCE B/W Copy Assignment and Copy Constructor:
        a copy assignment operator can be called many number of times, while copy constructor is only called once

    To create a Copy Assignment Operator, use -> void operator= (class to_be_copied)

*/

// program to show how a copy assignment operator is overloaded

# include <iostream>
# include <cstring>

using namespace std;

class Car
{
    private:
        float price;

    public:
        int model_no;
        char *name; //pointer to a dynamic array

        // constructor
        Car ()
        {
            name = NULL;
        }

        // parameterised constructor
        Car (float p, int m, char *n)
        {
            price = p;
            model_no = m;
            name = new char[strlen(n)+1]; // need to do +1 as we need to copy NULL Chr as well
            strcpy(name, n); 
        }

        // to set price
        void set_price(int aPrice)
        {
            price = aPrice;
        }

        // helper function to print the class attributes
        void print()
        {
            cout << "Name: " << name << endl;
            cout << "Mode Number: " << model_no << endl;
            cout << "Price: " << price << endl;
        }

        // Copy Assignment Operator Overloading
        void operator= (Car &x) //can pass by memory or reference, but passing by reference to save memory this time
        {
            cout << "INSIDE COPY ASSIGNMENT OPERATOR!" << endl;

            // same work that we did in the copy constructor
            price = x.price;
            model_no = x.model_no;
            // name = x.name; // this is what the default constructor was doing
            // create a deep copy
            name = new char[strlen(x.name)+1];
            strcpy(name, x.name);

        }

};

int main ()
{
    Car c1(100, 221921, "BMWM3"); // calling the parameterised constructor
    Car c2; // calling the inbuilt copy constructor
    c2 = c1;

    c2.set_price(500); // works fine and does not mess up anything
    c2.name[0] = 'Z'; // this changes things for BOTH IF WE DO A SHALLOW COPYYYY!!!!!!!!!

    c1.print();
    cout << endl;
    c2.print();

    return 0;
}