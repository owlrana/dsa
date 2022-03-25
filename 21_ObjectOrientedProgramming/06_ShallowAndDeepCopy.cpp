/*

Some special functions that C++ Classes give you when you create a new class/object.
    Here are 4 different special functions that are always present when you create a class:
        1.  Constructor
        2.  Copy Constructor
        3.  Copy Assignment Operator
        4.  Destructor

    2. Copy Constructor (more details)
        Now we know that a copy constructor makes a copy of the object.
        We also know that this constructor exists by default.
        So when is the need to define your own copy constructor?
            - DEFAULT constructor creates a SHALLOW COPY 
        Thus, if you need a DEEP COPY, then you need to create your own constructor!

    DIFFERENCE BETWEEN SHALLOW OR DEEP COPY
    In your class, if you have some pointer that is pointing to a resource that is
    outside the constructor Eg. A Dynamically Allocated Array or heap array then copying that
    usually using a normal copy constructor will give a problem.




*/

// program to show difference in shallow and deep copy

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

        // Copy Constructor (Creates a DEEP COPY)
        Car(Car &x)
        {
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
    Car c2(c1); // calling the inbuilt copy constructor

    c2.set_price(500); // works fine and does not mess up anything
    c2.name[0] = 'Z'; // this changes things for BOTH IF WE DO A SHALLOW COPYYYY!!!!!!!!!

    c1.print();
    cout << endl;
    c2.print();

    return 0;
}