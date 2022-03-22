// program for Bubble Sort

#include<iostream>
#include<climits>
using namespace std;

void swap (int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void BubbleSort(int array[], int size)
{
    for (int iteration = 1; iteration <= size - 1; iteration ++) // we require n-1 iterations
    {
        for (int j = 0; j < size - 1 - iteration; j ++) // after index size-1-iteration the elements are sorted
        {
            if (array[j+1] < array[j])
            {
                swap(array[j+1], array[j]); // do pairwise swapping in the unsorted path of the arr
            }
        }
    }
}

// A function to implement bubble sort recursively
void BubbleRecursiveSort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;
 
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
 
    // Largest element is fixed,
    // recur for remaining array
    BubbleRecursiveSort(arr, n-1);
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

    BubbleSort(array, n);
    print(array, n);

    return 0;
}