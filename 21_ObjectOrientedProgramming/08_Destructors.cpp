/*  
    Some special functions that C++ Classes give you when you create a new class/object.
    Here are 4 different special functions that are always present when you create a class:
        1.  Constructor
        2.  Copy Constructor
        3.  Copy Assignment Operator
        4.  Destructor

    4.  Destructor
        -   Goal of a destructor is to clear out the memory occupied by an object
        -   Destructors are generally called automatically when an object goes out of scope
        -   Generally you only need to write cases when you have dynamically allocated members in your class

        Destructors begin by " ~ ", the tilde sign

*/

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

        ~Car()
        {
            // if you do not have any dynamically allocated objects in class, even this empty body is enough
            cout << "inside the car " << name << endl;

            // to remove dynamically allocated objects
            cout << "deleting name for the car..." << name << endl;
            if (name != NULL)
                delete [] name;
            
            // THE ORDER OF DESTRUCTION IS REVERSE (object that is initiated first gets to be destroyed the LAST)
            // you can also delete whole object of any class by the logic below in the main function (only if the object is dynamically created)
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

    // delete c1; // these wont work as the thing you are deleting needs to be DYNAMICALLY ALLOCATED first
    // delete c2;

    Car *c3 = new Car(200, 300, "Ferrari");
    // c3.print(); // cannot do this as now c3 is not an object, but instead a pointer to an object of Car class
    // so if anything is in the heap memory, we cannot use " . ", but now we will have to use " -> "
    // (*c3).print(); // we can do this, or we can do the shortcut:
    c3->print();
    // this means we are using pointer variable c3 which now needs to point to its object's function print()
    delete c3;

    // Note that ^ Ferrari is the first one to be deleted as it was the last one to be created

    return 0;
}