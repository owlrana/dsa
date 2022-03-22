// program for Bubble Sort

#include<iostream>
#include<climits>
using namespace std;

void WaveSort(int* array, int size)
{
    // approach is to visit each ODD placed element (even indexed elements)
    // and make sure it is the largest in its local position

    for (int i = 1; i < size; i += 2)
    {
        // check if previous element is higher, if it is, then SWAP
        if (array[i-1] > array[i])
        {
            swap(array[i-1], array[i]);
        }

        // check if the next element is higher, if it is, then SWAP
        if (i != size-1 and array[i] < array[i+1])
        {
            swap(array[i], array[i+1]);
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

    WaveSort(array, n);
    print(array, n);

    return 0;
}