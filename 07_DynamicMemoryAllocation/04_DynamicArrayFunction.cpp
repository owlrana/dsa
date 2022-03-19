# include <iostream>
using namespace std;

int* fun()
{
    int a[] = {1,2,3,4};
    cout << "Value of a in function: " << a << endl; // returns the address of a
    cout << "Value of a[0] in function: " << a[0] << endl; // returns the 0th element of a

    // int* a = new int [4] {11,2,3,4}; // should have initialised a like this

    return a; // address of stack memory is returned here, which will be out of scope once func call ends
}

int main ()
{
    int *b = fun();
    cout << "Value of b outside: " << b << endl; // returns the address of a WHICH WILL BE ZERO!!
    cout << "Value of b[0] outside: " << b[0] << endl; // the local array in function is now GONE (scope),
    // so this ^ statement will now give garbage value or may even give segmentation fault

    // delete [] b; // should have also deleted it before the program ends

    return 0;
}