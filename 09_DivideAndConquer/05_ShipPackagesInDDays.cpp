// from https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>

using namespace std;

bool packageable (vector<int> &weights, int size, int d, int curr_min)
{
    int num = 1;
    int pack = 0;

    for (int i = 0; i < size; i ++)
    {   
        /*  // not required as our curr_min's Extreme left value in main function
            // is always the highest one in the array
            if (weights[i] > curr_min)
                return false;
        */

        if (weights[i] > curr_min)
            return false;
        
        if (pack + weights[i] > curr_min)
        {
            num ++;

            pack = weights[i];
            
            if (num > d)
                return false;
        }
        else
        {
            pack += weights[i];
        }
    }
    return true;
}

int main ()
{
    vector <int> weights {1,2,3,1,1}; // weight of packages
    int size = weights.size();

    int d = 4; // days limit

    // binary approach for deciding mid as min pages
    int sum = 0;
    
    for (int i = 0; i < size; i ++)
        sum += weights[i];

    int s = 0;
    int e = sum;
    int ans = INT_MAX;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (packageable(weights, size, d, mid))
        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}