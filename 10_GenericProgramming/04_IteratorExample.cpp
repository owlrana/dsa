// Explaining Iterators and how STL Functions work in C++

/*
    Our search() function will accept .begin() of container and .end()
    It will work on the range: [ num.begin(), num.end() ) only.
    Meaning: it will exclude the .end()

    This is just for understanding of how the people who built
    the STL library must have created the STL generic functions
    which work on vectors, arrays, lists etc without rewriting.

    It is important to understand the underhood concepts but you are
    not expected to code your algorithms using these general concepts.
*/

# include <iostream>
# include <list>

using namespace std;

template<class ForwardIterator, class T>
ForwardIterator search (ForwardIterator start, ForwardIterator end, T key)
{
    while (start != end)
    {
        if (*start == key)
            return start;
        
        start ++;
    }

    return end;
}

int main ()
{
    list <int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.insert(lst.end(), {3,4,5,6,7,8,9,10,12,11});

    auto it = search(lst.begin(), lst.end(), 12);
    
    // int arr[] = {1,2,3,4,5,6,7,9,12,13,11};
    // auto it = search(arr, arr+(sizeof(arr)/sizeof(int)), 12);
    // + it will also work on vectors, maps, etc ;)

    if (it == lst.end())
        cout << "Element not found :(" << endl;
    else
        cout << "Element " << *it << " found!" << " :)" << endl;

    it++; // this can also iterate through our list/vector anyt

    cout << "Next element is: " << *it << endl;

    return 0;
}

// Additinonally in STL Functions:s
// They also have a class comparator function to compare objects