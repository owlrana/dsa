// https://leetcode.com/problems/single-number/submissions/

/*
    This problem can also be solved by this approach but it is not very efficient:
        vector<int> nums {1,1,2,2,3,3,4,4,5};
        int ans = 0;
        for (int i = 0; i < nums.size(); i ++)
            ans = ans ^ nums[i];
        return ans;

*/

# include <iostream>
# include <vector>

using namespace std;

int main ()
{
    vector<int> nums {1,1,2,2,3,3,4,4,5,5,10};
    int size = nums.size();

    int ans = 0;
    for (int i = 0; i < size; i ++)
        ans = ans ^ nums[i]; // Running XOR operation

    cout << ans << endl; // number which was only once in the array
    return 0;
}