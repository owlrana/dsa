# include <iostream>

using namespace std;

// SelectionSort
void selection_sort(int a[], int n) {
    // running loop to decide what goes into ith position
    for (int i=0; i < n-1; i ++) { // goes only till n-2 index as last element is already sorted
        
        int min_index = i;
        // find out the smallest element index in remaining array (unsorted)
        for (int j=i; j < n; j++) { // need to consider if we need to swap the last element with second last
            if (a[j] < a[min_index]) {
                min_index = j; // did not swap, first we are storing the index as swapping is costly
            }
        }
        // now we do a swap
        swap(a[min_index], a[i]); // in-built function to swap two parameters of any type. Returns nothing.
    }
}

int main () 
{
    int n, key;
    cout << "Enter the size of the array you want: ";
    cin >> n;
    cout << endl;

    int arr[1000];

    cout << "Input the elements: ";
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i]; 
    }

    // calling the bubble sort to sort the array
    selection_sort(arr, n); // when you send array as argument, it's address is given to the function
    // this is why the value of the array elements will be changed through our function
    for (int i=0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
}