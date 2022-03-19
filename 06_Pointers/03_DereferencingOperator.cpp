/*
    "*" can be used for: 
        1. multiplication (binary operator)
        2. creating a pointer variable
        3. Dereference any address

    Dereferencing means that you can access the variable that the pointer is pointing to.

*/

# include <iostream>
using namespace std;

int main ()
{
    int x = 10;

    int *pX = &x; // telling c++ that pX is a pointer and store the address of x in it

    cout << pX << endl << &x << endl; // pX and &x are the same thing

    cout << *pX << endl << x << endl; // *pX and x means using the value stored in the bucket

    cout << pX + 1 << endl; // gives the address of the next memory location

    cout << *(pX + 1) << endl; // gives the value stored in the next memory location (will be garbage most prob)

    cout << **(&pX) << endl; // goes to --> bucket of ( bucket of ( adress of pX )) which is 10

    int **pXx = &pX; // called a double pointer, means storing the address of a pointer into a pointer
    cout << pXx << endl; // this is the address of the pointer it stores ie. &pX
    cout << *pXx << endl; // this is the value of the pointer it stores ie. &x
    cout << **pXx << endl; // this is the value of the pointer's value ie. 10  
    cout << &pXx << endl; // this is the address of the pointer ie. &pXx
    return 0;

}