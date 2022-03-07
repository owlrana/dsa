# include <iostream>
# include <climits> // this headerfile gives you the maximum range of int
// Max range is denoted as: INT_MAX
// Min range is denoted as: INT_MIN

using namespace std;

int main() {

    int n, key;
    cout << "Enter the number of elements you want in the array: ";
    cin >> n;
    cout << endl;

    int a[1000];

    cout << "Enter the array:\n";
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    cout << endl;

    // algorithm to find the largest and the smallest number
    int largest = INT_MIN; // as we need to find largest, we initialise by the smallest number that's possible
    int smallest = INT_MAX; // same, but this time the largest value as we need to find smallest number

    // traverse over the array
    for (int i=0; i < n; i ++) {
        if (a[i] > largest) {
            largest = a[i];
        }
        if (a[i] < smallest) {
            smallest = a[i];
        }
    }

    // output
    cout << "The smallest element is: " << smallest;
    cout << "\nThe largest element is: " << largest;
    cout << endl;

    // you can also use inbuilt min/max functions
    for (int i=0; i < n; i ++) {
        largest = max(largest, a[i]); // returns the maximum of the arguments given
        smallest = min(smallest, a[i]); // returns the smallest of the arguments given
    }
    // in this way, we have avoided the use of if condition
    // output
    cout << "\nThe smallest element is: " << smallest;
    cout << "\nThe largest element is: " << largest;
    cout << endl;
    
    return 0;
}