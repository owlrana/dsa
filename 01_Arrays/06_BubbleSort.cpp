# include <iostream>

using namespace std;

// Bubble Sort Function
void bubble_sort(int a[], int n) {

    // n-1 large elements to the end of our array
    for (int itr=1; itr <= n-1; itr++) {
        // pairwise swapping of unsorted part of the array
        for (int j=0; j <= (n-itr-1); j++) { // j should be less than the index of elements that are sorted
            if (a[j+1] < a[j]) { // to check if the element in front is small or not
                swap(a[j], a[j+1]); // if it is small, then just swap!!
            }
        }
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
    bubble_sort(arr, n);

    for (int i=0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
}