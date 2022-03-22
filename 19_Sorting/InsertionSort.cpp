// program for Bubble Sort

#include<iostream>
#include<climits>
using namespace std;

void InsertionSort(int array[], int size)
{
    for (int i = 1; i <= size-1; i ++) // as we move i -> forward, the left most array keeps sorting
    {
        int current = array[i]; // this is the element that needs to be inserted in right place

        int j = i-1;
        while (j >= 0 and array[j] > current)
        {
            array[j+1] = array[j];  // keep shifting the elements to right...
            j -= 1; // keep moving towards the left area
        }
        array[j+1] = current; // the last element was found to be -1 or lesser than current, so +1
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
    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        cin >> array[i];
    }

    InsertionSort(array, n);
    print(array, n);

    return 0;
}