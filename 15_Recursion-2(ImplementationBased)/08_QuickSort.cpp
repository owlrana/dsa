/*
    -- QUICK SORT --
    A Divide and Conquer algorithm for sorting that is pretty popular and is included in many libraries.
    Special thing about this sorting technique is that it SORTS ARRAY IN PLACE WITHOUT EXTRA ARRAY.
    But it may take up memory due to call stack (recursion).
    The average complexity is N LogN and worst is N^2 (which can be fixed by using random pivots)

    Algo:
        1.  Choose Pivot before sorting
        2.  Divide into two parts with pivot in middle
            --> Send element to left if <= pivot
            --> Send element to right if > pivot
        3.  Recursively Sort Left and Right side

*/

# include <iostream>
using namespace std;

int partition(int array[], int start, int end)
{
    // in place (cannot take an extra array)
    int i =  start - 1; // i stands for the smaller region (currently saying no element)
    int j =  start; // this stands for the larger region, will swap with i and move i one ahead if j has smaller
    // so this approach kind of bubbles the smaller elements into the left hand side of the array
    // if the element is bigger, it is already in the right place so we just move j to the right
    int pivot = array[end];

    while (j <= end - 1)
    {
        if (array[j] <= pivot)
        {
            // merge the smaller element in the region 1 ( we keep increasing as we find more elements)
            i = i + 1;
            swap(array[i], array[j]);
        }
        // go on to the next element to check its place
        j = j + 1;
    }

    // place the pivot element in the element that is next (it will always be bigger than pivot)
    swap(array[i + 1], array[end]);

    return i+1; // return this pivot element index
}

void quickSort(int array[], int start, int end)
{
    // base case first
    if (start >= end)
        return;

    // recursive case
    int pivot = partition(array, start, end); //helper function that does partitioning for us
    // now that we know about the pivot element we can go ahead and recursively sort other parts
    // left part
    quickSort(array, start, pivot-1);

    // right part
    quickSort(array, pivot+1, end);
}


int main ()
{
    int array[] = {2,7,8,6,1,5,4,0};
    int size = sizeof(array) / sizeof(int);

    quickSort(array, 0, size - 1);

    // print the array
    for (int i = 0; i < size; i ++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;

    return 0;
}