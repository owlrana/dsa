// Program to do binary search by using recursion

# include <iostream>
using namespace std;

bool binarySearch(int arr[], int size, int key)
{
    int mid = size/2;
    
    if (arr[mid] == key)
    {
        return true;
    }
    
    if (arr[mid] < key and size > 1)
    {
        return binarySearch(arr+mid, size-mid, key); // will catch if anywhere there is true
    }
    else if (arr[mid] > key and size > 1)
    {
        return binarySearch(arr, size-mid, key); // will catch if anywhere there is true
    }
    
    return false;

}

int main ()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter the element you want to search for: ";
    cin >> key;

    if (binarySearch(arr, size, key))
        cout << "NUMBER FOUND!" << endl;
    else
        cout << "Num not found... " << endl;

    return 0;
}