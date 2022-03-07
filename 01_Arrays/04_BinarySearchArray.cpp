// Binary Search on Arrays
// works only in a sorted array!!
// also called divide and conquer technique (to break array into smaller parts and then search)
// has log(n) complexity 

# include <iostream>
using namespace std;

// binary search function
int binary_search(int a[], int n, int key) {
    int s = 0; // initialise the starting point
    int e = n-1; // initialise the ending point

    while (s <= e) {
        
        // initliase the mid point as the element to check
        int mid = (s+e) / 2;

        // if found, return
        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] > key) { // if element in mid > key, means we need to shrink the ending
            e = mid - 1;
        }
        else {                   // otherwise, it means mid < key so we now shring the starting
            s = mid + 1; 
        }
    }

    return -1; //  if the above block did not return anything, this will be excuted

}

int main ()
{
    int n, key;
    // user inputs the size of the array they want 
    cout << "Enter the size of the array you want: ";
    cin >> n;
    cout << endl;

    // assuming that the user inputs the max size (which is 1000, we assume)
    int arr[1000];

    // taking the input from the user, user can also input all values sep by space and it will work
    cout << "Input the elements: ";
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i]; 
    }

    // now asking the user what is to be searched
    cout << endl;
    cout << "Enter the Element you want to search for: ";
    cin >> key; 
    cout << endl;

    // calling the binary search function
    if (binary_search(arr, n, key) == -1) {
        cout << "The element was not found....\n";
    } else {
        cout << "The element was found at index: " << binary_search(arr, n, key) << endl;
    }

    return 0;
}