/*
    Very important question and has been asked in a LOT of interview problems
*/

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool canCowBePlaced(int stalls[], int n, int mid, int cows)
{
    int last_cow_placed = stalls[0];
    int count = 1;
    
    for (int i = 1; i < n; i ++)
    {
        if (stalls[i] - last_cow_placed >= mid)
        {
            last_cow_placed = stalls[i];
            count += 1;

            if (count == cows)
                return true;
        }
    }
    return false;
}

int main ()
{
    int n = 5;
    int stalls[5] = {1,2,8,4,9};
    int cows = 3;
    sort(stalls, stalls+n);

    // binary search algorithm
    int start = 0;
    int end = stalls[n-1] - stalls[0];
    int ans = 0;
    
    cout << start << endl;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        cout << "MID is: " << mid << endl; // sanity check to find out if the logic is working

        bool placeable = canCowBePlaced(stalls, n, mid, cows); // if these stalls are placeable or not
        
        if (placeable) // this is not placeable
        {
            ans = mid; // assign the new answer to this 
            cout << "ANS is set to: " << ans << endl;
            start = mid + 1; //  put the starting as the new true value (newest to the right)
            cout << "START changed: " << start << ", End: " << end << endl;
        }
        else
        {
            end = mid - 1; // now put the end as the left most False known value
            cout << "END changed: " << end << ", Start: " << start <<endl;
        }
    }
    
    cout << ans << endl;
    
    return ans;
}