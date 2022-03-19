// https://leetcode.com/problems/single-number-iii/

# include <iostream>
# include <vector>

using namespace std;

int main ()

{
    vector<int> nums {1,1,2,2,3,3,4,4,5,5,6,7};
    int n = nums.size();

    int xxor = 0;
    for (int i = 0; i < n; i ++)
        xxor = xxor ^ nums[i];

    int temp = xxor;
    int pos = 0;
    while ((temp & 1) != 1)
    {
        temp = temp >> 1;
        pos += 1;
    } // now we know that the first set bit in xor is at position 'pos'

    int mask = (1 << pos);

    // find those numbers that contain the set bit at same position as mask
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i ++)
    {
        if ((nums[i] & mask) > 0)
            x = x^nums[i];
    }

    y = xxor ^ x;
 
    cout << min(x,y) << endl;
    cout << max(x,y) << endl;

    return 0;
}