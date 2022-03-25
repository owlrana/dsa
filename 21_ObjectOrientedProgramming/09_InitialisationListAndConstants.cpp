/*
    Some more topics that are important to understand Object Oriented Programming:
        1.  Constant Data Members
            These are initialised once and they cannot change their values
        2.  Constant Parameters
            These are paramters passed to a function that are not going to be changed. It is a good practice to make them constant as well.
        3.  Constant Functions
            These are functions that are not going to change anything, so make sure you do const to show that they do no change to internal variables.
            PS: functions need to have "const" AFTER its names and arguments

    These practices make debugging very easy. In large codebases, this can very efficiently eliminate the probability of error generating functions.
    
*/

# include <iostream>
# include <cstring>

using namespace std;

class Car
{
    private:
        float price;
        // INITIALISATION OF CONSTANT VARIABLE
        // const int msp = 99; // this needs to be initialised RIGHT HERE & RIGHT FUCKING NOW (commented out because there is another way)
        // now that it is initialised, you cannot do assignment

        // another way if you need to NOT declare it right then and there for some reason (maybe you want diff value for diff constructor types)
        const int msp; // but now you need to initialise this value while the constructor is being called

    public:
        int model_no;
        char *name; //pointer to a dynamic array

        // constructor
        Car() : msp(99) //  for this constructor call, msp will be initialised as 99
        {
            name = NULL;
        }

        // parameterised constructor
        Car (float p, int m, char *n, int val) : msp(min(val, 99)) // for this constructor call, msp will be initialised as whatever is minimum of maxVal (user input) or 99
        {
            price = p;
            model_no = m;
            name = new char[strlen(n)+1];
            strcpy(name, n); 
        }

        // to set price
        void set_price(const int aPrice)
        {
            price = aPrice;
        }

        // helper function to print the class attributes
        void print() const // functions need to have "const" AFTER its names and arguments
        {
            cout << "Mode Number: " << model_no << endl;
            cout << "Price: " << price << endl;
            cout << "MSP: " << msp << endl;
            cout << "Name: " << name << endl;
        }

        // Copy Constructor (Creates a DEEP COPY)
        Car(const Car &x) : msp (102) // should also create an initialisation for copycontructors, and should also make the copier as const for READ ONLY use
        {
            price = x.price;
            model_no = x.model_no;
            name = new char[strlen(x.name)+1];
            strcpy(name, x.name);
        }

};

int main ()
{
    Car c1(100, 221921, "BMWM3", 98); // calling the parameterised constructor
    
    c1.print();

    Car c2;
    
    c2.print();
    
    return 0;
}