// program for DNF Sort (Optimized way of counting if only 3 diff. items)

#include<iostream>
#include<climits>
using namespace std;

void DNFSort(int* array, int size)
{
    // low and high BOTH start at zero, and high will start at the end of the array
    int low = 0;
    int high = size-1;
    int mid = 0;

    while (mid <= high)
    {
        if (array[mid]==0)
        {
            // put it into its position and move both ahead
            // both low and mid index may be equal, in case all starting elements are == 0
            // that's fine! we just need low to be at the end of 0s anyway, and mid needs
            // to be in the unsorted path.

            swap(array[low], array[mid]);
            low ++;
            mid ++;
        }
        if (array[mid]==1)
        {
            // it is already in the right position. just move forward
            mid ++;
        }
        if (array[mid] == 2)
        {
            swap(array[mid], array[high]);
            high --;
            // no mid ++ because it may be possible that after swapping we just inserted a zero..
            // so in this case we need to check for zero again in the next iteration
        }
    }
}

// print the contents of an array
void print(int array[], int size)
{
    for (int i = 0; i < size; i ++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int array[50];
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i ++)
    {
        cout << "Enter the " << i << "th element: ";
        cin >> array[i];
        cout << endl;
    }

    DNFSort(array, n);
    print(array, n);

    return 0;
}