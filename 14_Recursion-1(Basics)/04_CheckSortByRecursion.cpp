// Checking if an array is sorted or not using recursion

# include <iostream>
using namespace std;

bool isSorted(int a[], int n) // int a[] is similar to int *a as both just pass the address by value
{
    // base case
    if ((n == 0) or (n == 1))
        return true;
    
    // recursive case
    if (a[0] < a[1] and isSorted(a+1, n-1)) // 0th element < 1st, + ALSO RECURSIVELY if array that starts from 1st index, with n-1 elements is sorted
    {
        return true;
    }
    return false;
}

int main ()
{
    int arr[] = {1, 2, 3, 14, 5};
    int n = sizeof(arr) / sizeof(int);

    if (isSorted(arr, n))
        cout << "Array is sorted!" << endl;
    else
        cout << "Array is NOT sorted!" << endl;

}
