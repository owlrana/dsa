/*
    Procedural Programming is creating functions in program
    Object Oriented programming is creating objects in program

    Some languages support OOPS and some dont, but most newer languages support this style.

    In OOP:
        Real world entity --> Object in program

    Suppose we have a car showroom owner who wants to sell/update info about a car

    so
        
    For any car:
          _____           _____           _____           _____           
         /__|__\____     /__|__\____     /__|__\____     /__|__\____      + N Type of Cars
        /-()----()--\   /-()----()--\   /-()----()--\   /-()----()--\

    Specifications:
            - model number
            - name
            - selling price                                               + details for N cars
            - MRP
            - features: [, , , ]
            - maybe more things
    
    The idea is to create a class of car, then create array of class objects to store all details.

    Class is just a blueprint of object you want which specifies paramters it will have,
    it does not remain in the memory.
    When you assign it values and its attributes, that is when you create an object of it.
*/

# include <iostream>
using namespace std;

// defining a new data type
class Car 
{
    int price;
    int model_no;
    char name[20];
};

int main ()
{
    // create an object of this class
    Car arr[20]; //create array of object Car and store information about 20 objects at once

    Car c; // single object

    return 0;
}