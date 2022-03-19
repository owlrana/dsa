// Sorting technique: Merge Sort
// Dividing the problem into sub problems, 
// divide array into smaller arrays and the merging the sorted ones in each level

# include <iostream>
using namespace std;

void merge(int *array, int left, int right)
{
    int mid = (left + right) / 2;

    int tempArray[100];
    int k = left; // taking this as left and not 0 so its easier to copy paste later into main array
    
    int i = left;
    int j = mid + 1;
    while (i <= mid and j <= right)
    {
        if (array[i] < array[j])
        {
            tempArray[k] = array[i];
            k += 1;
            i += 1;
        }
        else
        {
            tempArray[k] = array[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid)
    {
        tempArray[k] = array[i];
        k += 1;
        i += 1;
    }

    while (j <= right)
    {
        tempArray[k] = array[j];
        k += 1;
        j += 1;
    }

    // now write this tempArray to our original array
    for (int x = left; x <= right; x ++)
    {
        array[x] = tempArray[x];
    }
}

void mergeSort (int array[], int left, int right)
{
    // base case first
    if (left >= right)
        return;

    // recursive logic
    int mid = (left + right) / 2; // calculate the mid index to divide the array

    // sort the left and the right parts
    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);

    // merge the arrays now
    merge(array, left, right);
}

int main ()
{
    int array[] = {5,4,3,1,2,91,0,8};
    int right = (sizeof(array) / sizeof(int)) - 1;
    int left = 0;
    mergeSort(array, left, right);

    for (auto x: array)
        cout << x << ", " ;
    cout << "\b\b " << endl;

    return 0;
}