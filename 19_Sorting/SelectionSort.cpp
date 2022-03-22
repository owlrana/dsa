// program for Insertion Sort

#include<iostream>
#include<climits>
using namespace std;

void SelectionSort(int array[], int size)
{
    for (int i = 0; i < size-1; i ++)
    {
        int minIndex = i; // keeping track for the smallest index

        // to find out the smallest index out of the unsorted part
        for (int j = i; j < size; j ++)
        {   
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        // after this loop we can finally swap
        swap(array[i], array[minIndex]);
    }

    return;
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
    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        cin >> array[i];
    }

    SelectionSort(array, n);
    print(array, n);

    return 0;
}