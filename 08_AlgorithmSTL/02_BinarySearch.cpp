# include <iostream>
# include <algorithm>
using namespace std;

int main ()
{
    int arr[] = {20, 30, 40, 40, 40, 40, 50, 60, 100, 1100};
    int n  = sizeof(arr)/sizeof(int);

    int key = 60;

    // Search in a sorted array
    bool present = binary_search(arr, arr+n, key); // gives true or false acc to found or not

    if (present)
        cout << "The element is present!" << endl;
    else
        cout << "The element is not present..." << endl;

    // Get the index of the element where it is present
    // lower_bound(start, end, key);
    // upper_bound(start, end, key); 

    // they return address so we can also do int* instead of auto
    auto it = lower_bound(arr, arr+n, 999); // returns the first key address >= key value
    cout << "Lower Bound: " << it-arr << endl;

    auto it2 = upper_bound(arr, arr+n,999); // returns the first key that is > key value 
    cout << "Lower Bound: " << it2-arr << endl;

    // frequency of an element
    cout << "Frequency of element: " << it2-it << endl;

    return 0;
}