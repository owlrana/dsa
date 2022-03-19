// This is if the array is NOT sorted. For sorted array, we have binary search in file 02

# include <iostream>
# include <algorithm>
using namespace std;

int main ()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);

    // Search --> Find
    int key = 11;

    auto it = find(arr, arr+n, key); // auto finds out the type of var based on initialisation
    cout << it << endl; // this gives out the address where this key is stored in

    // to get the index, we will need to subtract this address with base address
    int index = it - arr;

    if (index == n) // if the index is not present, then the address returned is one after the end of arr
        cout << "Key is not present!" << endl;
    else
        cout << index << endl;

    return 0;
}