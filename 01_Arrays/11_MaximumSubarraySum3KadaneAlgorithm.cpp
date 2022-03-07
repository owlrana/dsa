// ***** KADANE's ALGORITHM REQUIRES AT LEAST ONE POSITIVE NUMBER TO WORK *****

// Kadane says that you dont need to generate all subarrays to find the max sum...
/*      Kadane solved this problem in LINEAR TIME!
        as we go along iterating each index, just add -ve value ONLY if the current sum is +ve
        (this is because -ve values added together can never create a +ve value)
 */

# include <iostream>
using namespace std;

int main() 
{   
    int n;
    cin >> n;

    int arr[1000];
    int cs = 0; // current sum, calculate only if (cs is >= 0) AND arr[i] is +ve, do not add -ves
    int ms = 0; // max sum that we have seen thus far

    for (int i =0; i<n; i ++) {
        cin >> arr[i];
    }

    // Kadane's Algorithms for maximum subarray sum
    for (int i = 0; i < n; i++) {
        cs = cs + arr[i];
        if (cs < 0) {
            cs = 0;
        }
        ms = max(cs, ms);
    }

    cout << "Maximum sum is: " << ms << endl;

    return 0;
}