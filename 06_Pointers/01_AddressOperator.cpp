# include <iostream>
using namespace std;

int main ()
{
    int x = 10;
    cout << &x << endl; // gives out the address where this value is stored (in Hexadecimal Numbers)
     
    float y = 10.5;
    cout << &y << endl << &y + 1 << endl; // gives out value of add then add of next memory location
    // next memory location is this next byte (+8 bits)

    // it DOES NOT WORK FOR CHARACTER VARIABLES
    char ch = 'A';
    cout << &ch << endl; // due to operator overloading (the way cout << is defined for characters)

    // but this can be made to work by Explicit Typecasting from char* to void*
    cout << (void *) &ch << endl; // you are basically just saying that the value stored is not a char (lying)

    return 0;
}