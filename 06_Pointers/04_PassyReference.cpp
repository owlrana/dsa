/*
    Usually in any function, arguments are passed by their values (int, char, etc).
    What this means is, the function creates another copy of the variable with the same value given,
    and then uses that local variable throughout it's runtime. When we come out of the function,
    this variable is de-allocated. So our real variable still has the same value.

    But we can pass an address to a function, so the function can edit the bucket rather than a copy.
*/

# include <iostream>
using namespace std;

// this function accepts the data type of int as its argument.
void passVal(int a) {
    a += 1;
    cout << "Passing by Val called. Value of a inside the function is now: " << a << endl;
}

// this function accepts the data type of int* as its argument.
void passRef(int* pB) {
    *pB += 1;
    cout << "Passing by Ref called. Value of b inside the function is now: " << *pB << endl;
}

int main ()
{
    int a = 10, b = 10;

    passVal(a); // sending the value of this variable
    passRef(&b); // need to send the address where this variable is stored
    cout << endl;
    cout << "Value of a outside the function is now: " << a << endl; // should not have changed
    cout << "Value of b outside the function is now: " << b << endl; // should have changed
    return 0;
}