/*
    POINT TO NOTE:
    When we pass a vector into the function, a copy is created.
    It is not like arrays, when the pointer is papssed.
    This, has a copy in the function's scope.
*/

// This file shows the use of vector datatype and how you can initialise its objects

# include <iostream>
# include <vector> // need to include this header file

using namespace std;

int main ()
{
    vector<int> a; // initialise an empty vector object a
    
    vector<int> b(5,10); // initialise a vector object b of size 5 and all elements as 10

    vector<int> c(b.begin(), b.end()); // initialise a vector c with all contents of b

    vector<int> d{1,2,3,4,5}; // initialise with the following elements in {}

    // storing the size of a vector
    int size = d.size();

    // 1. Look at how we can iterate over a vector
    for (int i = 0; i < size; i ++)
    {
        cout << d[i] << ", ";
    }
    cout << "\b\b " << endl;

    // 2. Using iterators to access the elements inside a vector
    for(auto it = d.begin(); it != d.end(); it++) // instead of auto you can also write "vector<int>::iterator it"
    {
        cout << *it << ", "; 
    }
    cout << "\b\b " << endl;

    // 3. For Each Loop (favourite)
    for (auto x: d) // means for each int x that lies in vector d
        cout << x << ", ";
    cout << "\b\b " << endl;
    
    // Taking input from user in a vector
    // As the vectors are dynamic, you do not need the size in advance
    vector<int> myvector;

    cout << "Enter the number of elements you want: ";
    cin >> size;

    for (int i = 0; i < size; i ++)
    {
        int element;
        cin >> element;
        myvector.push_back(element); // adds element to the end of myvector
    }

    // push_back() doesnt just add an element to the end, but it also checks
    // if the size of array needs to be increased or not. if it needs to be inc,
    // then the size of array is doubled (if cont. is available or finding new location)
    // and copies all the elements into the new location if it is created at another place

    for (auto x: myvector)
        cout << x << ", ";
    cout << "\b\b " << endl;


    // DIFFERENCE IN VECTORS WHILE INITIALISING (memory level)!!!

    // suppose you initialise a vector d_vector of 5 elements like this
    vector<int> d_vector {1,2,3,10,14};

    // and you initialise another vector v_vector of 5 elements like this
    vector<int> v_vector;
    for (int i = 0; i < 5; i ++)
    {   
        int element;
        cin >> element;
        v_vector.push_back(element);
    }

    // at memory level how they are different:
    // 1. for v_vector: 
    cout << "Size of v_vector is: " << v_vector.size() << endl; // how many elements vector contains
    cout << "Capacity of v_vector is: " << v_vector.capacity() << endl; // the size occupied by array in memory
    cout << "Capacity of v_vector is: " << v_vector.max_size() << endl; // max elements the vector can hold in WORST CASE acc to memory available in system

    // 2. for d_vector:
    cout << "Size of d_vector is: " << d_vector.size() << endl; // how many elements vector contains
    cout << "Capacity of d_vector is: " << d_vector.capacity() << endl; // the size occupied by array in memory
    cout << "Capacity of d_vector is: " << d_vector.max_size() << endl; // max elements the vector can hold in WORST CASE acc to memory available in system

    // the size of v_vector.capacity() is different as the vector doubled  when it was filling 4th element

    return 0;
}