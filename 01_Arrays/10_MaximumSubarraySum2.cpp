// We use mathematics to remove the 3rd loop in this algorithm
// we create an array of cumulative sum upto the specific elements, until the end of our array
// the we use this array to compute the sum between two indices i and j (substring sum)
// because of this, we do not need another loop now but it is solved using mathematics

/*
    arr   =   {1,2,3,4,-10}
    INDEX =    0 1 2 3  4
    cum_sum = {1,3,6,10,0}

    sum for substring i = 1 and j = 3 is difference of (j)th index value and (i-1)th index value :
        cum_sum[j] - cum_sum[i-1]; 
*/

// -10 1 2 3 4 -10
//   0 1 2 3 4  5
// -10-9-7-4-1 -11

# include <iostream>
#include<vector>
using namespace std;

int main() 
{   
    int n;
    cin >> n;

    int arr[1000];

    int max_sum = 0;
    int curr_sum = 0;

    int left = -50; // to find out which subarray it is
    int right = -50;

    // inintialise the cumulative sum
    vector<int> cum_sum (n, 0);

    cin >> arr[0];
    cum_sum[0] = arr[0];
    for (int i = 1;  i < n; i++) {
        cin >> arr[i];
        cum_sum[i] = cum_sum[i-1] + arr[i]; // sum of the sum until last element + this element's value
    } 

    // sanity check
    cout << "Cumulative Sum found is: " << endl;
    for (int i =0; i<n; i ++) {
        cout << cum_sum[i] << ", ";
    }
    cout << endl;

    // Generate all subarrays
    for (int i = 0; i < n; i++) { // iteration to decide the starting point of start index i
        for (int j = i; j < n; j++) { // iteration to decide the starting point of start index j
            
            curr_sum = cum_sum[j] - cum_sum[i-1];
            
            if (max_sum < curr_sum) { 
                max_sum = curr_sum;
                left = i;
                right = j;
            }
        }
    }

    cout << max_sum << endl;

    // subarray can be outputted using loop from i till j (including both)
    for (int i = left; i <= right; i ++) {
        cout << arr[i] << ", ";
    }

    return 0;
}