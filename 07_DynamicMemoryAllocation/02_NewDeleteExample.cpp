// This is to show "new" and "delete" use through an example program

# include <iostream>
using namespace std;

int main ()
{
    // Static Allocation
    int b[100]; // is allocated during compile time
    // int b[100] = {0}; // to initialise all mem locations as ZERO
    cout << sizeof(b) << endl; // this is first address of array, but size is associated to this var

    // Dynamic Allocation
    int n;
    cout << "Enter the size of the new array you want to create: "; 
    cin >> n;
    int* pPointer = new int[n];
    // int* pPointer = new int[n] {0}; // to initialise all mem locations as ZERO
    cout << sizeof(pPointer) << endl; // this is also first address, but size is not associated to this

    // working with array is still basically the same as before
    for (int i = 0; i < n; i ++)
    {
        cin >> pPointer[i];
        cout << pPointer[i] << " ";
    }

    // once done, free up space using delete
    delete [] pPointer;

    // this freeing of space was not done in statically allocated as compiler takes care of it auto
    // when the variables go out of scope (Allocation/De-Allocation is done by compiler)

    return 0;
}