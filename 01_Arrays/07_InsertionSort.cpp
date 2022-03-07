// Insertion Sort
// Like cards, the unsorted elements keep going into their right place inside the sorted part
// of the array

# include <iostream>

using namespace std;

// Insertion Sort Function
void insertion_sort(int a[], int n) {
    
    // we assume that the first element is sorted. So starting from the 2nd element
    for (int i=1; i <= n-1; i++) {
        
        int e = a[i]; // storing the value for our element that we need to insert
        
        int j = i-1; // j should start right before i and a[j] shifts to right if it is greater to a[i]
    
        while (j >= 0 and a[j] > e) {
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = e; // insert the element into the position after where a[j] was < a[i]
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

    // calling the insertion sort to sort the array
    insertion_sort(arr, n);

    for (int i=0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
} 