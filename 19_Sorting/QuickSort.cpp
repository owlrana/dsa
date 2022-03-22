// program for Bubble Sort

#include<iostream>
#include<climits>
using namespace std;

int round = 1;

int partition(int* array, int start, int end)
{
    // doing in place, not taking any extra memory
    int i = start - 1;
    int j = start;

    cout << "----------\nRound: " << round++ <<endl;
    cout << "int i = " << start -1 << "; int j = " << start;

    int pivot = array[end]; // taking the last element as pivot and inserting it into right place
    cout << endl << "Pivot elements is: " << pivot << endl;

    // only go till the end-1 index, as index end is our pivot element
    for (; j <= end - 1;)
    {
        cout << "Checking if array[j] (" << array[j] << ") is less than Pivot (" << pivot <<") \n";
        if (array[j] <= pivot)
        {
            // merge the smaller element into region 1
            i = i + 1;
            cout << "YES IT IS. Swapping and increasing value of i. Now i=" << i << endl;
        }
        // expand the larger region
        j = j + 1;
        cout << "Incrementing the value of j, loop over. Value of j=" <<j << endl;
    }

    // place the pivot element in the correct index
    swap (array[i+1], array[end]);
    
    cout << endl << endl;
    return i + 1;
}

void QuickSort(int* array, int start, int end)
{   
    // base case
    if (start >= end) // this means there is either 1 element, or no element (its sorted!)
    {
        return;
    }

    // recursive case
    int p = partition(array, start, end); // this is required to know where to break array further
    // left side
    QuickSort(array, start, p-1);
    // right side
    QuickSort(array, p+1, end);
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

    QuickSort(array, 0, n-1);
    print(array, n);

    return 0;
}