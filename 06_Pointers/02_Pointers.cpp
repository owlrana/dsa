/*
    Pointer variables stores address of another variable.
*/

# include <iostream>
using namespace std;

int main ()
{

    int a = 100;

    int * y; // declaring without initialisation, currently has a garbage value thus it is recc to init = 0
    y = &a;
    // also never store diff type of address for diff variable Eg. Int ptr should only have int var address

    int * z = &a;

    cout << *y << endl << *z << endl;

    // Size of a pointer variable is same for all datatypes, but there ARE NO GUARANTEES!
    // (Usually 4 bytes or 8 bytes depending upon the system (32/64 bit))
    // in 64 bit system all memory locations are of 64 bits and this is how much space is allocated for 
    // each block! (8 bytes)
    // https://stackoverflow.com/questions/399003/is-the-sizeofsome-pointer-always-equal-to-four

    int *xptr;
    xptr = &a;

    cout << endl;
    cout << &xptr << endl << xptr << endl; //&ptr gives the address of our pointer and xptr is add of var

    int b = 0;
    xptr = &b; // can also reassign to a different address (but only of the same type!!)
    cout << endl;
    cout << &xptr << endl << xptr << endl; 

    return 0;
}