# include <iostream>
# include <vector>

using namespace std;

// a print function that outputs vectors, lists, strings neatly for cleaner code
template<class T>
void print(T d)
{
    auto x = d[0];
    for (auto x: d)
    {
        cout << x ;
        if (typeid(x).name() == typeid(1).name())
            cout << ", ";
    }
    if (typeid(x).name() == typeid(1).name())
        cout << "\b\b " << endl;
    else
        cout << endl;
}

int main ()
{
    vector<int> d {1,2,3,10,14};

    // add element to the back of the vector
    d.push_back(15); // Complexity: O(1) for most cases unless it needs to double
    print(d);

    // removes the last element from the vector, Complexity: O(1)
    d.pop_back();
    print(d);

    // insert some elements into the middle, Complexity: O(N)
    d.insert(d.begin() + 3, 100); // v.being() + 3 iterator should tell the position (index)
    print(d);

    d.insert(d.begin(), 4, 0); // inserts element "0", 4 times at position d.begin()
    print(d);

    // erase some elements from the middle, Complexity: O(N)
    d.erase(d.begin() + 3);
    print(d);

    // erase a range of elements, Complexity: O(N)
    d.erase(d.begin(), d.begin() + 5); // removes a range of index from [0 to 5) (not including, upto 5)
    print(d);

    // current size of vector
    cout << d.size() << endl;
    print(d);

    // underlying capacity of vector
    cout << d.capacity() << endl; // generally vectors do not shrink to keep the operations efficient
    print(d);

    // to allocate more memory explicitly
    //d.resize(20); // this also initialises the new members added as 0
    d.resize(30, 1); // this initialises the new memebers as 1
    d.resize(4); // if size is smaller than the array, the extra elements are DESTROYED!!
    cout << d.capacity() << endl;
    print(d);

    // removes all elements of a vector (DOES NOT DELETE THE MEMORY OCCUPIED BY THE ARRAY!)
    d.clear();
    //d.push_back(1);
    //print(d);
    cout << d.capacity() << endl;

    // To check if a vector is empty or not
    if (d.empty())
        cout << "The vector is empty dawg!" << endl;

    d.push_back(999);
    // If you need to front most element
    cout << d.front() << endl;
    
    // last element
    cout << d.back() << endl;


    // -- IMPORTANT CONCEPT --
    // Suppose we want to input 500 elements (taking only 5 to show the example)
    // usually what we use to take input in vector is:
    vector<int> myvector;
    cout << myvector.capacity() << endl;
    int size;
    size = 5;
    //cin >> size;

    for (int i = 0; i < size; i ++)
    {
        int num;
        cin >> num;
        myvector.push_back(num);
        cout << "Capacity of vector: " << myvector.capacity() << endl;
    }
    print(myvector);

    /*
        THE FLAW IN THE ABOVE APPROACH IS THAT
            The vector will start with: 
                - 0 capacity, 
                - then will inc to 1,
                - then double to 2,
                - then double to 4,
                - then double to 8,
                - ...
                - ..
                - until the process is complete
   
        Problem is that finding new space in memory, then copying all elements, then deleting previous
        ^ This is a very expensive process and for a large number of size will definitely hit the processes

        So, to avoid doubling, we will use reserve function.
        
        -- RESERVE FUNCTION --
        Reserve helps you specify a number for the capacity, and this capacity DOES NOT CHANGE UNLESS YOU PASS THE VALUE RESERVED.
        This is different from initialising your vector as N elements, as in the reserve method your size will dynamically change.
    */

    // So this time we do
    vector<int> newvector;
    newvector.reserve(5);
    cout << newvector.capacity() << endl;
    
    //cin >> size;

    for (int i = 0; i < size; i ++)
    {
        int num;
        cin >> num;
        newvector.push_back(num);
        cout << "Capacity of vector: " << newvector.capacity() << endl;
    }
    print(newvector);

    return 0;
}