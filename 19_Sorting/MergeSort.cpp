// program for Bubble Sort

#include<iostream>
#include<climits>
using namespace std;

void combine (int* array, int start, int midpoint, int end)
{
    // now need a pointer for left side array of midpoint
    int i = start;
    // also need a pointer for right side array of midpoint
    int j = midpoint + 1;

    int temp[10000]; // later on we will copy this result into our original array
    int k = start;

    while( i <= midpoint and j <= end)
    {
        if (array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else 
        {
            temp[k++] = array[j++];
        }
    }

    while (i <= midpoint)
    {
        temp[k++] = array[i++];
    }

    while (j <= end)
    {
        temp[k++] = array[j++];
    }

    for (int i = start; i <= end; i ++)
    {
        array[i] = temp[i];
    }
}

void MergeSort(int* array, int start, int end)
{   
    if (start >= end)
        return;

    // follow 3 steps

    // 1. Find the midpoint
    int midpoint = (start + end) / 2;

    // 2. Divide Recursively for smaller arrays
    MergeSort(array, start, midpoint);
    MergeSort(array, midpoint + 1, end);

    // 3. Merge the arrays
    combine (array, start, midpoint, end);

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

    MergeSort(array, 0, n-1);
    print(array, n);

    return 0;
}