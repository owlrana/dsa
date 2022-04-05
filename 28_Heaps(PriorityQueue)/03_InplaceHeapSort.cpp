// Sorting a heap in place WITHOUT an extra array
/*  
    Suppose we are given: 
    2 1 0 4 3

    We need to convert this array (visualised as a tree) into a max heap
    4 3 0 1 2

    Now we need to take advantage of heap's property that the 1st element is highest.
    We remove 4, and reduce the effective size of heap as follows:
    2 3 0 1    | 4

    this time we again create the array into heap
    3 2 0 1    | 4
    and do the same with 3
    1 2 0      | 3 4

    Similarly....
    1 0        | 2 3 4
    0          | 1 2 3 4  (when you have only 1 element left, then stop as that is the smallest!)
     
->  0 1 2 3 4 ANSWER.

    Time Complexity: O(NlogN)
        How? 
        Time taken = building heap once + n Times(removing elements + heapify)
        Time to build heap = O(N)

        Time to remove 1 element = O(1)
        Time to heapify array = O(logN)
*/

#include<everything>
using namespace std;

// heapify function
void heapify(vector<int> &arr, int size, int idx)
{
    int left = idx*2;
    int right = (idx*2) + 1;

    int min_idx = idx;
    int last = size - 1;

    if (left <= last and (arr[left] > arr[idx]))
    {
        min_idx = left;
    }

    if (right <= last and (arr[right] > arr[min_idx]))
    {
        min_idx = right;
    }

    if (idx != min_idx)
    {
        swap(arr[idx], arr[min_idx]);
        heapify(arr, size, min_idx);
    }
}

// function that builds a heap from array
void buildHeap(vector<int> &arr)
{   
    int size = arr.size();
    int n = size - 1;

    for (int i = n/2; i >= 1; i --)
    {
        heapify(arr, size, i);
    }
}

// DRIVER FUNCTION TO SORT HEAP
void heapSort(vector<int> &arr)
{
    buildHeap(arr);
    int n = arr.size();

    // remove n-1 elements from the heap after putting them in position
    while (n > 1)
    {
        swap(arr[1], arr[n-1]);

        // remove that elements from the heap (its sorted dawg)
        n --;
        heapify(arr, n, 1);
    }
}

// utility function to print vector
void printThis(vector<int> arr)
{
    for (int i = 1 ; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(-1);

    int size;
    cout << "Enter the size of array you want to store: ";
    cin >> size;

    for (int i = 0; i < size; i ++)
    {
        int number;
        cin >> number;
        arr.push_back(number);
    }

    cout << "Before sorting: ";
    printThis(arr);
    cout << endl;

    heapSort(arr);

    cout << "After sorting: ";
    printThis(arr);
    cout << endl;

    return 0;
}