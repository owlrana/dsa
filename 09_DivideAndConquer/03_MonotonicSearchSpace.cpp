/*
        Identify the search space of your problem. If it is monotonic in nature,
        then you can come up with a Divide and Conquer algorithm instead of brute force.

        For eg, finding root (floored) of a number like in this example program
*/

# include <iostream>
using namespace std;

int square_root(int n)
{
    int s = 0;
    int e = n;
    int ans = -1; 

    while(s <= e)
    {
        int mid = (s + e) / 2;
        
        if (mid*mid == n)
        {
            return mid;
        }
        
        if (mid*mid < n)
        {
            ans = mid;
            s = mid+1;
        }
        else 
        {
            e = mid - 1;
        }
    }

    // to calculate the floating point, you will have to use brute force
        // increment each time by .1 until number is greater, then go back .1 step
            // then inc by .01 and do same
                // REPEAT UNTIL YOU REACH THE FLOATING POINT ACCURACY REQUIRED

    return ans;
}

int main ()
{
    int n;
    cin >> n;

    cout << square_root(n) << endl;

    return 0;
}