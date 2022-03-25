/*

Some special functions that C++ Classes give you when you create a new class/object.
    Here are 4 different special functions that are always present when you create a class:
        1.  Constructor
        2.  Copy Constructor
        3.  Copy Assignment Operator
        4.  Destructor

    2.  Copy Constructor
        -   make a copy of the given object
        -   also exists by default and is hidden Eg. (Car car2(car1));
            // this will create a car2 object based on all the internal details as car1
        Eg.
            Car()
            {
                private:
                    int model = 0000;
                    int price = 1000;
                    string name = "BMW M3";

                public:
                    Car()
                    {
                        // constructor
                    }

                    // COPY CONSTRUCTOR - ACCEPTS ANOTHER OBJECT OF CAR
                    // Car(Car x) // this will give error
                    Car(Car &x) // why are we passing it by reference? answer after the example.
                    {
                        model = x.model;
                        price = x.price;
                        name = x.name;
                    }
            }

        WHY ARE WE PASSING THE OBJECT FOR COPY BY REFERENCE?
        When we call without reference, this is what happens:
            1.  our compiler recieves which object is being passed
            2.  the compiler then tries to create a copy of the object passed
            3.  COMPILER COULD NOT CREATE COPY AS THE CODE TO CREATE COPY IS WHAT WE ARE WRITING!!!!
        Thus, we cannot send the object by value, we NEED to pass it by reference so as to not create a copy
        PS: do not alter anything in the object creating copy from as it will change the real values inside the object!

        Bonus: Another way to call the copy constructor
        ->  Car car2 = car1; // here also the copy constructor is called, it is exactly the same as "Car car2(car1);"

*/