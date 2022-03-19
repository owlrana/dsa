# include <iostream>
# include <algorithm>
using namespace std;

int first_occurrence(int a[], int n, int key)
{
    int s = 0;
    int e = n-1;

    int ans = -1;

    // update in a dir that ans value is lower and lower
    while(s <= e)
    {
        int mid = (s + e) / 2;
        
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(a[mid] > key)
            e = e - 1;
        else
            s = mid + 1;
    }

    return ans;
}

int last_occurrence(int a[], int n, int key)
{
    int s = 0;
    int e = n-1;

    int ans = -1;

    // update in a dir that ans value is higher and higher
    while(s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1; // do not stop but go to right part of the array
        }
        else if(a[mid] > key)
            e = e - 1;
        else
            s = mid + 1;
    }

    return ans;
}

int main ()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,8,8,8,8,10};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;

    cout << "First occurrence is: " << first_occurrence(arr, n, key) << endl;
    cout << "Last occurrence is: " << last_occurrence(arr, n, key) << endl;

    return 0;
}