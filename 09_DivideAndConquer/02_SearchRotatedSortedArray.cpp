/*
        Using Binary Sort to go to mid and then we identify where we are:
            
            0. if element[mid] is the key, then just return

            1. if element[0] <= element[mid]
                --> means we are in the first half, and all we know is that the LEFT side is sorted
                We need to know if our element is within this range, 
                    --> if it is then narrow down by: end = mid - 1
                    --> if it is NOT then move out of this range by: start =  mid + 1

            2. if element[end] >= element[mid]
                --> means we are in the second half, and all we know is that RIGHT SIDE is sorted
                We need to know if our element is within this range, 
                    --> if it is then narrow down by: start = mid + 1
                    --> if it is NOT then move out of this range by: end =  mid - 1

        We use this knowledge ^ to find out where our element lies and move accordingly 
*/

# include <iostream>
using namespace std;

int find_key(int a[], int n, int key)
{
    int s = 0;
    int e = n-1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[s] <= a[mid]) // means mid pt is lying on the first part of the line
        {
            // 2 cases -- > check whether element lies on right or left side of midpoint
            if (key >= a[s] and key <= a[mid])
            {
                e = mid - 1;
            }
            else 
            {
                s = mid + 1;
            }
        }
        else // means midpoint lies in the right part of the array
        {
            if (key >= a[mid] and key <= a[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main ()
{
    int n;
    cin >> n;
    int a [n];

    for (int i = 0; i < n; i ++)
        cin >> a[i];

    int key;
    cin >> key;

    cout << find_key(a, n, key);

    return 0;
}