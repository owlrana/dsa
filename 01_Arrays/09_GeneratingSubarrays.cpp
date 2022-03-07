// Give an array, we need to generate all the subarrays in it
// subarray is a continuous smaller part of an array
// Eg. {1, 2, 3} has sub arrays: {1,2}, {1,3}, {2,3}, {1}, {2}, {3} but not {1,3} !!

# include <iostream>

using namespace std;

int main() 
{   
    int n;
    cin >> n;

    int a[1000];

    for (int i =0; i<n; i ++) {
        cin >> a[i];
    }

    // Generate all subarrays
    for (int i = 0; i < n; i++) { // iteration to decide the starting point of start index i
        for (int j = i; j < n; j++) { // iteration to decide the starting point of start index j
            for(int k = i; k <= j; k++) { // prints elements of current subarray from i, to j
                cout << a[k] << ", "; // subarray's elements seperated by commas 
            }
            cout << endl; // subarrays separated by different lines
        }
    }

    return 0;
}